/*
 * Module: globals
 * Revision History:
 * 2024/07/16 - Original by Cameron Yee-Ping
 * ------------------------------------------------
 * This module contains initializations of the global variables used in this application
*/
#include "../include/globals.h"

bool headers_printed = false;
sqlite3* db = nullptr;