#include <iostream>

#include "../include/database_connection.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void connect_db() {
    std::cout << "Connected\n";
}

void disconnect_db() {
    std::cout << "Disconnected\n";
}