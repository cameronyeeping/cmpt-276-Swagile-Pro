/*
 * Module: Product Maintenance
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

    //User has 5 attempts to provide a valid input, if number of attempt exceeds 5, they are redirected to the main menu
     for (int attempt_num = 5; attempt_num >= 0; attempt_num--) { 
        cout << "Please Enter the Product Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        cin >> name;
        if (name.length() <= 30) {
            break;
        }
        else {
            cout << "Product name must be 30 characters or less!\n";
            continue;
        }
        if (attempt_num == 0){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num >= 0; attempt_num--) { 
        cout << "Please Enter the Product ReleaseID:\n";
        cout << "Maximum Length: 30 Characters \n";
        cout << "Required Format: #.#.# \n";
        cin >> release_id;
        if (release_id.length() <= 30) {
            break;
        } else {
            cout << "ReleaseID must be 30 characters or less!\n";
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

        cout << "Please Enter the Product Release Date:\n";
        cout << "Required Format: YYYY-MM-DD\n";
        cin >> release_date;

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
                continue;
            } else {
                break;
            }

        } else {
            cout << "Release date must be in correct format!\n";
            continue;
        }
        if (attempt_num == 0){
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
    cin >> confirm_input;

    if (confirm_input == "Y" || confirm_input == "y"){
        add_product_release_query(name,           // name of the product
                                  release_id,     // release ID of the product
                                  release_date    // next anticipated release date of product
                        );
        cout << "You have successfully created a new product!\n";
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
    string name;
    string release_id;
    string release_date;
    
    //Display all current product releases in the database
    display_product_release_query();

    for (int attempt_num = 5; attempt_num >= 0; attempt_num--) { 
        cout << "Please Enter the Product Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        cin >> name;

        cout << "Please Enter the Product ReleaseID:\n";
        cout << "Format: #.#.# \n";
        cin >> release_id;

        //Check if Product Name and ReleaseID is valid
        if (search_product_query(name, release_id) == true) {  // if product found IMPLEMENT
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
        cout << "Please Enter the Product Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        cin >> name;
        if (name.length() <= 30) {
            break;
        }
        else {
            cout << "Product name must be 30 characters or less!\n";
            continue;
        }
        if (attempt_num == 0){
            cout << "You have exceeded the number of allowed attempts!\n";
            cout << "You have been re-directed to the Main Menu!\n";
            return;
        }
    }

    for (int attempt_num = 5; attempt_num >= 0; attempt_num--) { 
        cout << "Please Enter the ReleaseID:\n";
        cout << "Required Format: #.#.# \n";
        cin >> release_id;
        if (release_id.length() <= 30) {
            break;
        } else {
            cout << "ReleaseID must be 30 characters or less!\n";
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

        cout << "Please Enter the Product Release Date:\n";
        cout << "Required Format: YYYY-MM-DD\n";
        cin >> release_date;

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
                continue;
            } else {
                break;
            }

        } else {
            cout << "Release date must be in correct format!\n";
            continue;
        }
        if (attempt_num == 0){
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
    cout << "Do you want to confirm the updated product release? (Y/N)\n";
    cin >> confirm_input;

    if (confirm_input == "Y" || confirm_input == "y"){
        update_product_release_query(name,            // name of the product
                                     release_id,     // release ID of the product
                                     release_date    // next anticipated release date of product
                        );
        cout << "You have successfully updated a product release!\n";
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