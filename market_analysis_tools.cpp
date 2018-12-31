#include <vector>
#include <iostream>
#include "market_analysis_tools.h"

int get_transaction_count_with_products(sqlite::sqlite &db, std::string prod_a, std::string prod_b) {
    std::shared_ptr<sqlite::statement> stmt = db.get_statement();

    stmt->set_sql("SELECT COUNT(*) "
                  "FROM "
                  "    (SELECT * FROM transactions WHERE product=\"" + prod_a + "\") as l "
                  "  INNER JOIN "
                  "    (SELECT * FROM transactions WHERE product=\"" + prod_b + "\") as r "
                  "  ON l.transaction_id = r.transaction_id");
    /*
    stmt->set_sql("SELECT COUNT(*) "
                  "FROM "
                  "    (SELECT * FROM transactions WHERE product=?1) as l "
                  "  INNER JOIN "
                  "    (SELECT * FROM transactions WHERE product=?2) as r "
                  "  ON l.transaction_id = r.transaction_id");
    */

    stmt->prepare();
    //stmt->bind(1, prod_a);
    //stmt->bind(2, prod_b);
    stmt->step();

    return stmt->get_int(0);
}

int get_transaction_count_with_products(sqlite::sqlite &sqlite, std::string prod_a, std::string prod_b, std::string prod_c){
    std::shared_ptr<sqlite::statement> stmt = sqlite.get_statement();

    stmt->set_sql("SELECT COUNT(*) "
                  "  FROM "
                  "    (SELECT * FROM transactions WHERE product=\"" + prod_a + "\") as l "
                  "  INNER JOIN "
                  "    (SELECT * FROM transactions WHERE product=\"" + prod_b + "\") as m "
                  "    ON l.transaction_id = m.transaction_id"
                  "  INNER JOIN "
                  "    (SELECT * FROM transactions WHERE product=\"" + prod_c + "\") as r "
                  "    ON l.transaction_id = r.transaction_id");
    stmt->prepare();
    stmt->step();

    return stmt->get_int(0);
}

int get_transaction_count_with_product(sqlite::sqlite &db, std::string product) {
    std::shared_ptr<sqlite::statement> stmt = db.get_statement();
    stmt->set_sql("select COUNT(*) FROM( SELECT DISTINCT transaction_id FROM transactions WHERE product = ?1 )");
    stmt->prepare();
    stmt->bind(1, product);
    stmt->step();

    return stmt->get_int(0);
}

int get_transaction_count(sqlite::sqlite &db) {
    std::shared_ptr<sqlite::statement> stmt = db.get_statement();
    stmt->set_sql("SELECT COUNT(*) FROM ( SELECT DISTINCT transaction_id FROM transactions )");
    stmt->prepare();
    stmt->step();

    return stmt->get_int(0);
}

void get_all_products(sqlite::sqlite &db, std::vector<std::__cxx11::string> &target_list){
    std::shared_ptr<sqlite::statement> stmt = db.get_statement();
    stmt->set_sql("SELECT DISTINCT product FROM transactions");
    stmt->prepare();

    while(stmt->step())
        target_list.push_back(stmt->get_text(0));
}