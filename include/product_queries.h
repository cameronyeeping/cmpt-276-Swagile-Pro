/*
 * Module: Product Queries
 * Revision History:
 * Rev 1. 2024/07/01 Original by Cameron Yee-Ping
 * ------------------------------------------------
 * This module contains all queries involving the product table in swagile_pro.db
 * The functions in this module assume that all function parameters have been checked for correctness.
 * However, if an error occurs in any of these functions, they throw an error that can be caught by the caller.
*/
#ifndef PRODUCT_QUERIES_H
#define PRODUCT_QUERIES_H

#include <iostream>
#include <string>
#include <sqlite3.h>

#include "../include/database_connection.h"

/*
 * add_product_query() creates an INSERT INTO query that adds a row into the product table in swagile_pro.db 
 * using the parameters provided.
*/
void add_product_query(std::string name,            // name of the product
                        std::string release_id,     // release ID of the product
                        std::string release_date    // next anticipated release date of product
                        );
//===================================

/*
 * update_product_query() creates an UPDATE TABLE query that changes a product's attributes 
 * to the ones provided as parameters.
*/
void update_product_query(std::string name,            // name of the product
                        std::string release_id,     // release ID of the product
                        std::string release_date    // next anticipated release date of product
                        );
//===================================

/*
 * delete_product_query() deletes a given product from the product table using a DELETE FROM query.
*/
void delete_product_query(std::string name  // name of product to be deleted.
                        );
//===================================

/*
 * display_product_query() displays all products in the table using a SELECT FROM query.
*/
void display_product_query();


#endif 