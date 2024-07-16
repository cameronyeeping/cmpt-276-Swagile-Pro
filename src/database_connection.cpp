#include "../include/database_connection.h"

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

int connect_db() {
    int exit = sqlite3_open("swagile_pro.db", &db);
    if(exit) {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        return 1;
    }
    return 0;
}

int disconnect_db() {
    int exit = sqlite3_close(db);
    if(exit != SQLITE_OK) {
        cerr << "Error";
    }
}