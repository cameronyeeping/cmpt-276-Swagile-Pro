/*
 * Module: Macros
 * Revision History:
 * Version 2 - 2024/07/16 - Revised by Ananya Singh
 * Version 1 - 2024/07/15 - Original by Cameron Yee-Ping
 * ------------------------------------------------------
 * This module defines macros used throughout the low level modules
 * They are sql queries that are used when preparing a statement. This module does not
 * have a corresponding .cpp file.
*/
#ifndef MACROS_H 
#define MACROS_H

#include <iostream>
#include <sqlite3.h>
#include <string>

#define PRAGMA_FOREIGN_KEYS "pragma foreign_keys=on;"
#define CREATE_USERS_TABLE "CREATE TABLE IF NOT EXISTS Users ( \
    user_id INTEGER PRIMARY KEY, \
    first_name char(30) NOT NULL, \
    last_name char(30) NOT NULL, \
    phone_number char(13) NOT NULL, \
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
#define GET_CHANGE_ID_QUERY "SELECT * FROM Change_Request WHERE change_id = ?;"

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


#define ADD_USER_QUERY "INSERT INTO Users (first_name, last_name, phone_number, email, department) \
    VALUES (?, ?, ?, ?, ?);"

#define UPDATE_USER_QUERY "UPDATE Users \
    SET first_name = ?, last_name = ?, phone_number = ?, email = ?, department = ? \
    WHERE user_id = ?;"


#define SEARCH_USER_QUERY "SELECT * FROM Users \
    WHERE first_name = ? \
    AND last_name = ?;"
#define DELETE_USER_QUERY \
    "DELETE FROM Users " \
    "WHERE user_id = ?;"

#define DISPLAY_USERS_QUERY \
    "SELECT * " \
    "FROM Users;"

#define GET_USER_ID_QUERY "SELECT user_id FROM Users WHERE user_id = ?;"
#define ADD_PRODUCT_RELEASE_QUERY "INSERT INTO Product_Release (product_name, release_id, release_date) \
    VALUES (?, ?, ?);"

#define UPDATE_PRODUCT_RELEASE_QUERY "UPDATE Product_Release \
    SET product_name = ?, release_id = ?, release_date = ? \
    WHERE product_name = ? AND release_id = ?;"

#define DELETE_PRODUCT_RELEASE_QUERY "DELETE FROM Product_Release \
    WHERE product_name = ?;"
    
#define DISPLAY_PRODUCT_QUERY "SELECT DISTINCT product_name FROM Product_Release;"

#define DISPLAY_PRODUCT_RELEASE_QUERY "SELECT * \
    FROM Product_Release;"

#define GET_PRODUCT_QUERY "SELECT * FROM Product_Release \
    WHERE \
        product_name = ? AND release_id = ?"
#define ADD_CHANGE_ITEM_QUERY \
    "INSERT INTO Change_Item (change_id, product_name, future_release, description) " \
    "VALUES (?, ?, ?, ?);"

#define UPDATE_CHANGE_ITEM_QUERY \
    "UPDATE Change_Item " \
    "SET product_name = ?, future_release = ?, description = ? " \
    "WHERE change_id = ?;"

#define DELETE_CHANGE_ITEM_QUERY \
    "DELETE FROM Change_Item " \
    "WHERE change_id = ?;"

#define DISPLAY_CHANGE_ITEMS_QUERY \
    "SELECT * " \
    "FROM Change_Item;"
#define CREATE_REPORT_1 "SELECT CR.change_id, CR.completion_state, CR.severity, CI.description \
    FROM Change_Request CR \
    JOIN Change_Item CI ON CR.change_id = CI.change_id \
    WHERE NOT (CR.completion_state = 'Completed') \
    AND CR.product_name = ?;"
#define CREATE_REPORT_2 "SELECT DISTINCT Users.user_id, Users.first_name, Users.last_name FROM Users \
    JOIN Change_Request ON Users.user_id = Change_Request.user_id \
    WHERE Change_Request.product_name = ?\
    AND Change_Request.bug_release_id = ?;"

#define ADD_CHANGE_REQUEST_QUERY \
        "INSERT INTO Change_Request (user_id, product_name, bug_release_id, report_date, completion_state, severity) \
        VALUES (?, ?, ?, ?, ?, ?);"

#define UPDATE_CHANGE_REQUEST_QUERY \
        "UPDATE Change_Request \
        SET user_id = ?, product_name = ?, bug_release_id = ?, report_date = ?, completion_state = ?, severity = ? \
        WHERE change_id = ?;"

#define DELETE_CHANGE_REQUEST_QUERY "DELETE FROM Change_Request \
        WHERE change_id = ?;"

#define DISPLAY_CHANGE_REQUEST_QUERY \
        "SELECT * " \
        "FROM Change_Request;"

#define CHANGE_ITEM_DETAIL_QUERY \
        "SELECT *  \
        FROM Change_Item \
        WHERE change_id = ?;"
#endif 
