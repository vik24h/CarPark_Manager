#include <iostream>
#include <fstream>
#include "UI.h"
#include "test.cppT"

using namespace ui;
using namespace controller;

int domain::Auto::count=0;

int main() {

    using namespace main_test;
    main_test::main();

    shared_ptr<repository::InMemory> repos_m = make_shared<repository::InMemory>();
    shared_ptr<AutoController> control_m = make_shared<AutoController>(repos_m);     //Repository, Controller und UI generieren
    AutoUI ui_m=AutoUI(control_m);

    shared_ptr<repository::InFile> repos_f = make_shared<repository::InFile>();
    shared_ptr<AutoController> control_f = make_shared<AutoController>(repos_f);     //Repository, Controller und UI generieren
    AutoUI ui_f=AutoUI(control_f);

    repos_m->add_to_stock("ID3", "VW", 2020, 25000, 40000, {1, 10}, 300);
    repos_m->add_to_stock("ID4", "VW", 2019, 50000, 50000, {1, 30}, 350);
    repos_m->add_to_stock("GrandSphere", "Audi", 2022, 1000, 100000, {1, 0}, 500);
    repos_m->add_to_stock("Etron GT", "Audi", 2020, 70000, 80000, {1, 15}, 400);
    repos_m->add_to_stock("Model X", "Tesla", 2017, 100000, 45000, {1, 40}, 380);  //10 Autos einfugen
    repos_m->add_to_stock("Model S", "Tesla", 2015, 150000, 20000, {1, 35}, 420);
    repos_m->add_to_stock("Model Y", "Tesla", 2018, 80000, 38000, {1, 5}, 230);
    repos_m->add_to_stock("Enyaq", "Skoda", 2021, 30000, 47000, {1, 20}, 310);
    repos_m->add_to_stock("Mustang Mach-E", "Ford", 2020, 130000, 57000, {1, 45}, 360);
    repos_m->add_to_stock("EQS", "Mercedes-Benz", 2022, 15000, 120000, {0, 59}, 550);

/*
    repos_f->add_to_stock("ID3", "VW", 2020, 25000, 40000, {1, 10}, 300);
    repos_f->add_to_stock("ID4", "VW", 2019, 50000, 50000, {1, 30}, 350);
    repos_f->add_to_stock("GrandSphere", "Audi", 2022, 1000, 100000, {1, 0}, 500);
    repos_f->add_to_stock("Etron GT", "Audi", 2020, 70000, 80000, {1, 15}, 400);
    repos_f->add_to_stock("Model X", "Tesla", 2017, 100000, 45000, {1, 40}, 380);  //10 Autos einfugen
    repos_f->add_to_stock("Model S", "Tesla", 2015, 150000, 20000, {1, 35}, 420);
    repos_f->add_to_stock("Model Y", "Tesla", 2018, 80000, 38000, {1, 5}, 230);
    repos_f->add_to_stock("Enyaq", "Skoda", 2021, 30000, 47000, {1, 20}, 310);
    repos_f->add_to_stock("Mustang Mach-E", "Ford", 2020, 130000, 57000, {1, 45}, 360);
    repos_f->add_to_stock("EQS", "Mercedes-Benz", 2022, 15000, 120000, {0, 59}, 550);
*/

    int save_id;
    cout<<"Choose saving type:"<<endl;
    cout<<"Press 1 for in-memory"<<endl;
    cout<<"Press 2 for in-file"<<endl;
    cin>>save_id;
    cout<<endl;


    string user[] = {"Vik", "But", "Coldea"};
    string usr;
    int passwd[] = {210, 211, 111};
    int pswd;
    int role[] = {1, 0, 0};
    int rle = -1;

    cout << "    ***___ Vericu' Automobile ___***" << endl;
    cout << "                *Login*" << endl;
    cout << "User:" << endl;
    cin >> usr;
    cout << "Password:" << endl;
    cin >> pswd;

    for (int i = 0; i < 3; i++)
        if (user[i] == usr && passwd[i] == pswd)     //Rolle de Benutzers auswahlen via Login
            rle = role[i];

    if(save_id==1) {
        if (rle == 1)
            ui_m.manager_menu(save_id);
        else if (rle ==0)          //Programm (Interaktion mit dem Programm) startet nachdem alle Testfunktionen durchgefuhrt wurden und die 10 Produkte eingefugt wurden und die Rolle ausgewahlt wurde
            ui_m.kunde_menu(save_id);
        else
            cout << "Incorrect username or password. Try again!" << endl;
    }

    if(save_id==2) {
        if (rle == 1)
            ui_f.manager_menu(save_id);
        else if (rle ==0)          //Programm (Interaktion mit dem Programm) startet nachdem alle Testfunktionen durchgefuhrt wurden und die 10 Produkte eingefugt wurden und die Rolle ausgewahlt wurde
            ui_f.kunde_menu(save_id);
        else
            cout << "Incorrect username or password. Try again!" << endl;
    }

    return 0;
}