#include "../include/database_connection.h"
#include "../include/product_queries.h"
#include "../include/macros.h"
#include "../include/globals.h"

using namespace std;

void add_product_release_query(string product_name, string release_id, string release_date)
{
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, ADD_PRODUCT_RELEASE_QUERY, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, product_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, release_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, release_date.c_str(), -1, SQLITE_STATIC);

    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
}

void update_product_release_query(string product_name, string release_id, string release_date, string old_product_name, string old_release_id)
{
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, UPDATE_PRODUCT_RELEASE_QUERY, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, product_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, release_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, release_date.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, old_product_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, old_release_id.c_str(), -1, SQLITE_STATIC);

    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);

}

void delete_product_release_query(string product_name)
{
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, DELETE_PRODUCT_RELEASE_QUERY, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, product_name.c_str(), -1, SQLITE_STATIC);
 
    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
}

void display_product_query()
{
    headers_printed = false;
    char* errMsg = nullptr;

    int exit = sqlite3_exec(db, DISPLAY_PRODUCT_QUERY, callback, 0, &errMsg);
    if (exit != SQLITE_OK) {
        cerr << "Error executing SELECT statement: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void display_product_release_query()
{
    headers_printed = false;
    char* errMsg = nullptr;

    int exit = sqlite3_exec(db, DISPLAY_PRODUCT_RELEASE_QUERY, callback, 0, &errMsg);
    if (exit != SQLITE_OK) {
        cerr << "Error executing SELECT statement: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

bool search_product_query(string name, string release_id) {
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, GET_PRODUCT_QUERY, -1, &stmt, nullptr);
    if (exit != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2,release_id.c_str(), -1, SQLITE_STATIC);
    exit = sqlite3_step(stmt);

    bool exists = false;
    if (exit == SQLITE_ROW) {
        exists = true;
    }

    sqlite3_finalize(stmt);
    return exists;
}