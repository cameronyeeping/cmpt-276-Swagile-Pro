/*
 * Module: Product Queries
 * Revision History:
 * Version 2 - 2024/07/16 - Revised by Ananya Singh
 * Version 1 -  2024/07/01 Original by Cameron Yee-Ping
 * ------------------------------------------------
 * This module contains all queries involving the product table in swagile_pro.db
 * The functions in this module assume that all function parameters have been checked for correctness.
 * However, if an error occurs in any of these functions, they throw an error that can be caught by the caller.
 * 
 * This module hides the representation of products vs their releases. They are actually stored in the same table. 
 * When the caller calls a product function vs a product release function, they access the same table. The only difference is 
 * how their output is formatted.
*/
#ifndef PRODUCT_QUERIES_H
#define PRODUCT_QUERIES_H

#include <iostream>
#include <string>
#include <sqlite3.h>

#include "../include/database_connection.h"

/*
 * add_product_release_query() creates an INSERT INTO query that adds a row into the product table in swagile_pro.db 
 * using the parameters provided.
*/
void add_product_release_query(std::string product_name,            // name of the product
                        std::string release_id,     // release ID of the product
                        std::string release_date    // next anticipated release date of product
                        );
//===================================

/*
 * update_product_query() creates an UPDATE TABLE query that changes a product's attributes 
 * to the ones provided as parameters.
*/
void update_product_release_query(std::string product_name,            // name of the product
                        std::string release_id,         // release ID of the product
                        std::string release_date,       // next anticipated release date of product
                        std::string old_product_name,   // original product name
                        std::string old_release_id      // original release id
                        );
    
//===================================

/*
 * delete_product_query() deletes a given product from the product table using a DELETE FROM query.
*/
void delete_product_release_query(std::string product_name  // name of product to be deleted.
                        );
//===================================

/*
 * display_product_query() displays all products in the table using a SELECT FROM query.
*/
void display_product_query();
//===================================

/*
 * this function displays all product releases in the database. It is a slightly different query than 
 * display_product_query().
*/
void display_product_release_query();

bool search_product_query(std::string name, std::string release_id);

#endif 
