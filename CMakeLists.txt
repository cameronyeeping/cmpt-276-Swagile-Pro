cmake_minimum_required(VERSION 3.10)

# Project name
project(Swagile_Pro
        VERSION 1.0
        DESCRIPTION "Swagile Pro: Issue tracking software")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(include)
# Add the executable
add_executable(Swagile_Pro
    src/create_report.cpp
    src/database_connection.cpp
    src/globals.cpp
    src/main.cpp
    src/product_maint.cpp
    src/product_queries.cpp
    src/ui.cpp
    src/user_maint.cpp
    src/user_queries.cpp
    src/report_queries.cpp
)

# Link the SQLite3 library
find_package(SQLite3 REQUIRED)
if(SQLite3_FOUND)
    target_include_directories(Swagile_Pro PRIVATE ${SQLite3_INCLUDE_DIRS})
    target_link_libraries(Swagile_Pro PRIVATE ${SQLite3_LIBRARIES})
endif()
