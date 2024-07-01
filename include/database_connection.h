#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <sqlite3.h>


// allows us to get an output from the Select operation
static int callback(void* data, int argc, char** argv, char** azColName);

// opens connection user to swagile_pro.db
void connect_db();

// closes connection to swagile_pro.db
void disconnect_db();


#endif