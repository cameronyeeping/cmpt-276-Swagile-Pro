/*
 * Module: testFileOps
 * Revision History: 
 * Rev 1. - 2024/07/16 Original by Cameron Yee-Ping
 * ----------------------------------------------------
 * This module tests file operations with multiple functions in the User Queries module 
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

// low level module, write one at a time to NOT PRODUCT 
// struct or class with 2 or more data members to write
// also read them back one at a time, compare

// testFileOps.cpp
// one other function to test

typedef struct {
    string first_name;
    string last_name;
    string phone_number;
    string email;
    string department;
} user_data;

typedef struct {
    string user_id;
    string product_name;
    string bug_release_id;
    string report_date;
    string completion_state;
    string severity;
} change_request_data;
int main() {
    if(connect_db())
        return 1;
    user_data users[2] = {
        {"Lebron", "James", "123-456-7890", "lebronjamesthegoat@gmail.com", "Engineering"},
        {"Stephen", "Curry", "098-765-4321", "stephcurrysplash@gmail.com", "Marketing"}
    };
    // Test case 1: Read/Write 
    for(int i = 0; i < 2; i++)
        add_user_query(users[i].first_name, users[i].last_name, users[i].phone_number,  users[i].email, users[i].department);
    Query_Results r1 = search_user_query(users[0].first_name, users[0].last_name);
    Query_Results r2 = search_user_query(users[1].first_name, users[1].last_name);
    int success = 0;
    
    success += strncmp((users[0].first_name).c_str(), r1.getData()[1].c_str(), strlen(users[0].first_name.c_str()));
    success += strncmp((users[0].last_name).c_str(), r1.getData()[2].c_str(),strlen(users[0].last_name.c_str()));
    success += strncmp((users[0].phone_number).c_str(), r1.getData()[3].c_str(),strlen(users[0].phone_number.c_str()));
    success += strncmp((users[0].email).c_str(), r1.getData()[4].c_str(), strlen(users[0].email.c_str()));
    success += strncmp((users[0].department).c_str(), r1.getData()[5].c_str(), strlen(users[0].department.c_str()));
    
    success += strcmp((users[1].first_name).c_str(), r2.getData()[1].c_str());
    success += strcmp((users[1].last_name).c_str(), r2.getData()[2].c_str());
    success += strcmp((users[1].phone_number).c_str(), r2.getData()[3].c_str());
    success += strcmp((users[1].email).c_str(), r2.getData()[4].c_str());
    success += strcmp((users[1].department).c_str(), r2.getData()[5].c_str());
    
    std::cout << "Read/Write Users test: ";
    if (success != 0) 
        std::cout << "[FAILED]\n";
    else
        std::cout << "[SUCCESS]\n";

    // test case 2: Deleting a user 
    delete_user_query(r1.getData()[0]);
    delete_user_query(r2.getData()[0]);
    std::cout << "Delete User test: ";
    if (search_user_id_query(r1.getData()[0]) || search_user_id_query(r2.getData()[0]))
        std::cout << "[FAILED]\n";
    else
        std::cout << "[SUCCESS]\n";


    if (disconnect_db()) 
        return 1;
    return 0;
}