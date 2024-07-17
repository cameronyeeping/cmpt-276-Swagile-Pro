/*
 * Module: Globals
 * Revision History:
 * 2024/07/15 - Original by Cameron Yee-Ping
 * -----------------------------------------------
 * This module defines global variables used in the application
*/
#ifndef GLOBALS_H 
#define GLOBALS_H
#include <sqlite3.h>

// This flag is used when printing 
extern bool headers_printed;
// pointer to the sqlite database. It's used in all query functions
extern sqlite3* db;
#endif