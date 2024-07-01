#ifndef USER_QUERIES_H
#define USER_QUERIES_H

#include "../include/database_connection.h"

#include <iostream>
#include <sqlite3.h>
#include <string>

// adds a user to database
void add_user_query(std::string first_name, std::string last_name, std::string phone_number, std::string email);

// updates an existing user in database
void update_user_query(std::string userID);

// displays user from database
void display_users_query();


#endif