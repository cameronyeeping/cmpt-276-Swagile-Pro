#include <iostream>
#include <string>
#include "../include/issue_manag.h"
#include "../include/issue_queries.h"
using namespace std;

void create_change_request() {
    string user_id;
    string name; 
    string date;
    string bug_release_id;  
    string completion = "Acknowledged";  
    string severity;

    //User has 5 times to provide valid input, bring to main menu after 5
    for (int attempt_num = 5; attempt_num >= 0; attempt_num--) { 
        cout << "Please Enter the UserID of the User:\n";
        cin >> user_id;
        if (search_user_id_query(user_id) == true) { 
            break;
        } else {
            cout << "Enter a valid UserID!\n";
            continue;
        }
        if (attempt_num == 0){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num >= 0; attempt_num--) { 
        cout << "Please Enter the Product Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        cin >> name;

        cout << "Please Enter the Product ReleaseID:\n";
        cout << "Format: #.#.# \n";
        cin >> bug_release_id;

        if (search_product_query(name, bug_release_id) == true) {  // if product found IMPLEMENT
            break;
        } else {
            cout << "Enter valid product name and releaseID!\n";
            continue;
        }
        if (attempt_num == 0){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num >= 0; attempt_num--) { 
        string month_str;
        string day_str;

        int month_int;
        int day_int;

        cout << "Please Enter the Current Date:\n";
        cout << "Required Format: YYYY-MM-DD\n";
        cin >> date;

        if (date.length() == 10 && date[4] == '-' && date[7] == '-' ) {
            month_str = date.substr(5,6);
            day_str = date.substr(8,9);

            month_int = stoi(month_str);
            day_int = stoi(day_str);

            if (month_int < 1 || month_int > 12 || day_int < 1 || day_int > 31) {
                cout << "Current date must be in correct format!\n";
                continue;
            } else {
                break;
            }

        } else {
            cout << "Current date must be in correct format!\n";
            continue;
        }
        if (attempt_num == 0){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num >= 0; attempt_num--) { 
        cout << "Please Enter the Severity Level of the Issue:\n";
        cout << "Required Format: Number between 1-4\n";
        cin >> severity;
        if (severity.length() == 1 && severity[0] <= '4' && severity[0] >= '1') {
            break;
        } else {
            cout << "Severity Level must be in correct format!\n";
            continue;
        }
        if (attempt_num == 0){
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
    cin >> confirm_input;

    if (confirm_input == "Y" || "y"){
        add_change_request_query(user_id, 
                                 name,    
                                 date,   
                                 bug_release_id, 
                                 completion 
                                 severity 
                                );
        cout << "You have successfully created a new user!\n";
        cout << "You have been re-directed to the Main Menu!\n";
    } else {
        cout << "Action has been aborted.\n";
        cout << "You have been re-directed to the Main Menu!\n";
    }


    return;
}