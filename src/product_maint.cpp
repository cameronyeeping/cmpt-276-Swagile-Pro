#include <iostream>
#include <string>
#include "../include/product_maint.h"
#include "../include/product_queries.h"
using namespace std;

void create_product_release() {
    string name;
    string release_id;
    string release_date;

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

        if (release_date.length() == 10 && release_date[4] == '-' && release_date[7] == '-' ) {
            month_str = release_date.substr(5,6);
            day_str = release_date.substr(8,9);

            month_int = stoi(month_str);
            day_int = stoi(day_str);

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

    cout << "Product Name: " << name << "\n";
    cout << "ReleaseID: " << release_id << "\n";
    cout << "Release Date: " << release_date << "\n";
    cout << "Do you want to add this product? (Y/N)\n";
    cin >> confirm_input;

    if (confirm_input == "Y" || "y"){
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

void update_product_release() {
    string name;
    string release_id;
    string release_date;
    
    display_product_release_query();

    for (int attempt_num = 5; attempt_num >= 0; attempt_num--) { 
        cout << "Please Enter the Product Name:\n";
        cout << "Maximum Length: 30 Characters \n";
        cin >> name;

        cout << "Please Enter the Product ReleaseID:\n";
        cout << "Format: #.#.# \n";
        cin >> release_id;

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

    //User has 5 times to provide valid input, bring to main menu after 5
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

        if (release_date.length() == 10 && release_date[4] == '-' && release_date[7] == '-' ) {
            month_str = release_date.substr(5,6);
            day_str = release_date.substr(8,9);

            month_int = stoi(month_str);
            day_int = stoi(day_str);

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

    cout << "Product Name: " << name << "\n";
    cout << "ReleaseID: " << release_id << "\n";
    cout << "Release Date: " << release_date << "\n";
    cout << "Do you want to confirm the updated product release? (Y/N)\n";
    cin >> confirm_input;

    if (confirm_input == "Y" || "y"){
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

void display_product_releases() {
    display_product_release_query();
}

void display_products() {
    display_product_query();
}