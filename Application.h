#ifndef TEST_APPLICATION_H
#define TEST_APPLICATION_H

#include <string>
#include <vector>

using namespace std;

class Application{

private:
    string db_file_path = "/home/darek/dane/Nextcloud/Studia/statystyka/projekt/database/bakery.db";
    string output_file_path = "out.csv";
    double minimum_support = 0.005;
    double minimum_confidence = 0.01;
    double minimum_corelation = 0.01;
    bool enable_2_to_1_analysis = false; // not tested!!!

    vector<string> product_list;

private:
    void pause();
    void calculate();
    void menu();

public:
    void start();


};

#endif //TEST_APPLICATION_H
