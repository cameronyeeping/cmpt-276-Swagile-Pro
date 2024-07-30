/**
 * Program to load 500 unique users
*/

#include "../include/user_queries.h"
#include "../include/database_connection.h"
#include <string>

void load_data()
{
    for(int i = 0; i <= 500; i++)
    {
        int user_id = i;
        string user_first_name = "name" + to_string(user_id);
        add_user_query(user_first_name, "last", "1231231234", "example@example.com", "department");
    }
}

int main() 
{
    connect_db();
    load_data();
    display_users_query();
    disconnect_db();
    return 0;
}