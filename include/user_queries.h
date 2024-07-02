/*
 * Module: User Queries
 * Revision History:
 * Rev 1. 2024/07/01 Original by Cameron Yee-Ping
 * ------------------------------------------------
 * This module handles all queries involving the user table in swagile_pro.db. It
 * assumes that all inputs have been checked for correctness. If an error occurs when 
 * performing these queries, the functions will throw an error that can be caught by the caller.
*/
#ifndef USER_QUERIES_H
#define USER_QUERIES_H

#include "../include/database_connection.h"

#include <iostream>
#include <sqlite3.h>
#include <string>

/*
 * add_user_query() adds a user to the user table in swagile_pro.db with the attributes that are
 * provided as parameters using an INSERT INTO query.
*/
void add_user_query(std::string first_name,     // first name of the user
                    std::string last_name,      // last name of the user
                    std::string phone_number,   // phone number of the user
                    std::string email,          // employee of the user
                    std::string department      // department that the user works in
                    );
//===================================

/*
 * update_user_query() updates a row in the user table in swagile_pro.db with a matching userID with the attributes provided as 
 * function parameters 
*/
void update_user_query(std::string userID,      // userID (primary key)
                    std::string first_name,     // first name of the user
                    std::string last_name,      // last name of the user
                    std::string phone_number,   // phone number of the user
                    std::string email,          // employee of the user
                    std::string department      // department that the user works in
                    );
//===================================

/*
 * delete_user_query() deletes a row in the user table with a matching userID. userID is the primary 
 * key of the table, so it will never delete more than one.
*/
void delete_user_query(std::string userID);
//===================================

/*
 * display_users_query() displays all users that currently exist in the users table using a SELECT FROM query.
*/
void display_users_query();



#endif