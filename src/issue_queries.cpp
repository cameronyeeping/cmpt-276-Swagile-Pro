#include "../include/database_connection.h"
#include "../include/issue_queries.h"
#include "../include/macros.h"
using namespace std;

void add_change_request_query(string change_id, string user_id, string product_name, string bug_release_id, string report_date, string completion_state, string severity)
{
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, ADD_CHANGE_REQUEST_QUERY, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, change_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, user_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, product_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, bug_release_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, report_date.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, completion_state.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, severity.c_str(), -1, SQLITE_STATIC);


    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
}