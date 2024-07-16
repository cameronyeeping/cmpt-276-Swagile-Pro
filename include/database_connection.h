/*
 * Module: Database connection
 * Revision History:
 * Rev. 2 2024/07/15 Modified by Cameron Yee-Ping
 *                   - Added global db pointer
 *                   - Added global headers_printed flag
 *                   - Added callback function for SELECT queries.
 * Rev. 1 2024/07/01 Original by Cameron Yee-Ping
 * ------------------------------------------------
 * This module contains handles connection and disconnection to and from the 
 * swagile_pro.db database. It exports two functions: connect_db(), and disconnect_db().
*/

#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <sqlite3.h>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

sqlite3* db; // global pointer
bool headers_printed = false; // used for formatting output
/*
 * connect_db() calls the sqlite3 api to connect to swagile_pro.db. If 
 * the database does not exist, it creates a new one and creates all of the necessary tables.
 * If the api fails to connect to the database, it will throw an error which will be caught by the main module.
*/
void connect_db();

/*
 * disconnect_db() calls the sqlite3 api to close the connection to swagile_pro.db. If
 * the api fails to disconnect, it will throw an error that will be caught by the main module.
*/
void disconnect_db();

/*
 * callback controls output for select queries
*/
int callback(void *NotUsed, int argc, char **argv, char **azColName);

#endif