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


#include "../include/create_report.h"
#include "../include/database_connection.h"
#include "../include/issue_manag.h"
#include "../include/issue_queries.h"
#include "../include/product_maint.h"
#include "../include/product_queries.h"
#include "../include/report_queries.h"
#include "../include/query_results.h"
#include "../include/user_maint.h"
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
    Query_Results results;

    /*
     * Performance test: Pass if displaying a type 1 report succeeds in under 110 ms.
    */
    vector<vector<string>> report_data = {
        {"1", "Crashes when files are missing", "3.3.9", "In Progress", "Severe"},
        {"2", "Freezes on startup", "3.4.0", "In Progress", "Low"},
        {"3", "Lagging under load", "3.4.0", "In Progress", "Low"},
        {"4", "Logs user out on shutdown", "3.4.1", "In Progress", "Low"},
        {"5", "Visual artifacts in menu", "3.4.1", "In Progress", "Moderate"},
        {"6", "Displayed time out of sync with system", "3.4.1", "In Progress", "Moderate"},
        {"7", "Wifi frequently disconnects", "3.4.2", "Known Issue", "Moderate"},
        {"8", "Bluetooth frequently disconnects", "3.4.2", "Known Issue", "Moderate"},
        {"9", "Cursor invisible", "3.4.2", "Known Issue", "Severe"},
        {"10", "Keyboard skipping inputs", "3.4.2", "Known Issue", "Severe"}
    }; 
    add_product_release_query("WizBang", "3.3.9", "2024-06-01");
    add_product_release_query("WizBang", "3.4.0", "2024-06-01");
    add_product_release_query("WizBang", "3.4.1", "2024-06-01");
    for(int i = 0; i < 10; i++) {
        add_change_item_query("WizBang", report_data[1][i], "2024-06-01", report_data[3][i], report_data[4][i]);
    }
    auto duration = measureRuntime([&]() {display_report_1_query("WizBang");});
    cout << "Performance Test: ";
    if(duration.count() < 110.0)
        cout << "[PASS]\n";
    else 
        cout << "[FAIL]\n";

    // Clean up steps
    delete_product_release_query("Wizbang");
    
    /*
     * Functional test case
     * Add a user to database
    */
    add_user_query("Lebron", "James", "604-123-1234", "lebronjamesthegoat@gmail.com", "Engineer");
    results = search_user_query("Lebron", "James");
    string s1 = results.getData()[1];
    string s2 = results.getData()[2];
    cout << "Functional Test: ";
    if(strcmp(s1.c_str(), "Lebron") && strcmp(s2.c_str(), "James"))
        cout << "[PASS]\n";
    else 
        cout << "[FAIL]\n";
    delete_user_query(results.getData()[0]); // delete user we added by userID
    return 0;
}