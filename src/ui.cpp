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
            cout << "Enter back-up directory: ";
            cin >> directory;
            cout << "Back-up created\n";

            break;
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
    cout << "5) Backup System\n";
    cout << "0) Exit\n";
    cout << "\nEnter selection: ";
    cin >> selection;
    return selection;
}

static void change_request_menu() {
    int selection = 0;
    cout << "1) Create Change Request\n";
    cout << "2) Update Change Request\n";
    cout << "3) Delete Change Request\n";
    cout << "4) Display Change Requests\n";
    cin.ignore();
    cin >> selection;
    switch (selection) {
    case 1:
        cout << "Create change request placeholder\n";
        break;
    case 2:
        cout << "Update Change Request placeholder\n";
        break;
    case 3:
        cout << "Delete Change Request placeholder\n";
        break;
    case 4:
        cout << "display change request placeholder\n";
        break;
    }
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
    cout << "1) Report #1\n";
    cout << "2) Report #2\n";
    cout << "0) Back\n";
    cin >> selection;
    switch (selection) {
    case 1:
        cout << "Report #1\n";
        break;
    case 2:
        cout << "Report #2\n";
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
    cout << "1) Create Product\n";
    cout << "2) Create Product Release\n";
    cout << "3) Update Product\n";
    cout << "4) Update Product Release\n";
    cout << "5) Display Products\n";
    cout << "6) Display Product Releases\n";
    cout << "7) Delete Product\n";
    cout << "8) Delete Product Releases\n";
    cout << "0) Back\n";

    cin >> selection; 
    switch (selection) {
    case 1:
        cout << "Create Product menu\n";
        break;
    case 2:
        cout << "Create Product release menu\n";
    case 0:
        break;
    default: 
        cout << "Invalid input\n";
    }
    return;
}


static void user_menu() {
    int selection;
    cout << "1) Create Employee\n";
    cout << "2) Edit Employee\n";
    cout << "3) Delete Employee\n";
    cout << "0) Back\n";
    cout << "\nEnter selection: ";

    cin >> selection;
    switch (selection) {
    case 1: 
        cout << "create employee placeholder\n";
        break;
    case 2: 
        cout << "edit employee placeholder\n";
        break;
    case 3:
        cout << "delete employee placeholder\n";
        break;
    case 0:
        break;
    }
    return;
}

static void change_item_maintenance_menu() {
    cout << "=======Change Item Maintenance=======\n";
    cout << "1) Query Change Item\n";
    cout << "2) Create Change Item\n";
    cout << "3) Update Change Item\n";
    cout << "4) Delete Change Item\n";
    cout << "5) Display Change Items\n";
    cout << "0) Back\n";
    int selection;
    cin >> selection;

    switch (selection) {
    case 1:
        //query_change_item();
        cout << "query change item placeholder\n";
        break;
    case 2: 
        cout << "update change item placeholder\n";
        break;
    case 3:
        cout << "update change item placeholder\n";
        break;
    case 4:
        cout << "delete change item placeholder\n";
        break;
    case 5: 
        cout << "display change items placeholder\n";
    case 0:
        break;
    default:
        cout << "invalid input\n";
    }

}
