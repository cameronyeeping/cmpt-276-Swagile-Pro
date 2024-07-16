#include "../include/database_connection.h"

using namespace std;
int callback(void* data, int argc, char** argv, char** azColName) { 
    static bool headersPrinted = false;  // To print headers only once

    if (!headersPrinted) {
        for (int i = 0; i < argc; i++) {
            cout << setw(20) << azColName[i]; // Adjust column width as needed
        }
        cout << endl << "===========================================================================================================\n";
        headersPrinted = true;
    }

    for (int i = 0; i < argc; i++) {
        cout << setw(20) << (argv[i] ? argv[i] : "NULL");
    }
    cout << endl;
    return 0;
}

void connect_db() {
    cout << "Connected\n";
}

void disconnect_db() {
    cout << "Disconnected\n";
}