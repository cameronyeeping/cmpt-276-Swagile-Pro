/*
 * Module: Create Report
 * Rev 2. - 2024-07-02 Modified by Cameron Yee-Ping
 *        - Added Documentation
 * Rev 1. - 2024-07-01 Original by Ananya Singh
 * --------------------------------------------------
 * This module contains the mid-level functions for creating a type 1 and type 2 report.
*/
#ifndef CREATE_REPORT_H
#define CREATE_REPORT_H
#include <string>

/*
 * create_report_1() polls for a product name that will be used for creating a 
 * type 1 report. It also checks the input for validity before passing control
 * to the report queries module.
 * 
 * A type 1 report is a list of all change items regarding a particular product
 * that are not already completed/cancelled.
*/
void create_report_1();

/*
 * create_report_2() first polls for a product, then a change item for that product.
 * After checking the validity of the input, it passes control to the report queries module.
 * 
 * A type 2 report is a list of customers/staff who need to be informed when a particular 
 * change has been implemented, and in what ProductRelease ID.
*/
void create_report_2();

#endif
