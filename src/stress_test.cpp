/**
 * Program to load 500 unique users
*/

#include "user_queries.cpp"
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
    load_data();
    return 0;
}