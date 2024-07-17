/*
 * Module: Product Queries
 * Revision History:
 * Rev 1. 2024/07/16 Original by Dylan Dang
 * ------------------------------------------------
 * This module contains all queries involving the product table in swagile_pro.db
 * The functions in this module assume that all function parameters have been checked for correctness.
 * However, if an error occurs in any of these functions, they throw an error that can be caught by the caller.
 * 
 * This module hides the representation of products vs their releases. They are actually stored in the same table. 
 * When the caller calls a product function vs a product release function, they access the same table. The only difference is 
 * how their output is formatted.
*/

#include "../include/database_connection.h"
#include "../include/product_queries.h"
#include "../include/macros.h"
#include "../include/globals.h"

using namespace std;

/*
 * add_product_release_query() creates an INSERT INTO query that adds a row into the product table in swagile_pro.db 
 * using the parameters provided.
*/
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

/*
 * update_product_query() creates an UPDATE TABLE query that changes a product's attributes 
 * to the ones provided as parameters.
*/
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

/*
 * delete_product_query() deletes a given product from the product table using a DELETE FROM query.
*/
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

/*
 * display_product_query() displays all products in the table using a SELECT FROM query.
*/
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

/*
 * this function displays all product releases in the database. It is a slightly different query than 
 * display_product_query().
*/
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

/*
 * Search function to search whether the query has specific product name and product release ID
*/
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