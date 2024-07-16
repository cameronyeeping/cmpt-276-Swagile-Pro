#include "../include/query_results.h"
#include "../include/database_connection.h"
#include "../include/macros.h"
#include "../include/report_queries.h"

using namespace std;

void display_report_1_query(const string& product) {
    // ! Fix output formatting
    char* errMsg = nullptr;
    sqlite3_stmt* stmt;

    int exit = sqlite3_prepare_v2(db, CREATE_REPORT_1, -1, &stmt, nullptr); // prepare statement for binding text
    if (exit != SQLITE_OK) {
        cerr << "Error preparing SELECT statement: " << sqlite3_errmsg(db) << endl;
        return;
    }

    exit = sqlite3_bind_text(stmt, 1, product.c_str(), -1, SQLITE_STATIC); // bind text to query

    if (exit != SQLITE_OK) {
        cerr << "Error binding parameter: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return;
    }
    cout << setw(20) << "Change ID" << setw(20) << "Completion State" << setw(20) << "Severity" << setw(40) << "Description" << endl;

    cout << endl << "===========================================================================================================\n";
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