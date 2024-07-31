/*
Module: Issue Manag
* Rev 3. - 2024-07-30 Modified by Dylan Dang
         - Fixed create_change_item
         - Fixed invalid trial bugs
* Rev 2. - 2024-07-29 Modified by Dylan Dang
         - Fixed 5 wrong attempt loop
* Rev 1. - 2024-07-15 Original by Dylan Dang
--------------------------------------------------
This module contains the implementations of the exported functions outlined in "issue_manag.h"
*/

#include <iostream>
#include <string>
#include "../include/issue_manag.h"
#include "../include/issue_queries.h"
#include "../include/user_queries.h"
#include "../include/product_queries.h"
using namespace std;


/*
create_change_request() polls for user_ID, name, date, bug_release_id, completion state and severity.
It checks the inputs for validity, and then passes control to the issue queries module to create a new change
request.
*/

void create_change_request() {
    string user_id;
    string name; 
    string date;
    string bug_release_id;  
    string completion = "Acknowledged";  
    string severity;

    cin.ignore(10000, '\n');
    //User has 5 attempts to provide valid input, bring to main menu after 5
    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the UserID of the User:\n";
        getline(cin, user_id);
        if (search_user_id_query(user_id) == true) { 
            break;
        } else {
            cout << "Enter a valid UserID!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the Product Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        getline(cin, name);

        cout << "Please Enter the Product ReleaseID:\n";
        cout << "Format: #.#.# \n";
        getline(cin, bug_release_id);

        if (search_product_query(name, bug_release_id) == true) {
            break;
        } else {
            cout << "Enter valid product name and releaseID!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        string month_str;
        string day_str;

        int month_int;
        int day_int;

        cout << "Please Enter the Current Date:\n";
        cout << "Required Format: YYYY-MM-DD\n";
        getline(cin, date);

        if (date.length() == 10 && date[4] == '-' && date[7] == '-' ) {
            month_str = date.substr(5,6);
            day_str = date.substr(8,9);

            month_int = stoi(month_str);
            day_int = stoi(day_str);

            if (month_int < 1 || month_int > 12 || day_int < 1 || day_int > 31) {
                cout << "Current date must be in correct format!\n";
            } else {
                break;
            }
        } else {
            cout << "Current date must be in correct format!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the Severity Level of the Issue:\n";
        cout << "Required Format: Number between 1-4\n";
        getline(cin, severity);
        if (severity.length() == 1 && severity[0] <= '4' && severity[0] >= '1') {
            break;
        } else {
            cout << "Severity Level must be in correct format!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    string confirm_input;

    cout << "UserID: " << user_id << "\n";
    cout << "Product Name: " << name << "\n";
    cout << "Current Date: " << date << "\n";
    cout << "ReleaseID: " << bug_release_id << "\n";
    cout << "Severity Level: " << severity << "\n";
    cout << "Do you want to add this change request? (Y/N)\n";
    getline(cin, confirm_input);

    if (confirm_input == "Y" || confirm_input == "y"){
        add_change_request_query(user_id, 
                                 name,       
                                 bug_release_id, 
                                 date,
                                 completion,
                                 severity 
                                );
        cout << "You have successfully created a new change request!\n";
        cout << "The newly added change request is the bottom most item in the table:\n";
        display_change_request_query();
        cout << "You have been re-directed to the Main Menu!\n";
    } else {
        cout << "Action has been aborted.\n";
        cout << "You have been re-directed to the Main Menu!\n";
    }

    return;
}

/*
query change item first displays all change items concisely, and then polls for user input. 
The user input MUST be a valid changeID. After checking for validity, it hands control to the issue
queries module.
This function is used to display a detailed description of a specific change item
*/
void query_change_item() {
    string change_id;

    display_change_items_query();
    cin.ignore(10000, '\n');
    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the ChangeID of a change item:\n";
        
        getline(cin, change_id);
        if (search_change_id_query(change_id) == true) { 
            break;
        } else {
            cout << "Enter a valid ChangeID!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    change_item_detail_query(change_id);
    return;
}

/*
create_change_item polls for change_id, product_name and anticipated release date.
After checking for validity, it passes control to the issue queries module to create a change item with the
given inputs.
*/
void create_change_item() {
    string change_id; 
    string product_name;
    string anticipated_release_id; 
    string description;
    
    cin.ignore(10000, '\n');
    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the ChangeID of a Change Request:\n";
        getline(cin, change_id);
        //cout << change_id << endl;

        if (search_change_id_query(change_id) == true) { 
            break;
        } else {
            cout << "Enter a valid ChangeID!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }
    
    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the Product Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        getline(cin, product_name);
        if (product_name.length() <= 30) {
            break;
        }
        else {
            cout << "Product name must be 30 characters or less!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }
    
    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the Product ReleaseID:\n";
        cout << "Format: #.#.# \n";
        getline(cin, anticipated_release_id);

        if (anticipated_release_id.length() <= 30) {
            break;
        } else {
            cout << "Enter valid product name and releaseID!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the Description of the Issue:\n";
        cout << "Maximum Length: 1000 Characters \n";
        getline(cin, description); 
        if (description.length() <= 10000) {

            break;
        }
        else {
            cout << "Description must be 1000 characters or less!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

        string confirm_input;

        cout << "ChangeID: " << change_id << "\n";
        cout << "Product Name: " << product_name << "\n";
        cout << "Anticipated Release ID: " << anticipated_release_id << "\n";
        cout << "Description: " << description << "\n";
        cout << "Do you want to add this change item? (Y/N)\n";
        getline(cin, confirm_input);

    if (confirm_input == "Y" || confirm_input == "y"){
        add_change_item_query(change_id,     
                              product_name,   
                              anticipated_release_id,  
                              description      
                             );
        cout << "You have successfully created a new change item!\n";
        cout << "The newly added change request is the bottom most item in the table:\n";
        display_change_items_query();
        cout << "You have been re-directed to the Main Menu!\n";
    } else {
        cout << "Action has been aborted.\n";
        cout << "You have been re-directed to the Main Menu!\n";
    }
    return;
}

/*
 * update_change_request polls for ChangeID, product name, anticipated release date, and description.
 * After checking for validity, it passes control to the issue queries module to update a change request with the 
 * given inputs.
*/
void update_change_request() {
    string change_id;
    string user_id;
    string product_name;
    string bug_release_id;
    string report_date;
    string completion_state;
    string severity;

    cin.ignore(10000, '\n');
    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the ChangeID of a change item:\n";
        
        getline(cin, change_id);
        if (search_change_id_query(change_id) == true) { 
            break;
        } else {
            cout << "Enter a valid ChangeID!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the UserID of the user who submitted the change request:\n";
        getline(cin, user_id);
        if (search_user_id_query(user_id) == true) { 
            break;
        } else {
            cout << "Enter a valid UserID!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the New Product Name :\n";
        cout << "Maximum Length: 30 Characters \n";
        getline(cin, product_name);
        if (product_name.length() <= 30) {
            break;
        }
        else {
            cout << "Product name must be 30 characters or less!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the Product ReleaseID of Where the Bug was Found:\n";
        cout << "Format: #.#.# \n";
        getline(cin, bug_release_id);

        if (bug_release_id.length() <= 30) {
            break;
        } else {
            cout << "Enter valid product name and releaseID!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        string month_str;
        string day_str;

        int month_int;
        int day_int;

        cout << "Please Enter the Date that the Issue was Reported:\n";
        cout << "Required Format: YYYY-MM-DD\n";
        getline(cin, report_date);

        if (report_date.length() == 10 && report_date[4] == '-' && report_date[7] == '-' ) {
            month_str = report_date.substr(5,6);
            day_str = report_date.substr(8,9);

            month_int = stoi(month_str);
            day_int = stoi(day_str);

            if (month_int < 1 || month_int > 12 || day_int < 1 || day_int > 31) {
                cout << "Current date must be in correct format!\n";
            } else {
                break;
            }
        } else {
            cout << "Current date must be in correct format!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Choose the Completion State of the Change Item:\n";
        cout << "Required Format: Number between 1-4\n";
        cout << "1) Acknowledged\n";
        cout << "2) In Progress\n";
        cout << "3) Completed\n";
        cout << "4) Cancelled\n";
        getline(cin, completion_state);
        if (completion_state.length() == 1 && completion_state[0] <= '4' && completion_state[0] >= '1') {
            if (completion_state[0] == '1') {
                completion_state = "Acknowledged";
            } else if (completion_state[0] == '2') {
                completion_state = "In Progress";
            } else if (completion_state[0] == '3') {
                completion_state = "Completed";
            } else if (completion_state[0] == '4') {
                completion_state = "Cancelled";
            }
            break;
        } else {
            cout << "Choose an option between 1-3!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the Severity Level of the Issue:\n";
        cout << "Required Format: Number between 1-4\n";
        getline(cin, severity);
        if (severity.length() == 1 && severity[0] <= '4' && severity[0] >= '1') {
            break;
        } else {
            cout << "Severity Level must be in correct format!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    string confirm_input;

        cout << "ChangeID: " << change_id << "\n";
        cout << "UserID of the user who submitted the change request: " << user_id << "\n";
        cout << "Product Name: " << product_name << "\n";
        cout << "ReleaseID of Where the Bug was Found: " << bug_release_id << "\n";
        cout << "Date that the Issue was Reported: " << report_date << "\n";
        cout << "Completion State: " << completion_state << "\n";
        cout << "Severity Level: " << severity << "\n";
        cout << "Do you want to confirm this updated change request? (Y/N)\n";
        getline(cin, confirm_input);

    if (confirm_input == "Y" || confirm_input == "y"){
        update_change_request_query(
                                change_id,
                                user_id, 
                                product_name, 
                                bug_release_id, 
                                report_date,
                                completion_state,
                                severity
                                );
        cout << "You have successfully updated a change request!\n";
        cout << "You have been re-directed to the Main Menu!\n";
    } else {
        cout << "Action has been aborted.\n";
        cout << "You have been re-directed to the Main Menu!\n";
    }
    return;
}
