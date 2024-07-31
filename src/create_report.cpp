/*
Module: Create Report
Rev 1. - 2024-07-16 Original by Dylan Dang
--------------------------------------------------
This module contains the implementations of the exported functions outlined in "create_report.h"
*/

#include <iostream>
#include <string>
#include "../include/create_report.h"
#include "../include/report_queries.h"
using namespace std;

/*
 * create_report_1() polls for a product name that will be used for creating a 
 * type 1 report. It also checks the input for validity before passing control
 * to the report queries module.
 * 
 * A type 1 report is a list of all change items regarding a particular product
 * that are not already completed/cancelled.
*/
void create_report_1() {
    string product;
    cout << "Please Enter the Product Name:\n";
    cin.ignore(100000, '\n');

    cin >> product;

    //Display all the change items that is not completed/cancelled
    display_report_1_query(product);
}

/*
 * create_report_2() first polls for a product, then a change item for that product.
 * After checking the validity of the input, it passes control to the report queries module.
 * 
 * A type 2 report is a list of customers/staff who need to be informed when a particular 
 * change has been implemented, and in what ProductRelease ID.
*/
void create_report_2() {
    string product;
    string product_release;
    cin.ignore(100000, '\n');

    cout << "Please Enter the Product Name:\n";
    cin >> product;

    cout << "Please Enter the Product Release ID:\n";
    cin >> product_release;

    //Display all the customer needs to be informed that state is completed
    display_report_2_query(product, product_release);
}