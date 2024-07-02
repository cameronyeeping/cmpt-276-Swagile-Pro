/*
 * Module: Product Maintenance
 * Revision History:
 * Rev. 1 2024/07/01 Original by Ananya Singh
 * ------------------------------------------------
 * This module is used to create new products and new product releases. It exports two functions: create_product()
 * and create_product_release(). 
*/


#ifndef PRODUCT_MAINT_H
#define PRODUCT_MAINT_H
#include <string>

// create_product() is used to create a new product (e.g. 'iPhone 13') in the swagile pro system
void create_product();

// create_product_release() is used to create a new product release (e.g. '3.1.0'),
// for an exisitng product, in the swagile pro system
void create_product_release();

#endif