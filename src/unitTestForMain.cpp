/*
 * Module: Unit Test for Main
 * Revision History: 
 * Rev 1. - 2024/07/02 Original by Cameron Yee-Ping
 * This module performs a performance test on create_report_1_query(), 
 * as well as a functional test on add_user_query()
*/
#include <iostream>
#include <string>
#include <vector>


#include "../include/database_connection.h"
#include "../include/issue_queries.h"
#include "../include/product_queries.h"
#include "../include/report_queries.h"
#include "../include/query_results.h"
#include "../include/user_queries.h"

using namespace std;

/*
 * function that measures runtime of another function
*/
template <typename F>
chrono::milliseconds measureRuntime(F&& func) {
    auto start = chrono::high_resolution_clock::now();

    // Execute the provided function
    func();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    return duration;
}


int main() {
    if(connect_db())
        return 1;
    cout << "Connected\n";
    if (disconnect_db()) 
        return 1;
    return 0;
}