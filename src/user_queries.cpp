/*
 * Module: User Queries
 * Revision History:
 * Rev 1. 2024/07/01 Original by Cameron Yee-Ping
 * ------------------------------------------------
 * This module contains the implementations of the exported functions outlined in "user_queries.h"
*/

#include "../include/database_connection.h"
#include "../include/user_queries.h"
#include "../include/macros.h"
// sqlite3 * db is globally defined
using namespace std;

/*
 * add_user_query() adds a user to the user table in swagile_pro.db with the attributes that are
 * provided as parameters using an INSERT INTO query.
*/
void add_user_query(string first_name, string last_name, string phone_number, string email, string department) { 
    sqlite3_stmt* stmt;

    //Prepare a query statement from the given macro
    int exit = sqlite3_prepare_v2(db, ADD_USER_QUERY, -1, &stmt, nullptr);

    //Bind text to query
    sqlite3_bind_text(stmt, 1, first_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, last_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, phone_number.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, department.c_str(), -1, SQLITE_STATIC);

    //Execute the statement
    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    //Call destructor
    sqlite3_finalize(stmt);
}

/*
 * update_user_query() updates a row in the user table in swagile_pro.db with a matching userID with the attributes provided as 
 * function parameters 
*/
void update_user_query(string userID, string first_name, string last_name, string phone_number, string email, string department) { 
    sqlite3_stmt* stmt;

    //Prepare a query statement from the given macro
    int exit = sqlite3_prepare_v2(db, UPDATE_USER_QUERY, -1, &stmt, nullptr);
    
    //Bind text to query
    sqlite3_bind_text(stmt, 1, first_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, last_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, phone_number.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, department.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, userID.c_str(), -1, SQLITE_STATIC);

    //Execute the statement
    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    //Call destructor
    sqlite3_finalize(stmt);
}

/*
 * display_users_query() displays all users that currently exist in the users table using a SELECT FROM query.
*/
void display_users_query() {
    headers_printed = false;
    char* errMsg = nullptr;

    //Binding text not required
    //Execute the statement
    int exit = sqlite3_exec(db, DISPLAY_USERS_QUERY, callback, 0, &errMsg);
    if (exit != SQLITE_OK) {
        cerr << "Error executing SELECT statement: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

/*
 * delete_user_query() deletes a row in the user table with a matching userID. userID is the primary 
 * key of the table, so it will never delete more than one.
*/
void delete_user_query(string userID) {
    sqlite3_stmt* stmt;
    //Prepare a query statement from the given macro
    int exit = sqlite3_prepare_v2(db, DELETE_USER_QUERY, -1, &stmt, nullptr);

    //Bind text to query
    sqlite3_bind_text(stmt, 1, userID.c_str(), -1, SQLITE_STATIC);
 
    //Execute the statement
    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    //Call destructor
    sqlite3_finalize(stmt);   
}

/*
 * constructs a query to search of a user by their first and last name, and returns it in a query results object
*/
Query_Results search_user_query(string first, string last) {
    Query_Results result;
    sqlite3_stmt* stmt;

    //Prepare a query statement from the given macro
    int exit= sqlite3_prepare_v2(db, SEARCH_USER_QUERY, -1, &stmt, nullptr);
    if (exit!= SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
        return result;
    }

    //Bind text to query
    sqlite3_bind_text(stmt, 1, first.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, last.c_str(), -1, SQLITE_STATIC);

    //Fetch the results and store them in the Query_Results object
    vector<string> data;
    int num_rows = 0;
    int num_cols = sqlite3_column_count(stmt);

    //Fetch each row of the result set
    while ((exit= sqlite3_step(stmt)) == SQLITE_ROW) {
        ++num_rows;
        for (int col = 0; col < num_cols; ++col) {
            const char* text = reinterpret_cast<const char*>(sqlite3_column_text(stmt, col));
            data.push_back(text ? text : "NULL");
        }
    }

    if (exit != SQLITE_DONE && exit != SQLITE_ROW) {
        cerr << "Execution finished with an error: " << sqlite3_errmsg(db) << std::endl;
    }

    //Call destructor
    sqlite3_finalize(stmt);
    result = Query_Results(data, num_rows, num_cols);

    return result;
}

/*
 * Takes a user_id and checks if the user exists in the table, returns a bool
*/
bool search_user_id_query(string user_id) {
    sqlite3_stmt* stmt;

    //Prepare a query statement from the given macro
    int exit = sqlite3_prepare_v2(db, GET_USER_ID_QUERY, -1, &stmt, nullptr);
    if (exit != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    //Bind text to query
    sqlite3_bind_text(stmt, 1, user_id.c_str(), -1, SQLITE_STATIC);
    exit = sqlite3_step(stmt);

    //Check if result is not empty
    bool exists = false;
    if (exit == SQLITE_ROW) {
        exists = true;
    }

    //Call destructor
    sqlite3_finalize(stmt);
    return exists;
}