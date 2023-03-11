//
// Created by Vik on 28/04/2022.
//

#include "UI.h"
#include <iostream>
#include <memory>

using namespace std;
using namespace ui;
using namespace controller;

AutoUI::AutoUI(shared_ptr<controller::AutoController> &control) : control(control){}

controller::AutoController AutoUI::get_control() {
    return *this->control;
}

void AutoUI::manager_menu(int save_id) {
    cout << endl;
    cout << "    ***___ Vericu' Automobile ___***" << endl;
    cout << "              *Manager Menu*" << endl;
    cout << "     1.Add vehicle" << endl;
    cout << "     2.Remove vehicle" << endl;
    cout << "     3.Modify vehicle" << endl;
    cout << "     4.List specific model and brand" << endl;
    cout << "     5.List by registration" << endl;
    cout << "     6.List by mileage" << endl;
    cout << "     7.List by price ascending" << endl;
    cout << "     0 -> Exit" << endl;
    cout << endl;
    cout << "     Option:" << endl;

    int input;
    cin >> input;

    vector<domain::Auto> filtered;
    string model, brand, new_model, new_brand;
    int registration, mileage, price, range, new_registration, new_mileage, new_price, new_range, from, to, id;
    domain::timetable charging, new_charging;

    switch (input) {

        case 1:
            cout << "Give input model:" << endl;
            cin >> model;
            cout << "Give input brand:" << endl;
            cin >> brand;
            cout << "Give input registration:" << endl;
            cin >> registration;
            cout << "Give input mileage:" << endl;
            cin >> mileage;
            cout << "Give input price" << endl;
            cin >> price;
            cout << "Give input charging time (hour/minutes):" << endl;
            cin >> charging.hour;
            cin >> charging.min;
            cout << "Give input range" << endl;
            cin >> range;
            try {
                this->get_control().add_vehicle(save_id, model, brand, registration, mileage, price, charging, range);
            } catch (exception &) {
                cout << "Invalid input! Please try again";
            }
            manager_menu(save_id);

        case 2:
            cout << "Give input model:" << endl;
            cin >> model;
            cout << "Give input brand:" << endl;
            cin >> brand;
            cout << "Give input registration:" << endl;
            cin >> registration;
            cout << "Give input mileage:" << endl;
            cin >> mileage;
            cout << "Give input price" << endl;
            cin >> price;
            cout << "Give input range" << endl;
            cin >> range;
            try {
                this->get_control().remove_vehicle(save_id, model, brand, registration, mileage, price, range);
            } catch (exception &) {
                cout << "Invalid input!Please try again";
            }
            manager_menu(save_id);

        case 3:
            cout << "!CAR TO BE MODIFIED!" << endl;
            cout << "Give input id:" << endl;
            cin >> id;

            cout << "!NEW INFO (GIVE SAME INPUT IF NO CHANGE IS NEEDED)" << endl;
            cout << "Give input model:" << endl;
            cin >> new_model;
            cout << "Give input brand:" << endl;
            cin >> new_brand;
            cout << "Give input registration:" << endl;
            cin >> new_registration;
            cout << "Give input mileage:" << endl;
            cin >> new_mileage;
            cout << "Give input price" << endl;
            cin >> new_price;
            cout << "Give input charging time (hour/minutes):" << endl;
            cin >> new_charging.hour;
            cin >> new_charging.min;
            cout << "Give input range" << endl;
            cin >> new_range;
            try {
                this->get_control().modify_vehicle(save_id, id, new_model,
                                              new_brand, new_registration, new_mileage, new_price, new_charging,
                                              new_range);
            } catch (exception &) {
                cout << "Invalid input!Please try again";
            }
            manager_menu(save_id);

        case 4:
            cout << "Give specific model or brand (type *all* if there is no specific model or brand)" << endl;
            cout << "Model:" << endl;
            cin >> model;
            cout << "Brand:" << endl;
            cin >> brand;
            if (model == "all" || model == "*all*")
                model = "";
            if (brand == "all" || brand == "*all*")
                brand = "";
            filtered = this->get_control().list_specific_model_brand(save_id, model, brand);
            cout<<"Model , Brand , Registration , Mileage , Price , Charging, Range";
            for (domain::Auto vehicle: filtered)
                vehicle.print_auto();
            cout << endl;
            manager_menu(save_id);

        case 5:
            cout << "Give input interval (from->to):" << endl;
            cout << "From:" << endl;
            cin >> from;
            cout << "To:" << endl;
            cin >> to;
            try {
                filtered=this->get_control().list_by_registration(save_id, from, to);
            } catch (exception &) {
                cout << "Invalid input!Please try again";
            }
            cout<<"Model , Brand , Registration , Mileage , Price , Charging, Range";
            for (domain::Auto vehicle: filtered)
                vehicle.print_auto();
            cout << endl;
            manager_menu(save_id);

        case 6:
            cout << "Give input interval (from->to):" << endl;
            cout << "From:" << endl;
            cin >> from;
            cout << "To:" << endl;
            cin >> to;
            try {
                filtered=this->get_control().list_by_mileage(save_id, from, to);
            } catch (exception &) {
                cout << "Invalid input!Please try again";
            }
            cout<<"Model , Brand , Registration , Mileage , Price , Charging, Range";
            for (domain::Auto vehicle: filtered)
                vehicle.print_auto();
            cout << endl;
            manager_menu(save_id);

        case 7:
            cout << "Give input interval (from->to):" << endl;
            cout << "From:" << endl;
            cin >> from;
            cout << "To:" << endl;
            cin >> to;
            try {
                filtered=this->get_control().list_by_price_ascending(save_id, from, to);
            } catch (exception &) {
                cout << "Invalid input!Please try again";
            }
            cout<<"Model , Brand , Registration , Mileage , Price , Charging, Range";
            for (domain::Auto vehicle: filtered)
                vehicle.print_auto();
            cout << endl;
            manager_menu(save_id);

        default:
            exit(0);

    }
}

void AutoUI::kunde_menu(int save_id) {
    cout << endl;
    cout << "    ***___ Vericu' Automobile ___***" << endl;
    cout << "              *Kunde Menu*" << endl;
    cout << "     1.List specific model and brand" << endl;
    cout << "     2.List by registration" << endl;
    cout << "     3.List by mileage" << endl;
    cout << "     4.List by price ascending" << endl;
    cout << "     5.Add to favourite" << endl;
    cout << "     0 -> Exit" << endl;
    cout << endl;
    cout << "     Option:" << endl;

    int input;
    cin >> input;

    vector<domain::Auto> filtered;

    string model, brand;
    int registration, mileage, price, range, from, to, id;
    domain::timetable charging;

    switch (input) {

        case 1:
            cout << "Give specific model or brand (type *all* if there is no specific model or brand)" << endl;
            cout << "Model:" << endl;
            cin >> model;
            cout << "Brand:" << endl;
            cin >> brand;
            if (model == "all" || model == "*all*")
                model = "";
            if (brand == "all" || brand == "*all*")
                brand = "";
            filtered = this->get_control().list_specific_model_brand(save_id, model, brand);
            for (domain::Auto vehicle: filtered)
                vehicle.print_auto();
            cout << endl;
            kunde_menu(save_id);

        case 2:
            cout << "Give input interval (from->to):" << endl;
            cout << "From:" << endl;
            cin >> from;
            cout << "To:" << endl;
            cin >> to;
            try {
                filtered=this->get_control().list_by_registration(save_id, from, to);
            } catch (exception &) {
                cout << "Invalid input!Please try again";
            }
            for (domain::Auto vehicle: filtered)
                vehicle.print_auto();
            cout << endl;
            kunde_menu(save_id);

        case 3:
            cout << "Give input interval (from->to):" << endl;
            cout << "From:" << endl;
            cin >> from;
            cout << "To:" << endl;
            cin >> to;
            try {
                filtered=this->get_control().list_by_mileage(save_id, from, to);
            } catch (exception &) {
                cout << "Invalid input!Please try again";
            }
            for (domain::Auto vehicle: filtered)
                vehicle.print_auto();
            cout << endl;
            kunde_menu(save_id);

        case 4:
            cout << "Give input interval (from->to):" << endl;
            cout << "From:" << endl;
            cin >> from;
            cout << "To:" << endl;
            cin >> to;
            try {
                filtered=this->get_control().list_by_price_ascending(save_id, from, to);
            } catch (exception &) {
                cout << "Invalid input!Please try again";
            }
            for (domain::Auto vehicle: filtered)
                vehicle.print_auto();
            cout << endl;
            kunde_menu(save_id);

        case 5:
            cout << "Give input id:" << endl;
            cin >> id;
            try {
                this->get_control().add_favourite(save_id, id);
            } catch (exception &) {
                cout << "Invalid input!Please try again";
            }
            if(save_id==1) {
                for (domain::Auto vehicle: this->get_control().get_InMemory().get_fav())
                    vehicle.print_auto();
            }
            if(save_id==2) {
                for (domain::Auto vehicle: this->get_control().get_InFile().get_fav())
                    vehicle.print_auto();
            }
            cout << endl;
            kunde_menu(save_id);

        default:
            exit(0);

    }
}
