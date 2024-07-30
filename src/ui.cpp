/* 
 * Module: UI
 * Revision History:
 * Rev.1 - 2024/07/01 Original by Cameron Yee-Ping
 * -------------------------------------------------
 * Includes implementations of functions defined in "ui.h"
*/

#include "../include/ui.h"
#include "../include/create_report.h"
#include "../include/issue_manag.h"
#include "../include/macros.h"
#include "../include/product_maint.h"
#include "../include/user_maint.h"
#include "../include/issue_queries.h"
#include "../include/database_connection.h"


using namespace std;

void start_ui() {
    int selection;
    string directory;
    do {
        selection = display_main_menu();
        switch (selection) {
        case 1:
            user_menu();
            break;
        case 2:
            product_menu();
            break;
        case 3:
            issue_menu();
            break;
        case 4:
            create_report_menu();
            break;
        case 5:
            create_backup("./");
        case 0:
            break;
        default:
            cout << "Invalid input\n";
        }
    } while (selection != 0);
}

static int display_main_menu(){
    int selection = 0;

    cout << "========Main Menu========\n";
    cout << "1) User Maintenance\n";
    cout << "2) Product Maintenance\n";
    cout << "3) Issue Management\n";
    cout << "4) Create a Report\n";
    cout << "5) Create Backup\n";
    cout << "0) Exit\n";
    cout << "\nEnter selection: ";
    cin >> selection;
    return selection;
}

static void issue_menu() {
    int selection = 0;
    cout << "1) Change Request Maintenance\n";
    cout << "2) Change Item Maintenance\n";
    cout << "0) Back\n";
    cin.ignore();
    cin >> selection;
    switch (selection) {
    case 1:
        change_request_menu();
        break;
    case 2:
        change_item_maintenance_menu();
        break;
    case 0: 
        break;
    default:
        cout << "Invalid input\n";
        break;
    }

}

static void create_report_menu() {
    int selection = 0;
    cout << "1) Create Report #1\n";
    cout << "2) Create Report #2\n";
    cout << "0) Back\n";
    cin >> selection;
    switch (selection) {
    case 1:
        create_report_1();
        break;
    case 2:
        create_report_2;
        break;
    case 0:
        break;
    default: 
        cout << "Invalid input\n";
        break;
    }
}

static void product_menu(){
    int selection = 0;
    cout << "1) Create Product Release\n";
    cout << "2) Update Product Release\n";
    cout << "3) Display Product Release\n";
    cout << "4) Display Products\n";
    cout << "0) Back\n";

    cin >> selection; 
    switch (selection) {
    case 1:
        create_product_release();
        break;
    case 2:
        update_product_release();
    case 3:
        display_product_releases();
        break;
    case 4:
        display_products();
        break;
    case 0:
        break;
    default: 
        cout << "Invalid input\n";
    }
    return;
}


static void user_menu() {
    int selection;
    cout << "1) Create User\n";
    cout << "2) Update User\n";
    cout << "3) Display Users\n";
    cout << "0) Back\n";
    cout << "\nEnter selection: ";

    cin >> selection;
    switch (selection) {
    case 1: 
        create_user();
        break;
    case 2: 
        update_user();
        break;
    case 3: 
        display_users();
        break;
    case 0:
        break;
    }
    return;
}

static void change_request_menu() {
    int selection = 0;
    cout << "1) Create Change Request\n";
    cout << "2) Display Change Requests\n";
    cout << "0) Back\n";
    cin.ignore();
    cin >> selection;
    switch (selection) {
    case 1:
        create_change_request();
        break;
    case 2:
        display_change_request_query();
        break;
    case 0:
        break;
    default: 
        cout << "Invalid input\n";
    }
}

static void change_item_maintenance_menu() {
    cout << "=======Change Item Maintenance=======\n";
    cout << "1) Create Change Item\n";
    cout << "2) Display Change Items\n";
    cout << "0) Back\n";
    int selection;
    cin >> selection;

    switch (selection) {
    case 1:
        create_change_item();
        break;
    case 2: 
        display_change_items_query();
        break;
    case 0:
        break;
    default:
        cout << "invalid input\n";
    }

}
