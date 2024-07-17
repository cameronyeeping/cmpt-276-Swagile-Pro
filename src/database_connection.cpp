#include "../include/database_connection.h"
#include "../include/macros.h"
#include "../include/globals.h"

using namespace std;
int callback(void* data, int argc, char** argv, char** azColName) { 
    if (!headers_printed) {
        for (int i = 0; i < argc; i++) {
            cout << setw(20) << azColName[i]; // Adjust column width as needed
        }
        cout << endl << "===========================================================================================================\n";
        headers_printed = true;
    }

    for (int i = 0; i < argc; i++) {
        cout << setw(20) << (argv[i] ? argv[i] : "NULL");
    }
    cout << endl;
    return 0;
}

int init_db() {
    char* errmsg = nullptr;
    int exit = sqlite3_exec(db, PRAGMA_FOREIGN_KEYS, callback, 0, &errmsg);
    if (exit != SQLITE_OK) {
        cerr << "Error enabling foreign keys: " << errmsg << endl;
        return 1;
    }
    exit = sqlite3_exec(db, CREATE_USERS_TABLE, callback, 0, &errmsg);
    if (exit != SQLITE_OK) {
        cerr << "Error creating table: " << errmsg << endl;
        return 1;
    }
    exit = sqlite3_exec(db, CREATE_PRODUCT_RELEASE_TABLE, callback, 0, &errmsg);
    exit = sqlite3_exec(db, CREATE_CHANGE_REQUEST_TABLE, callback, 0, &errmsg);
    exit = sqlite3_exec(db, CREATE_CHANGE_ITEM_TABLE, callback, 0, &errmsg);
    if (exit != SQLITE_OK) {
        cerr << "Error creating table: " << errmsg << endl;
        return 1;
    }
    return 0;
}

int connect_db() {
    int exit = sqlite3_open("swagile_pro.db", &db);
    if(exit) {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        return 1;
    }
    if(init_db()) {
        return 1;
    }
    return 0;
}

int disconnect_db() {
    int exit = sqlite3_close(db);
    if(exit != SQLITE_OK) {
        cerr << "Error closing database: " << sqlite3_errmsg(db);
        return 1;
    }
    return 0;
}