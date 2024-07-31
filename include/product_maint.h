/*
 * Module: Product Maintenance
 * Rev 2. - 2024-07-02 Modified by Cameron Yee-Ping
 *        - Added Documentation
 *        - Removed create_product() function.
 *        - Added update_product_release(), delete_product_release()
 * Rev 1. - 2024-07-01 Original by Ananya Singh
 * --------------------------------------------------
 * This module is used to create new products and new product releases. It exports two functions: create_product()
 * and create_product_release(). 
*/


#ifndef PRODUCT_MAINT_H
#define PRODUCT_MAINT_H

#include <string>

/*
 * create_product_release() prompts the user for a Product name, releaseID, and release date.
 * The new product's name MUST be unique, as it is the primary key of the table. After checking for
 * validity, it passes control to the product queries module to create a new product.
*/
void create_product_release();
//==============================

/*
 * update_product_release() first displays all products in the database. It then prompts the user for 
 * a product name (primary key) to update. After checking for validity, it prompts the user again for 
 * releaseID and anticipated release date. After checking the new inputs for validity, it passes control
 * to the product queries module to update the given product.
*/
void update_product_release();
//==============================

/*
 * display_product_releases() displays all product releases in the database.
*/
void display_product_releases();
//==============================

/*
 * display_products() displays all products in the database.
*/
void display_products();

#endif