/*
 * Module: Database Connection
 * Revision History: 
 * 2024/07/16 - Originial by Cameron Yee-Ping
 * ----------------------------------------------------
 * This module contains implementations of the functions defined in database_connection.h
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>

#include "../include/database_connection.h"
#include "../include/macros.h"
#include "../include/globals.h"

using namespace std;
int callback(void* data, int argc, char** argv, char** azColName) { 
    if (!headers_printed) {
        for (int i = 0; i < argc; i++) {
            cout << setw(30) << azColName[i]; // Adjust column width as needed
        }
        cout << endl << "===================================================================================================================================================="
        << "================================\n";
        headers_printed = true;
    }

    for (int i = 0; i < argc; i++) {
        cout << setw(30) << (argv[i] ? argv[i] : "NULL");
    }
    cout << endl;
    return 0;
}

int create_backup(string directory) {
    auto t = time(nullptr);
    auto tm = *localtime(&t);
    sqlite3* new_db = nullptr;
    sqlite3_backup* backup = nullptr;

    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d");
    auto str = oss.str();
    string db_name = "swagile_pro_backup_";

    db_name.append(str); 
    db_name.append(".db"); // s is the new database
    
    int exit = sqlite3_open(db_name.c_str(), &new_db);
    if (exit != SQLITE_OK) {
        cerr << "Cannot open database:" << sqlite3_errmsg(new_db) << endl;
        sqlite3_close(new_db);
        return -1;
    }

    backup = sqlite3_backup_init(new_db, "main", db, "main");
    if (!backup) {
        cerr << "Failed to initiate backup: " << sqlite3_errmsg(new_db) << endl;
        sqlite3_close(new_db);
        return -1;
    }

    exit = sqlite3_backup_step(backup, -1);
    if(exit != SQLITE_DONE) {
        cerr << "Error during backup: " << sqlite3_errmsg(new_db) << endl;
        sqlite3_close(new_db);
        return -1;
    }
    
    sqlite3_backup_finish(backup);
    if(exit == SQLITE_DONE) {
        cout << "Backup created successfully\n";
        exit = 0;
    }
    else {
        cerr << "Error during backup: " << sqlite3_errmsg(new_db) << endl;
        exit = -1;
    }
    sqlite3_close(new_db);
    return exit;
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