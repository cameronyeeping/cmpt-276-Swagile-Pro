#ifndef CREATE_REPORT_QUERIES_H
#define CREATE_REPORT_QUERIES_H

#include <iostream>
#include <sqlite3.h>
#include <string>


// list of all change items not done or cancelled
void display_report_1_query();

/*
 * Report #2: List of customers/staff who need to be informed when a particular
 * change has been implemented, and in what ProductRelease ID.   
 * Select product, then select from ChangeItems for that product. 
 * To word the report, select ProductRelease from list of releases for that product.  
 * Generate report of all requester and the email addresses of Requesters for that ChangeItem.
 */
void display_report_2_query(std::string product);
#endif