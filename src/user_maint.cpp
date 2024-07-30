/*
 * Module: User Maintenance
 * Rev 1. - 2024-07-15 Original by William Phan
 * --------------------------------------------------
 * This module contains the implementations of the exported functions outlined in "user_maint.h"
*/


#include <iostream>
#include <string>
#include "../include/user_maint.h"
#include "../include/user_queries.h"

using namespace std;


/*
 * create_user() prompts for name, phone number, email, and optionally department. If department is left blank,
 * it means that the user is external. After checking the input for validity, it creates a user with the corresponding
 * attributes.
*/
void create_user() {
    string first_name;
    string last_name;
    string phone_number;
    string email;
    string department;

    //User has 5 attempts to provide a valid input, if number of attempt exceeds 5, they are redirected to the main menu
    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the User First Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        cin >> first_name;
        if (first_name.length() <= 30) {
            break;
        }
        else {
            cout << "First name must be 30 characters or less!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the User Last Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        cin >> last_name;
        if (last_name.length() <= 30) {
            break;
        } else {
            cout << "Last name must be 30 characters or less!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the User Phone Number:\n";
        cout << "Required Length: 10 Characters \n";
        cout << "Format: 1231231234 \n";
        cin >> phone_number;
        if (phone_number.length() == 10) {
            break;
        } else {
            cout << "Phone number must be 10 characters\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the User Email:\n";
        cout << "Maximum Length: 50 Characters \n";
        cout << "Format: example@example.com \n";
        cin >> email;
        if (email.length() <= 50) {
            break;
        } else {
            cout << "Email must be 50 characters or less\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the User Department:\n";
        cout << "Maximum Length: 50 Characters\n";
        cin >> department;
        if (department.length() <= 50) {
            break;
        } else {
            cout << "Department must be 50 characters or less\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    string confirm_input;

    //Display the provided inputs back to the user for confirmation
    cout << "User First Name: " << first_name << "\n";
    cout << "User Last Name: " << last_name << "\n";
    cout << "User Phone Number: " << phone_number << "\n";
    cout << "User Email: " << email << "\n";
    cout << "User Department: " << department << "\n";
    cout << "Do you want to add this user? (Y/N)\n";
    cin >> confirm_input;

    if (confirm_input == "Y" || confirm_input == "y"){
        add_user_query (first_name,  
                    last_name,    
                    phone_number,  
                    email,         
                    department      
                    );
        cout << "You have successfully created a new user!\n";
        cout << "You have been re-directed to the Main Menu!\n";
    } else {
        cout << "Action has been aborted.\n";
        cout << "You have been re-directed to the Main Menu!\n";
    }


    return;
}

/*
 * update_user() displays all users, and then prompts for a userID. After checking the userID, it prompts again for 
 * name, phone number, email, and department. These inputs are used to update the corresponding user.
*/
void update_user() {
    string user_id;
    string first_name;
    string last_name;
    string phone_number;
    string email;
    string department;

    //Display all current users in the database
    display_users_query();
    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the UserID of the User:\n";
        cin >> user_id;
        //Check if userID is valid
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
        cout << "Please Enter the User First Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        cin >> first_name;
        if (first_name.length() <= 30) {
            break;
        }
        else {
            cout << "First name must be 30 characters or less!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the User Last Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        cin >> last_name;
        if (last_name.length() <= 30) {
            break;
        } else {
            cout << "Last name must be 30 characters or less!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the User Phone Number:\n";
        cout << "Required Length: 10 Characters \n";
        cin >> phone_number;
        if (phone_number.length() == 10) {
            break;
        } else {
            cout << "Phone number must be 10 characters\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the User Email:\n";
        cout << "Maximum Length: 50 Characters \n";
        cout << "Format: example@example.com \n";
        cin >> email;
        if (email.length() <= 50) {
            break;
        } else {
            cout << "Email must be 50 characters or less\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the User Department:\n";
        cout << "Maximum Length: 50 Characters\n";
        cin >> department;
        if (department.length() <= 50) {
            break;
        } else {
            cout << "Department must be 50 characters or less\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    string confirm_input;

    //Display the provided inputs back to the user for confirmation
    cout << "User First Name: " << first_name << "\n";
    cout << "User Last Name: " << last_name << "\n";
    cout << "User Phone Number: " << phone_number << "\n";
    cout << "User Email: " << email << "\n";
    cout << "User Department: " << department << "\n";
    cout << "Do you want to confirm the updated user? (Y/N)\n";
    cin >> confirm_input;

    if (confirm_input == "Y" || confirm_input == "y"){
        update_user_query (user_id,  
                        first_name,  
                        last_name,  
                        phone_number, 
                        email,
                        department
                        );
        cout << "You have successfully updated a user!\n";
        cout << "You have been re-directed to the Main Menu!\n";
    } else {
        cout << "Action has been aborted.\n";
        cout << "You have been re-directed to the Main Menu!\n";
    }
    return;
}

/*
 * display_users() displays all users in the database.
*/
void display_users() {
    display_users_query();
}

