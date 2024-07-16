/*
 * Module: Report Queries
 * Revision History:
 * Rev 1. 2024/07/01 Original by Cameron Yee-Ping
 * ------------------------------------------------
 * This module contains all queries involving the report table in swagile_pro.db
 * The functions in this module assume that all function parameters have been checked for correctness.
 * However, if an error occurs in any of these functions, they throw an error that can be caught by the caller.
*/
#ifndef REPORT_QUERIES_H
#define REPORT_QUERIES_H

#include <iostream>
#include <sqlite3.h>
#include <string>

#include "../include/query_results.h"

/*
 * Report #1: : List of all change items for a particular product that are not done and not cancelled.  
 * I.e. New/Reported, or Assessed, or InProgress.
*/
void display_report_1_query(std::string product);

/*
 * Report #2: List of customers/staff who need to be informed when a particular
 * change has been implemented, and in what ProductRelease ID.   
 * Select product, then select from ChangeItems for that product. 
 * To word the report, select ProductRelease from list of releases for that product.  
 * Generate report of all requester and the email addresses of Requesters for that ChangeItem.
 */
void display_report_2_query(std::string product, // product that we are displaying information for
                                    std::string product_release // product release of the product
                            );
#endif