#include <iostream>
#include <fstream>
#include <iomanip>

#include "libsqlite.hpp"
#include "Application.h"
#include "market_analysis_tools.h"




void Application::calculate() {
    try {
        sqlite::sqlite db(db_file_path);
        ofstream output_file(output_file_path, (ios::out | ios::trunc) );
        output_file.setf( ios::fixed );

        if(output_file.bad()){
            throw std::runtime_error("Nie mozna otworzyc pliku wyjsciowego");
        }

        /* fill product list */
        get_all_products(db, product_list);
        int transaction_count = get_transaction_count(db);

        cout << "liczba produktow: " << product_list.size() << endl;
        cout << "liczba transakcji: " << transaction_count << endl;


        // Wypisanie nagłówka pliku wyjściowego
        output_file << "Poprzednik;Nastepnik;Wsparcie;Zaufanie;Przyrost;Korelacja" << endl;


        for(string a : product_list){
            cout << "."; cout.flush();

            for(string b : product_list){

                if(a == b)
                    continue;

                int transactions_with_a = get_transaction_count_with_product(db, a);
                int transactions_with_b = get_transaction_count_with_product(db, b);
                int transactions_with_a_and_b = get_transaction_count_with_products(db, a, b);

                // wsparcie
                double support = (double) transactions_with_a_and_b / transaction_count;

                // zaufanie
                double confidence = (double) transactions_with_a_and_b / transactions_with_a;

                // przyrost
                double lift = (double) transactions_with_a_and_b /
                              ( transactions_with_a * transactions_with_b );

                // korelacja
                double corelation = support / confidence;

                if(support >= minimum_support && confidence >= minimum_confidence && corelation >= minimum_corelation){
                    output_file
                            << a << ";"
                            << b << ";"
                            << setprecision(5) << support << ";"
                            << setprecision(5) << confidence << ";"
                            << setprecision(5) << lift << ";"
                            << setprecision(5) << corelation << ";"
                            << setprecision(5) << endl;
                } else {
                    continue;
                }

                if(!enable_2_to_1_analysis)
                    continue;

                for(string c : product_list){
                    if(a == c || b == c)
                        continue;

                    int transactions_with_c = get_transaction_count_with_product(db, c);
                    int transactions_with_a_b_c = get_transaction_count_with_products(db, a, b, c);

                    // wsparcie
                    support = (double) transactions_with_a_b_c / transaction_count;

                    // zaufanie
                    confidence = (double) transactions_with_a_b_c / transactions_with_c;

                    // przyrost
                    lift = (double) transactions_with_a_b_c /
                                  ( transactions_with_a_and_b * transactions_with_c );

                    // korelacja
                    corelation = support / confidence;

                    if(support >= minimum_support && confidence >= minimum_confidence && corelation >= minimum_corelation){
                        output_file
                                << a << "+" << b << ";"
                                << c << ";"
                                << setprecision(5) << support << ";"
                                << setprecision(5) << confidence << ";"
                                << setprecision(5) << lift << ";"
                                << setprecision(5) << corelation << ";"
                                << setprecision(5) << endl;
                    }
                }
            }
        }
        cout << endl;



        if(output_file.bad()){
            throw std::runtime_error("Wystapil blad w czasie zapisu do pliku");
        }

        output_file.close();

    } catch(sqlite::exception &e) {
        cout << "Blad obslugi bazy danych" << endl;
        std::cerr << e.what() << std::endl;
    } catch(std::runtime_error &e){
        cout << "Blad obslugi plikow" << endl;
        std::cerr << e.what() << std::endl;
    }
}

void Application::start() {

    menu();

}

void Application::menu() {

    cout    << endl
            << "######################################" << endl
            << "###                                ###" << endl
            << "###   Analiza koszykowa  v0.1      ###" << endl
            << "###                                ###" << endl
            << "###   Autorzy:                     ###" << endl
            << "###     Dariusz Hatala             ###" << endl
            << "###     Oxana Danilova             ###" << endl
            << "###                                ###" << endl
            << "######################################" << endl
            << endl;

    bool exit = false;
    int choice;

    while(!exit){

        cout << "Konfiguracja:" << endl
             << " baza danych: " << this->db_file_path << endl
             << " plik wynikowy: " << this->output_file_path << endl
             << " min. zaufanie: " << minimum_confidence << endl
             << " min. wsparcie: " << minimum_support << endl
             << " min. korelacja: " << minimum_corelation << endl
             << endl;

        cout << "Menu: " << endl
             << " 1. Uruchomienie analizy" << endl
             << " 2. Zmiana nazwy pliku wynikowego" << endl
             << " 3. Zmiana pliku bazy danych" << endl
             << " 4. Zmiana min. zaufania" << endl
             << " 5. Zmiana min. wsparcia" << endl
             << " 6. Zmiana min. korelacji" << endl
             << " 0. Wyjscie" << endl;

        cout << "Wybor: ";

        cin >> choice;

        switch(choice){
            case 0: // Wyjscie
                exit = true;
                break;

            case 1: // Uruchomienie analizy
                cout << "Uruchamianie analizy" << endl;

                calculate();

                cout << "Gotowe." << endl
                     << "Plik wynikowy: " << this->output_file_path << endl;
                pause();
                exit = true;
                break;

            case 2: // Zmiana nazwy pliku wynikowego
                cout << "Podaj nowa nazwe: ";
                cin >> output_file_path;
                cout << endl;

                break;

            case 3: // Zmiana pliku bazy danych
                cout << "Podaj nowa sciezke: ";
                cin >> db_file_path;
                cout << endl;

                break;

            case 4: // Zmiana min. zaufania
                cout << "Podaj nowa wartosc: ";
                cin >> minimum_confidence;
                cout << endl;

                break;

            case 5: // Zmiana min. wsparcia
                cout << "Podaj nowa wartosc: ";
                cin >> minimum_support;
                cout << endl;

                break;

            case 6: // Zmiana min. korelacji
                cout << "Podaj nowa wartosc: ";
                cin >> minimum_corelation;
                cout << endl;

                break;

            default:
                cout << "Zly wybor." << endl;
                pause();
        }//switch


    }//while

}

void Application::pause() {
    cin.clear();
    cin.get();
    cin.get();
}
