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
void add_change_request_query(std::string change_id,   // user ID of the individual that submitted the change request
                            std::string user_id,       // name of Product that the the change request is for
                            std::string product_name,       // date of report
                            std::string bug_release_id,  // release id of the product with the bug
                            std::string report_date, // anticipated release ID
                            std::string completion_state,  // completion state
                            std::string severity           // the severity of the issue
                            );
//===========================================================

/*
 * update_change_request_query() creates an UPDATE TABLE query that edits a row in the change request table
 * this allows the user to update any number of fields expect the change_id (primary key)
*/
void update_change_request_query(
                                std::string change_id, // change id to be updated
                                std::string user_id,    // user ID of the individual that submitted the change request
                                std::string product_name, // name of Product that the the change request is for
                                std::string bug_release_id, // release ID where the bug was found
                                std::string report_date, // date the bug was reported
                                std::string completion_state, // the state of completion
                                std::string severity // the severity of the issue
                                );
//===========================================================

/*
 * delete_change_request_query() creates a DELETE FROM query that deletes a row in the change request table based on the 
 * changeID (primary key) of the row. 
*/
void delete_change_request_query(std::string change_id  // primary key of the change request table
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
void add_change_item_query(std::string change_id,        // change_id for the change item
                            std::string product_name,    // the product name for the issue
                            std::string future_release,  // anticipated release date
                            std::string description      // description of the issue that needs to be changed
                            );
//===========================================================
/*
 * update_change_item_query() creates an UPDATE TABLE query that edits a row in the change item table using 
 * the attributes provided as parameters.
*/
void update_change_item_query(std::string change_id,     // change_id (primary key) of change item we are updating
                            std::string product_name,    // name of product the change is for
                            std::string future_release,  // anticipated release date
                            std::string description     // description of the issue that needs to be changed
                        );
//===========================================================
/*
 * change_item_detail_query() searches the database for a row in the change item table with
 * the same changeID. Since changeID is unique, it will never return more than one row.
*/
void change_item_detail_query(std::string change_id // changeID of the change item we are looking for
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