/*
 * Module: Product Maintenance
 * Rev 4. - 2024-07-30 Modified by William Phan
          - Implemented update_change_request()
 * Rev 3. - 2024-07-30 Modified by Dylan Dang
          - Fixed invalid trial bugs
 * Rev 2. - 2024-07-29 Modified by Dylan Dang
 *        - Fixed 5 wrong attempt loop
 * Rev 1. - 2024-07-15 Original by William Phan
 * --------------------------------------------------
 * This module contains the implementations of the exported functions outlined in "product_maint.h"
*/


#include <iostream>
#include <string>
#include "../include/product_maint.h"
#include "../include/product_queries.h"

using namespace std;


/*
 * create_product_release() prompts the user for a Product name, releaseID, and release date.
 * After checking for validity, it passes control to the product queries module to create a new product.
*/
void create_product_release() {
    string name;
    string release_id;
    string release_date;

    cin.ignore(100000, '\n');
    //User has 5 attempts to provide a valid input, if number of attempt exceeds 5, they are redirected to the main menu
    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the Product Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        //cin.ignore(10000, '\n');

        getline(cin, name);
        if (name.length() <= 30) {
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
        cout << "Maximum Length: 30 Characters \n";
        cout << "Required Format: #.#.# \n";
        getline(cin, release_id);
        if (release_id.length() <= 30) {
            break;
        } else {
            cout << "ReleaseID must be 30 characters or less!\n";
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

        cout << "Please Enter the Product Release Date:\n";
        cout << "Required Format: YYYY-MM-DD\n";
        getline(cin, release_date);
        if (release_date.empty()) {
            break;
        }
        //Check if inputted date is in correct format 
        if (release_date.length() == 10 && release_date[4] == '-' && release_date[7] == '-' ) {
            month_str = release_date.substr(5,6);
            day_str = release_date.substr(8,9);

            //Convert inputted date segements into ints for comparison
            month_int = stoi(month_str);
            day_int = stoi(day_str);
            
            //Check if inputted date segments are valid
            if (month_int < 1 || month_int > 12 || day_int < 1 || day_int > 31) {
                cout << "Release date must be in correct format!\n";
            } else {
                break;
            }

        } else {
            cout << "Release date must be in correct format!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    string confirm_input;

    //Display the provided inputs back to the user for confirmation
    cout << "Product Name: " << name << "\n";
    cout << "ReleaseID: " << release_id << "\n";
    cout << "Release Date: " << release_date << "\n";
    cout << "Do you want to add this product? (Y/N)\n";
    getline(cin, confirm_input);

    if (confirm_input == "Y" || confirm_input == "y"){
        add_product_release_query(name,           // name of the product
                                  release_id,     // release ID of the product
                                  release_date    // next anticipated release date of product
                        );
        cout << "You have been re-directed to the Main Menu!\n";
    } else {
        cout << "Action has been aborted.\n";
        cout << "You have been re-directed to the Main Menu!\n";
    }

    return;
}

/*
 * update_product_release() first displays all products in the database. It then prompts the user for 
 * a product name (primary key) to update. After checking for validity, it prompts the user again for 
 * releaseID and anticipated release date. After checking the new inputs for validity, it passes control
 * to the product queries module to update the given product.
*/
void update_product_release() {
    string product_name;
    string release_id;
    string release_date;
    string old_product_name;
    string old_release_id;
    
    //Display all current product releases in the database
    display_product_release_query();

    cin.ignore(10000, '\n');
    for (int attempt_num = 5; attempt_num > 0; attempt_num--) { 
        cout << "Please Enter the Product Name to be Edited:\n";
        cout << "Maximum Length: 30 Characters \n";
        getline(cin, old_product_name);

        cout << "Please Enter the Product ReleaseID to be Edited:\n";
        cout << "Format: #.#.# \n";
        getline(cin, old_release_id);

        //Check if Product Name and ReleaseID is valid
        if (search_product_query(old_product_name, old_release_id) == true) {
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
        cout << "Please Enter the New Product Name:\n";
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
        cout << "Please Enter the New ReleaseID:\n";
        cout << "Required Format: #.#.# \n";
        getline(cin, release_id);
        if (release_id.length() <= 30) {
            break;
        } else {
            cout << "ReleaseID must be 30 characters or less!\n";
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
        cin.ignore(100000, '\n');
        cout << "Please Enter the New Product Release Date:\n";
        cout << "Required Format: YYYY-MM-DD\n";
        getline(cin, release_date);
        if (release_date.empty()) {
            break;
        }

        //Check if inputted date is in correct format

        if (release_date.length() == 10 && release_date[4] == '-' && release_date[7] == '-' ) {
            month_str = release_date.substr(5,6);
            day_str = release_date.substr(8,9);
            
            //Convert inputted date segements into ints for comparison
            month_int = stoi(month_str);
            day_int = stoi(day_str);

            //Check if inputted date segments are valid
            if (month_int < 1 || month_int > 12 || day_int < 1 || day_int > 31) {
                cout << "Release date must be in correct format!\n";
            } else {
                break;
            }

        }
        else {
            cout << "Release date must be in correct format!\n";
        }
        if (attempt_num == 1){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    string confirm_input;

    //Display the provided inputs back to the user for confirmation
    cout << "Old Product Name: " << old_product_name << "\n";
    cout << "Old ReleaseID: " << old_release_id << "\n";
    cout << "New Product Name: " << product_name << "\n";
    cout << "New ReleaseID: " << release_id << "\n";
    cout << "New Release Date: " << release_date << "\n";
    cout << "Do you want to confirm the updated product release? (Y/N)\n";
    getline(cin, confirm_input);

    if (confirm_input == "Y" || confirm_input == "y"){
        update_product_release_query(product_name,
                                     release_id, 
                                     release_date,  
                                     old_product_name, 
                                     old_release_id     
                        );
        cout << "You have been re-directed to the Main Menu!\n";
    } else {
        cout << "Action has been aborted.\n";
        cout << "You have been re-directed to the Main Menu!\n";
    }
    return;

}

/*
 * display_product_releases() displays all product releases in the database.
*/
void display_product_releases() {
    display_product_release_query();
}

/*
 * display_products() displays all products in the database.
*/
void display_products() {
    display_product_query();
}