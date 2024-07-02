/*
 * Module: UI
 * Revision History:
 * Rev. 1 2024/07/01 Original by Cameron Yee-Ping
 * -------------------------------------------------
 * This module handles most of the interaction with the user. 
 * It is used as an event initiator, which calls exported functions from the 
 * mid-level modules. 
*/

#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>


/*
 * start_ui() is the only exported function in the module. It contains a do-while 
 * loop with a switch case inside. The input provided by the user navigates to other
 * sub-menus.
*/
void start_ui();
//===================================

/*
 * display_main_menu() displays the main menu, and then polls for user input.
 * The input is returned and used in the switch case inside of start_ui()
*/
static int display_main_menu();
//===================================

/*
 * user_menu() is a sub-menu for user maintenance. It polls for user input, then
 * calls the respective function from the user maintenance module to finish the task.
*/
static void user_menu();
//===================================

/*
 * product_menu() is a sub-menu for product maintenance. It polls for user input, then
 * calls the respective function from the product maintenance module to finish the task.
*/
static void product_menu();  
//===================================

/*
 * issue_menu() is a sub-menu for issue management. From this menu, the user can either 
 * create a change request or navigate to the change item maintenance menu. If the user selects
 * to create a change request, it passes control to the Issue Maintenance module.
*/
static void issue_menu();  
//====================================

/*
 * change_item_maintenance_menu() is a sub-sub-menu of issue management. It polls for user input, then 
 * calls the respective function from the issue management module to complete the task.
*/
static void change_item_maintenance_menu(); //! sub-menu of change_item_maintenance
//====================================

/*
 * create_report_menu() is a sub-menu for creating a report. The user can choose to create two kinds of reports.
 * After the user chooses which report to create, it passes control to the create report module.
*/
static void create_report_menu();

#endif