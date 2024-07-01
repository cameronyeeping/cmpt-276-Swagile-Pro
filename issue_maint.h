#ifndef ISSUE_MAINT_H
#define ISSUE_MAINT_H
#include <string>

void create_change_request(std::string user_name, std::string release_id, std::string date, std::string priority);
void query_change_item();
void create_change_item();
void update_change_item();
#endif