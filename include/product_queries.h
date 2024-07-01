#ifndef PRODUCT_QUERIES_H
#define PRODUCT_QUERIES_H

#include <iostream>
#include <string>
#include <sqlite3.h>

#include "../include/database_connection.h"

// adds a user to database
void add_product_query(std::string name, std::string release_id, std::string release_date);

// updates an existing user in database
void update_product_query(std::string name, std::string release_id, std::string release_date);

// deletes user from database
void delete_product_query(std::string name);

// displays user from database
void display_product_query();


#endif 