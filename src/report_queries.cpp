#include "../include/query_results.h"
#include "../include/database_connection.h"
#include "../include/macros.h"
#include "../include/report_queries.h"

using namespace std;

void display_report_1_query(string product) {
    headers_printed = false;
    char* errMsg = nullptr;
    sqlite3_stmt* stmt;

    int exit = sqlite3_prepare_v2(db, UPDATE_USER_QUERY, -1, &stmt, nullptr);
    
    sqlite3_bind_text(stmt, 1, product.c_str(), -1, SQLITE_STATIC);
    exit = sqlite3_step(stmt);

    if (exit != SQLITE_OK) {
        cerr << "Error executing SELECT statement: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}