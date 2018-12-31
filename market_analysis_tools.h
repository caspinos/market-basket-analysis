#ifndef MARKET_ANALYSIS_TOOLS_H
#define MARKET_ANALYSIS_TOOLS_H

#include <string>
#include <vector>
#include "libsqlite.hpp"

int get_transaction_count_with_products(sqlite::sqlite &db, std::string prod_a, std::string prod_b);
int get_transaction_count_with_products(sqlite::sqlite &sqlite, std::string prod_a, std::string prod_b, std::string prod_c);
int get_transaction_count_with_product(sqlite::sqlite &db, std::string product);
int get_transaction_count(sqlite::sqlite &sqlite);
void get_all_products(sqlite::sqlite &db, std::vector<std::string> &target_list);

#endif //MARKET_ANALYSIS_TOOLS_H
