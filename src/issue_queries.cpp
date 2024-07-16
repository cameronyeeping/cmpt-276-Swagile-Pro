#include "../include/database_connection.h"
#include "../include/issue_queries.h"
#include "../include/macros.h"
using namespace std;

void add_change_request_query(string user_id, string product_name, string bug_release_id, string report_date, string completion_state, string severity)
{
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, ADD_CHANGE_REQUEST_QUERY, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, user_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, product_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, bug_release_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, report_date.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, completion_state.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, severity.c_str(), -1, SQLITE_STATIC);


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

void add_change_item_query(string change_id, string product_name, string future_release, string description)
{
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, ADD_CHANGE_ITEM_QUERY, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, change_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, product_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, future_release.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, description.c_str(), -1, SQLITE_STATIC);

    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
}

void update_change_item_query(string change_id, string product_name, string future_release, string description)
{
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, UPDATE_CHANGE_ITEM_QUERY, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, product_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, future_release.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, description.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, change_id.c_str(), -1, SQLITE_STATIC);

    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
}

void change_item_detail_query(string change_id) {
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, CHANGE_ITEM_DETAIL_QUERY, -1, &stmt, nullptr);

    if (exit == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, change_id.c_str(), -1, SQLITE_STATIC);

        exit = sqlite3_step(stmt);
        if (exit == SQLITE_ROW) {
            cout << sqlite3_column_text(stmt, 0) << "\t"
                 << sqlite3_column_text(stmt, 1) << "\t"
                 << sqlite3_column_text(stmt, 2) << "\t"
                 << sqlite3_column_text(stmt, 3) << endl;
        } else {
            cerr << "No row found." << endl;
        }

        sqlite3_finalize(stmt);
    } else {
        cerr << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
    }
}

void delete_change_item_query(string change_id)
{
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, DELETE_CHANGE_ITEM_QUERY, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, change_id.c_str(), -1, SQLITE_STATIC);
 
    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
}

void display_change_items_query()
{
    headers_printed = false;
    char* errMsg = nullptr;

    int exit = sqlite3_exec(db, DISPLAY_CHANGE_ITEMS_QUERY, callback, 0, &errMsg);
    if (exit != SQLITE_OK) {
        cerr << "Error executing SELECT statement: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

bool search_change_id_query(string change_id) {
    bool exists = false;
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, GET_CHANGE_ID_QUERY, -1, &stmt, nullptr);
    if(exit != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    sqlite3_bind_text(stmt, 1, change_id.c_str(), -1, SQLITE_STATIC);

    exit = sqlite3_step(stmt);
    
    if (exit == SQLITE_ROW) {
        exists = true;
    }
    return exists;
}
