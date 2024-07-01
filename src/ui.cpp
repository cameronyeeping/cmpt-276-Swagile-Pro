#include <iostream>
#include <string>
#include "../include/ui.h"

using namespace std;

void start_ui() {
    int selection;
    // TODO: put in do/while loop
    string directory;
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
}
int display_main_menu(){
    int selection = 0;

    cout << "Swagile Pro\n";
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

void change_item_maintenance_menu() {

}

void issue_menu() {
    int selection = 0;
    cout << "1) Create Change request\n";
    cout << "2) Change Item Maintenance\n";
    cout << "0) Back\n";
    cin.ignore();
    cin >> selection;
    switch (selection) {
    case 1:
        cout << "Create Change Request menu\n";
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


void create_report_menu() {
    int selection = 0;
    cout << "1) Create report\n";
    cout << "2) Edit existing report\n";
    cout << "3) Delete Report\n";
    cout << "0) Back\n";
    cin >> selection;
    switch (selection) {
    case 1:
        cout << "Create report menu\n";
        break;
    case 2:
        cout << "Edit existing report menu\n";
        break;
    case 3:
        cout << "Delete report menu\n";
        break;
    case 0:
        break;
    default: 
        cout << "Invalid input\n";
        break;
    }
}

void product_menu(){
    int selection = 0;
    cout << "1) Create Product\n";
    cout << "2) Create Product Release\n";
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

void create_employee(){
    string first, last;
    cout << "Enter employee name: ";
    cin >> first >> last;

    cout << first << " " << last << endl;
    return;
}


void user_menu() {
    int selection;
    cout << "1) Create Employee\n";
    cout << "2) Edit Employee\n";
    cout << "3) Delete Employee\n";
    cout << "4) Back\n";
    cout << "\nEnter selection: ";

    cin >> selection;
    switch (selection) {
    case 1: 
        create_employee();
        break;
    case 2: 
        //edit_employee();
        break;
    case 3:
        create_employee();
        break;
    }
    return;
}
