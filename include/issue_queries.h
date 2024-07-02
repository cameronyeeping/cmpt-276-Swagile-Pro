/*
 * Module: Issue Queries
 * Rev. 1 2024/07/01 Original by Cameron Yee-Ping
 * ------------------------------------------------
 * This module handles all sqlite queries regarding the Issues table. 
 * It exports functions that directly query swagile_pro.db. All functions
 * in this module assume that the inputs have been checked for correctness. However, if any
 * of the functions run into an error during the query, they will throw an error that can be caught by
 * the caller.
*/

#ifndef ISSUE_QUERIES_H
#define ISSUE_QUERIES_H

#include "../include/database_connection.h"

#include <iostream>
#include <string>
#include <sqlite3.h>

/*
 * add_change_request_query() takes 6 parameters, which are used as values to create 
 * a row in the change request table. Note: the releaseID (primary key) is 
 * automatically generated
*/
void add_change_request_query(std::string userID,   // user ID of the individual that submitted the change request
                            std::string name,       // name of Product that the the change request is for
                            std::string date,       // date of report
                            std::string releaseID,  // release id of the product with the bug
                            std::string fixed_releaseID, // anticipated release ID
                            std::string completion  // completion state
                            );
//===========================================================

/*
 * update_change_request_query() creates an UPDATE TABLE query that edits a row in the change request table
*/
void update_change_request_query(
                                std::string userID,    // user ID of the individual that submitted the change request
                                std::string name, // name of Product that the the change request is for
                                std::string fixed_releaseID, // anticipated release ID
                                std::string completion // completion state
                                );
//===========================================================

/*
 * delete_change_request_query() creates a DELETE FROM query that deletes a row in the change request table based on the 
 * changeID (primary key) of the row. 
*/
void delete_change_request_query(std::string changeID   // primary key of the change request table
                                );
//===========================================================

/*
 * display_change_request_query() displays all change requests that currently exist in the table.
*/
void display_change_request_query();
//===========================================================

/*
 * add_change_item_query() creates an INSERT INTO query that adds a new row into the change item table
 * using the attributes provided as parameters.
*/
void add_change_item_query(std::string name,            // name of product the change is for
                            std::string description,    // description of the issue that needs to be changed
                            std::string release_date,   // anticipated release date
                            std::string state);         // state (known issue, in progress, complete)
//===========================================================
/*
 * update_change_item_query() creates an UPDATE TABLE query that edits a row in the change item table using 
 * the attributes provided as parameters.
*/
void update_change_item_query(std::string changeID,     // changeID (primary key) of change item we are updating
                            std::string name,           // name of product the change is for
                            std::string description,    // description of the issue that needs to be changed
                            std::string release_date,   // anticipated release date
                            std::string state);         // state (known issue, in progress, complete)

//===========================================================
/*
 * change_item_detail_query() searches the database for a row in the change item table with
 * the same changeID. Since changeID is unique, it will never return more than one row.
*/
void change_item_detail_query(std::string changeID // changeID of the change item we are looking for
                            );
//===========================================================

/*
 * delete_change_item_query() deletes the row with a matching changeID from the database.
*/
void delete_change_item_query(std::string changeID // changeID of the change item we want to delete
                            );
//===========================================================

/*
 * display_change_items_query() displays ALL of the existing change items in the change item table.
*/
void display_change_items_query();






#endif