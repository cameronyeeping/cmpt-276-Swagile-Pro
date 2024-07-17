/*
 * Module: Report Queries
 * Revision History:
 * Rev 1. 2024/07/16 Original by Dylan Dang
 * ------------------------------------------------
 * This module contains the implementations of the exported functions outlined in "report_queries.h"
*/

#include "../include/query_results.h"
#include "../include/database_connection.h"
#include "../include/macros.h"
#include "../include/report_queries.h"
#include "../include/globals.h"

// sqlite3 * db is globally defined
using namespace std;

/*
 * Report #1: : List of all change items for a particular product that are not done and not cancelled.  
 * I.e. New/Reported, or Assessed, or InProgress.
*/
void display_report_1_query(string product) {
    // ! Fix output formatting
    char* errMsg = nullptr;
    sqlite3_stmt* stmt;

    //Prepare a query statement from the given macro
    int exit = sqlite3_prepare_v2(db, CREATE_REPORT_1, -1, &stmt, nullptr); // prepare statement for binding text
    if (exit != SQLITE_OK) {
        cerr << "Error preparing SELECT statement: " << sqlite3_errmsg(db) << endl;
        return;
    }

    //Bind text to query
    exit = sqlite3_bind_text(stmt, 1, product.c_str(), -1, SQLITE_STATIC); // bind text to query

    if (exit != SQLITE_OK) {
        cerr << "Error binding parameter: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return;
    }
    cout << setw(20) << "Change ID" << setw(20) << "Completion State" << setw(20) << "Severity" << setw(40) << "Description" << endl;

    cout << endl << "===========================================================================================================\n";
    // iterate until no rows remaining
    while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) { 

        cout << setw(20) << sqlite3_column_text(stmt, 0) << setw(20)
            << sqlite3_column_text(stmt, 1) << setw(20)
            << sqlite3_column_text(stmt, 2) << setw(40)
            << sqlite3_column_text(stmt, 3) << endl;
    }

    //Execute the statement
    if (exit != SQLITE_DONE) {
        cerr << "Error executing SELECT statement: " << sqlite3_errmsg(db) << endl;
    }

    //Call destructor
    sqlite3_finalize(stmt);
}

/*
 * Report #2: List of customers/staff who need to be informed when a particular
 * change has been implemented, and in what ProductRelease ID.   
 * Select product, then select from ChangeItems for that product. 
 * To word the report, select ProductRelease from list of releases for that product.  
 * Generate report of all requester and the email addresses of Requesters for that ChangeItem.
 */
void display_report_2_query(string product, string product_release)
{
    char* errMsg = nullptr;
    sqlite3_stmt* stmt;

    //Prepare a query statement from the given macro
    int exit = sqlite3_prepare_v2(db, CREATE_REPORT_2, -1, &stmt, nullptr); // prepare statement for binding text
    if (exit != SQLITE_OK) {
        cerr << "Error preparing SELECT statement: " << sqlite3_errmsg(db) << endl;
        return;
    }

    //Bind text to query
    exit = sqlite3_bind_text(stmt, 1, product.c_str(), -1, SQLITE_STATIC); // bind text to query
    exit = sqlite3_bind_text(stmt, 2, product_release.c_str(), -1, SQLITE_STATIC);

    if (exit != SQLITE_OK) {
        cerr << "Error binding parameter: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return;
    }
    cout << setw(20) << "User ID" << setw(20) << "First Name" << setw(20) << "Last Name" << endl;

    cout << endl << "===========================================================================================================\n";
    // iterate until no rows remaining
    while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) { 

        cout << setw(20) << sqlite3_column_text(stmt, 0) << setw(20)
            << sqlite3_column_text(stmt, 1) << setw(20)
            << sqlite3_column_text(stmt, 2) << endl;
    }

    //Execute the statement
    if (exit != SQLITE_DONE) {
        cerr << "Error executing SELECT statement: " << sqlite3_errmsg(db) << endl;
    }
    //Call destructor
    sqlite3_finalize(stmt);
}
