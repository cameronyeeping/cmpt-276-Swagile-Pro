#ifndef MACROS_H 
#define MACROS_H
// DO NOT SUBMIT THIS MODULE

#include <iostream>
#include <sqlite3.h>
#include <string>

#define CREATE_USERS_TABLE "CREATE TABLE IF NOT EXISTS Users ( \
    user_id INTEGER PRIMARY KEY, \
    first_name char(30) NOT NULL, \
    last_name char(30) NOT NULL, \
    email char(50) NOT NULL, \
    department char(50));"

#define CREATE_PRODUCT_RELEASE_TABLE "CREATE TABLE IF NOT EXISTS Product_Release ( \
    product_name char(30), \
    release_id char(30), \
    release_date DATE, \
    PRIMARY KEY (product_name, release_id));"

#define CREATE_CHANGE_REQUEST_TABLE "CREATE TABLE IF NOT EXISTS Change_Request ( \
    change_id INTEGER PRIMARY KEY, \
    user_id INTEGER NOT NULL, \
    product_name char(30) NOT NULL, \
    bug_release_id char(30) NOT NULL, \
    report_date DATE NOT NULL, \
    completion_state char(30), \
    severity char(30) NOT NULL, \
    FOREIGN KEY (user_id) REFERENCES Users (user_id) \
        ON DELETE CASCADE \
        ON UPDATE CASCADE, \
    FOREIGN KEY (product_name, bug_release_id) REFERENCES Product_Release (product_name, release_id) \
        ON DELETE CASCADE \
        ON UPDATE CASCADE);"

#define CREATE_CHANGE_ITEM_TABLE "CREATE TABLE IF NOT EXISTS Change_Item ( \
    change_id INTEGER, \
    product_name char(30), \
    future_release char(30), \
    description char(1000), \
    FOREIGN KEY (change_id) REFERENCES Change_Request (change_id) \
        ON DELETE CASCADE \
        ON UPDATE CASCADE, \
    FOREIGN KEY (product_name, future_release) REFERENCES Product_Release (product_name, release_id) \
        ON DELETE CASCADE \
        ON UPDATE CASCADE);"



#endif 
