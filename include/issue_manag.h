/*
 * Module: Issue management
 * Rev 2. - 2024-07-02 Modified by Cameron Yee-Ping
 *        - Added Documentation
 * Rev 1. - 2024-07-01 Original by Ananya Singh
 * --------------------------------------------------
 * This module contains the mid-level functions for 
 * issue management.
*/
#ifndef ISSUE_MANAG_H
#define ISSUE_MANAG_H
#include <string>

/*
 * create_change_request() polls for userID, name, date of report, releaseID, fixed_releaseID, and completion state.
 * It checks the inputs for validity, and then passes control to the issue queries module to create a new change 
 * request.
*/
void create_change_request();
//===============================

/*
 * query change item first displays all change items concisely, and then polls for user input. 
 * The user input MUST be a valid changeID. After checking for validity, it hands control to the issue 
 * queries module.
 * 
 * This function is used to display a detailed description of a specific change item
*/
void query_change_item();
//===============================

/*
 * create_change_item polls for product name, description, anticipated release date, and completion state.
 * After checking for validity, it passes control to the issue queries module to create a change item with the 
 * given inputs.
*/
void create_change_item();
//===============================

/*
 * update_change_item() first displays all change items concisely, and then polls for user input.
 * The user input MUST be a valid changeID. After checking the validity, it polls again for 
 * product name, description, anticipated release date, and completion state. It checks the validity of these new inputs, and then
 * passes control to the issue queries module to update the change item.
*/
void update_change_item();

#endif