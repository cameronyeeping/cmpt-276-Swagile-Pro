#ifndef ISSUE_QUERIES_H
#define ISSUE_QUERIES_H

#include "../include/database_connection.h"

#include <iostream>
#include <string>
#include <sqlite3.h>

// add change request to database
void add_change_request_query(std::string userID, std::string name, std::string releaseID, std::string fixed_date, std::string completion);

// update existing change request 
void update_change_request_query(std::string changeID);

// delete existing change request
void delete_change_request_query(std::string changeID);

// display existing change requests
void display_change_request_query();

// add change change item 
void add_change_item_query(std::string changeID, std::string name, std::string description, std::string release_date, std::string state);

// update existing change item
void update_change_item_query(std::string changeID, std::string name, std::string description, std::string release_date, std::string state);

// shows detailed information about a given change item
void change_item_detail_query(std::string changeID);

// delete an existing change item
void delete_change_item_query(std::string changeID);

// display all existing change items
void display_change_items_query();






#endif