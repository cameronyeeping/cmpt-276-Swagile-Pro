/*
 * Module: Product Maintenance
 * Rev 2. - 2024-07-02 Modified by Cameron Yee-Ping
 *        - Added Documentation
 *        - Added delete_user(), update_user(), display_users()
 * Rev 1. - 2024-07-01 Original by Ananya Singh
 * --------------------------------------------------
 * This module adds, updates, or displays users of the swagile pro system. It exports functions: create_user(), 
 * update_user(), and delete_user().
*/
#ifndef USER_MAINT_H
#define USER_MAINT_H
#include <string>

// create_user() is used to create a new requester (e.g. 'Ananya') in swagile pro
void create_user();
//===================================

// update_user() is used to update an existing user (e.g. change of phone number) in swagile pro
void update_user();
//===================================

// display_user() is used to display exisiting users in the swagile pro system with their details
void display_user();
//===================================


#endif
