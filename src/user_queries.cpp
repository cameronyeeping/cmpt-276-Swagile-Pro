#include "../include/database_connection.h"
#include "../include/user_queries.h"
#include "../include/macros.h"
// sqlite3 * db is globally defined
using namespace std;

void add_user_query(string first_name, string last_name, string phone_number, string email, string department) { 
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, ADD_USER_QUERY, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, first_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, last_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, phone_number.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, department.c_str(), -1, SQLITE_STATIC);

    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
}
void update_user_query(string userID, string first_name, string last_name, string phone_number, string email, string department) { 
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, UPDATE_USER_QUERY, -1, &stmt, nullptr);
    
    sqlite3_bind_text(stmt, 1, first_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, last_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, phone_number.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, department.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, userID.c_str(), -1, SQLITE_STATIC);

    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
}
void display_users_query() {
    headers_printed = false;
    char* errMsg = nullptr;

    int exit = sqlite3_exec(db, DISPLAY_USERS_QUERY, callback, 0, &errMsg);
    if (exit != SQLITE_OK) {
        cerr << "Error executing SELECT statement: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void delete_user_query(string userID) {
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, DELETE_USER_QUERY, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, userID.c_str(), -1, SQLITE_STATIC);
 
    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);   

}

Query_Results search_user_query(string first, string last) {
    Query_Results result;

    // SQL query to search for users by first and last names

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, SEARCH_USER_QUERY, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
        return result;
    }

    // Bind the parameters
    sqlite3_bind_text(stmt, 1, first.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, last.c_str(), -1, SQLITE_STATIC);

    // Fetch the results and store them in the Query_Results object
    vector<string> data;
    int num_rows = 0;
    int num_cols = sqlite3_column_count(stmt);

    // Fetch each row of the result set
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        ++num_rows;
        for (int col = 0; col < num_cols; ++col) {
            const char* text = reinterpret_cast<const char*>(sqlite3_column_text(stmt, col));
            data.push_back(text ? text : "NULL");
        }
    }

    if (rc != SQLITE_DONE && rc != SQLITE_ROW) {
        std::cerr << "Execution finished with an error: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    result = Query_Results(data, num_rows, num_cols);

    return result;
}

// ! UNTESTED
bool search_user_id_query(string user_id) {
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, GET_USER_ID_QUERY, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    sqlite3_bind_text(stmt, 1, user_id.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);

    bool exists = false;
    if (rc == SQLITE_ROW) {
        exists = sqlite3_column_int(stmt, 0) > 0;
    }

    sqlite3_finalize(stmt);
    return exists;
}