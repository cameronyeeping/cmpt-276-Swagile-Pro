/*
 * Module: Issue Maintenance
 * Revision History:
 * Rev. 1 2024/07/01 Original by Ananya Singh
 * ------------------------------------------------
 * This module is used to create change requests and change items. It is also used to update and display info
 * related to an existing change item in the swagile pro system. 
*/

#ifndef ISSUE_MANAG_H
#define ISSUE_MANAG_H
#include <string>

// create_change_request() is used when a user wants to report an new change for an existing product
void create_change_request();
//===================================

// change_item_info() displays all the fields for a particular, exisiting change items
void change_item_info();
//===================================

// create_change_item() creates a new change item, with a new change_id in the swagile pro system
void create_change_item();
//===================================

// update_change_item updates an existing change item in the swagile pro system (e.g. updating status)
void update_change_item();
//===================================

#endif