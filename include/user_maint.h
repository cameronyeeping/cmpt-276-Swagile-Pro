/*
 * Module: Product Maintenance
 * Rev 2. - 2024-07-02 Modified by Cameron Yee-Ping
 *        - Added Documentation
 *        - Added delete_user(), update_user(), display_users()
 * Rev 1. - 2024-07-01 Original by Ananya Singh
 * --------------------------------------------------
 * This module contains the mid-level functions for 
 * the management of products. 
*
*/
#ifndef USER_MAINT_H
#define USER_MAINT_H
#include <string>

// Creates a new requester in the system 
void create_user();

void delete_user();

void update_user();

void display_users();

#endif
