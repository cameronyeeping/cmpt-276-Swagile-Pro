/*
 * Module: Report Queries
 * Revision History: 
 * 2024/07/15 - Original by Cameron Yee-Ping
 * -----------------------------------------------
 * This module contains implementations of the functions defined in
 * reqport_queries.h
*/

#include "../include/query_results.h"
#include "../include/database_connection.h"
#include "../include/macros.h"
#include "../include/report_queries.h"
#include "../include/globals.h"


using namespace std;

void display_report_1_query(string product) {
    char* errMsg = nullptr;
    sqlite3_stmt* stmt;
    // prepare statement with CREATE_REPORT macro
    int exit = sqlite3_prepare_v2(db, CREATE_REPORT_1, -1, &stmt, nullptr); // prepare statement for binding text
    if (exit != SQLITE_OK) {
        cerr << "Error preparing SELECT statement: " << sqlite3_errmsg(db) << endl;
        return;
    }
    // bind parameter to statement
    exit = sqlite3_bind_text(stmt, 1, product.c_str(), -1, SQLITE_STATIC); // bind text to query

    if (exit != SQLITE_OK) {
        cerr << "Error binding parameter: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return;
    }
    // output column names
    cout << setw(20) << "Change ID" << setw(20) << "Completion State" << setw(20) << "Severity" << setw(40) << "Description" << endl;

    cout << endl << "===========================================================================================================\n";
    // iterate through all rows produced by result, read them, and write them to console
    while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) { // iterate until no rows remaining

        cout << setw(20) << sqlite3_column_text(stmt, 0) << setw(20)
            << sqlite3_column_text(stmt, 1) << setw(20)
            << sqlite3_column_text(stmt, 2) << setw(40)
            << sqlite3_column_text(stmt, 3) << endl;
    }

    if (exit != SQLITE_DONE) {
        cerr << "Error executing SELECT statement: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt);
}

void display_report_2_query(string product, string product_release)
{
    char* errMsg = nullptr;
    sqlite3_stmt* stmt;
    
    // prepare statement with given macro
    int exit = sqlite3_prepare_v2(db, CREATE_REPORT_2, -1, &stmt, nullptr); // prepare statement for binding text
    if (exit != SQLITE_OK) {
        cerr << "Error preparing SELECT statement: " << sqlite3_errmsg(db) << endl;
        return;
    }
    // bind text to statement
    exit = sqlite3_bind_text(stmt, 1, product.c_str(), -1, SQLITE_STATIC); // bind text to query
    exit = sqlite3_bind_text(stmt, 2, product_release.c_str(), -1, SQLITE_STATIC);

    if (exit != SQLITE_OK) {
        cerr << "Error binding parameter: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return;
    }
    cout << setw(20) << "User ID" << setw(20) << "First Name" << setw(20) << "Last Name" << endl;

    cout << endl << "===========================================================================================================\n";
    // get output and write to console
    while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) { // iterate until no rows remaining

        cout << setw(20) << sqlite3_column_text(stmt, 0) << setw(20)
            << sqlite3_column_text(stmt, 1) << setw(20)
            << sqlite3_column_text(stmt, 2) << endl;
    }

    if (exit != SQLITE_DONE) {
        cerr << "Error executing SELECT statement: " << sqlite3_errmsg(db) << endl;
    }
    // destructor
    sqlite3_finalize(stmt);
}
