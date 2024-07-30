/**
 * Preconditions: 
 * Load the database with 50 products.
 * Load each product with 10 change items. 
 * Load a particular product with 100 change items.
 * 
 * Process: 
 * Load relevant data.
 * Time the process of creating a type 1 report.
*/

#include "../include/product_queries.h"
#include "../include/issue_queries.h"
#include "../include/report_queries.h"
#include "../include/ui.h"
#include "../include/database_connection.h"
#include <sqlite3.h>

#include <cstdlib>
#include <string>
#include <ctime>

void load_data()
{
    srand(0);
    // Loading the database with 50 products
    for(int i = 0; i <= 50; i++) 
    {
        add_product_release_query("tester", "1.1.0", "2024-07-29");
    }

    // Loading each product with 10 change items
    for(int i = 0; i <= 10; i++)
    {
        int rand = (std::rand() % 2001) + 1;
        std::string rand_str = std::to_string(rand);
        add_change_item_query(rand_str, "tester", "1.1.1", "example desc");
    }

    // Load a particular product with 100 change items
    add_product_release_query("product1", "1.1.2", "2024-07-29");
    for (int i = 0; i <= 100; i++)
    {
        int rand = (std::rand() % 2001) + 1;
        std::string rand_str = std::to_string(rand);
        add_change_item_query(rand_str, "product1", "1.1.2", "example2 desc");
    }
}

int main()
{
    connect_db();
    // only load data once
    
    load_data();

    auto start = std::chrono::high_resolution_clock::now();

    display_report_1_query("product1");
   
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    disconnect_db();
    return 0;
}