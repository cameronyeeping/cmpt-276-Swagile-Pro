/*
 * Module name: Main
 * Revision History:
 * Rev. 1 - 2024/07/01 Original by Cameron Yee-Ping
 * -------------------------------------------------
 * This module contains driver code for the application. It attempts to connect
 * to swagile_pro.db, and then runs the ui. When the user chooses to quit the application, it 
 * closes the connection to the database and exits cleanly.
 * 
 * Coding convention:
 * For classes, put public members first, then protected, then private.
 * 
 * Our indent size is 4 spaces.
 * 
 * Function bodies should look like this:
 * void my_func(parameters) { // we use lower case letters and underscores, curly brace on first line of function
 *     int i = 3; // indent size is 4 spaces. we also have spaces between variables and operators.
 * }
 */

#include <iostream>
#include "../include/ui.h"
#include "../include/database_connection.h"

int main() {
    if(connect_db())
        return 1;
    start_ui();

    if (disconnect_db()) 
        return 1;
    return 0;
}