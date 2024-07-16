#include "../include/database_connection.h"
#include "../include/user_queries.h"
#include "../include/macros.h"
using namespace std;

void add_product_release_query(string product_name, string release_id, string release_date)
{
    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, ADD_PRODUCT_RELEASE_QUERY, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, product_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, release_id.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, release_date.c_str(), -1, SQLITE_STATIC);
}