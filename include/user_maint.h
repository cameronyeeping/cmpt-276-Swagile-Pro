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

/*
 * create_user() prompts for name, phone number, email, and optionally department. If department is left blank,
 * it means that the user is external. After checking the input for validity, it creates a user with the corresponding
 * attributes.
*/
void create_user();
//===================================

/*
 * update_user() displays all users, and then prompts for a userID. After checking the userID, it prompts again for 
 * name, phone number, email, and department. These inputs are used to update the corresponding user.
*/
void update_user();
//===================================

/*
 * display_users() displays all users in the database.
*/
void display_users();

#endif
