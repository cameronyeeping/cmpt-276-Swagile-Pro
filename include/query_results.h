/*
 * Modules: Query Results
 * Revision History:
 * Rev 1. - 2024/07/02 Original by Cameron Yee-Ping
 * --------------------------------------------------
 * This module contains the exported query results class. It holds the results of sqlite queries.
 * It is used internally to test/validate results of a query
*/
#ifndef QUERY_RESULTS_H
#define QUERY_RESULTS_H

#include <string>
#include <vector>

using namespace std;

class Query_Results {
public:
    Query_Results() : num_cols(0), num_rows(0) {} // default constructor

    Query_Results(const vector<string>& data, int rows, int cols) // parameterized constructor
        : data(data), num_rows(rows), num_cols(cols) {}

    // Copy constructor
    Query_Results(const Query_Results& other)
        : data(other.data), num_rows(other.num_rows), num_cols(other.num_cols) {}
    // copy assignment operator
    Query_Results& operator=(const Query_Results& other) {
        if (this == &other) {
            return *this; // self-assignment check
        }
        data = other.data;
        num_rows = other.num_rows;
        num_cols = other.num_cols;
        return *this;
    }
    // move constructor
    Query_Results(Query_Results&& other) noexcept
        : data(std::move(other.data)), num_rows(other.num_rows), num_cols(other.num_cols) {
        other.num_rows = 0;
        other.num_cols = 0;
    }
    // move assignment operator
    Query_Results& operator=(Query_Results&& other) noexcept {
        if (this == &other) {
            return *this; // self-assignment check
        }
        data = std::move(other.data);
        num_rows = other.num_rows;
        num_cols = other.num_cols;
        other.num_rows = 0;
        other.num_cols = 0;
        return *this;
    }
    /*
     * getRows() returns the number of rows in the result
    */
    int getRows() {
        return num_rows;
    }
    //====================
    /*
     * getCols() returns the number of columns in the result
    */
    int getCols() {
        return num_cols;
    }
    //====================
    
    /*
     * getData() returns a vector of strings with the results of the query
    */
    vector<string> getData() {
        return data;
    }
private:
    vector<string> data;  // this vector holds the results of the query
    int num_rows;         // num_rows is the number of rows returned by the query
    int num_cols;         // num_cols is the number of attributes returned by the query
};

#endif