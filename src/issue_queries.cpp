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

void update_change_request_query(string change_id, string user_id, string product_name, string bug_release_id,  string report_date,  string completion_state,  string severity)
{
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, UPDATE_CHANGE_REQUEST_QUERY, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, user_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, product_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, bug_release_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, report_date.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, completion_state.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, severity.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, change_id.c_str(), -1, SQLITE_STATIC);

    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
}

void display_change_request_query()
{
    headers_printed = false;
    char* errMsg = nullptr;

    int exit = sqlite3_exec(db, DISPLAY_CHANGE_REQUEST_QUERY, callback, 0, &errMsg);
    if (exit != SQLITE_OK) {
        cerr << "Error executing SELECT statement: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}
