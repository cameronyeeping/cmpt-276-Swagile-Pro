/*
 * Module: Issue Maintenance
 * Revision History:
 * Rev. 2 - 2024/07/02 Modified by Cameron Yee-Ping
 *          - Updated documentation
 * Rev. 1 - 2024/07/01 Original by Ananya Singh
 * ------------------------------------------------
 * This module is used to create change requests and change items. It is also used to update and display info
 * related to an existing change item in the swagile pro system. 
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

/*
 * update_change_request polls for ChangeID, product name, anticipated release date, and description.
 * After checking for validity, it passes control to the issue queries module to update a change request with the 
 * given inputs.
*/
void update_change_request();

#endif