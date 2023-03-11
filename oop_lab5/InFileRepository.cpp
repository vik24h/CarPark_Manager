//
// Created by Vik on 16/05/2022.
//

#include "InFileRepository.h"
#include <fstream>
#include <algorithm>

using namespace repository;

InFile::InFile() {
    this->stock = {};
    this->fav = {};
}

vector<domain::Auto> InFile::getallVehicles() {
    return this->stock;
}

vector<domain::Auto> InFile::get_fav() {
    return this->fav;
}

void InFile::add_to_stock(string model, string brand, int registration, int mileage, int price,
                          domain::timetable charging, int range) {
    if (model == "" || brand == "" || registration == 0 || price == 0 || (charging.hour == 0 && charging.min == 0) ||
        range == 0)
        throw exception();
    else {
        this->stock.emplace_back(domain::Auto(model, brand, registration, mileage, price, charging, range));
        ofstream fo;
        fo.open("repository.txt");
        fo.clear();
        for (domain::Auto vehicle: this->stock)
            fo << vehicle.get_model() << "," << vehicle.get_brand() << "," << vehicle.get_registration() << ","
               << vehicle.get_mileage() << "," << vehicle.get_price() << "," << vehicle.get_charging().hour << "/"
               << vehicle.get_charging().min << "," << vehicle.get_range() << endl;
        fo.close();
    }

}

void
InFile::remove_from_stock(string model, string brand, int registration, int mileage, int price, int range) {
    if (model == "" || brand == "" || registration == 0 || price == 0 || range == 0)
        throw exception();
    else {
        std::remove_if(this->stock.begin(), this->stock.end(),
                       [model, brand, registration, mileage, price, range](domain::Auto vehicle) {
                           return vehicle.get_model() == model && vehicle.get_brand() == brand &&
                                  vehicle.get_registration() == registration && vehicle.get_mileage() == mileage &&
                                  vehicle.get_price() == price && vehicle.get_range() == range;

                       });
        ofstream fo;
        fo.open("repository.txt");
        fo.clear();
        for (domain::Auto vehicle: this->stock)
            fo << vehicle.get_model() << "," << vehicle.get_brand() << "," << vehicle.get_registration() << ","
               << vehicle.get_mileage() << "," << vehicle.get_price() << "," << vehicle.get_charging().hour << "/"
               << vehicle.get_charging().min << "," << vehicle.get_range() << endl;
        fo.close();
    }
}

void InFile::modify_stock(int id, string new_model, string new_brand, int new_registration, int new_mileage,
                          int new_price, domain::timetable new_charging, int new_range) {
    if (new_model == "" || new_brand == "" || new_registration == 0 || new_price == 0 ||
        (new_charging.hour == 0 && new_charging.min == 0) || new_range == 0)
        throw exception();
    else {
        for (domain::Auto &vehicle: this->stock) {
            if (vehicle.get_id() == id) {
                vehicle.set_model(new_model);
                vehicle.set_brand(new_brand);
                vehicle.set_registration(new_registration);
                vehicle.set_mileage(new_mileage);
                vehicle.set_price(new_price);
                vehicle.set_charging(new_charging);
                vehicle.set_range(new_range);
                break;
            }
        }

        ofstream fo;
        fo.open("repository.txt");
        fo.clear();
        for (domain::Auto vehicle: this->stock)
            fo << vehicle.get_model() << "," << vehicle.get_brand() << "," << vehicle.get_registration() << ","
               << vehicle.get_mileage() << "," << vehicle.get_price() << "," << vehicle.get_charging().hour << "/"
               << vehicle.get_charging().min << "," << vehicle.get_range() << endl;
        fo.close();

    }
}

void InFile::add_to_fav(int id) {
    bool found = false;
    string model, brand;
    int registration, mileage, price, range;
    domain::timetable charging;
    for (domain::Auto &vehicle: this->getallVehicles())
        if (vehicle.get_id() == id) {
            found = true;
            model = vehicle.get_model();
            brand = vehicle.get_brand();
            registration = vehicle.get_registration();
            mileage = vehicle.get_mileage();
            price = vehicle.get_price();
            charging = vehicle.get_charging();
            range = vehicle.get_range();
        }
    if (found) {
        this->fav.emplace_back(domain::Auto(model, brand, registration, mileage, price, charging, range));
        ofstream fo;
        fo.open("fav.txt");
        fo.clear();
        for (domain::Auto vehicle: this->fav)
            fo << vehicle.get_model() << "," << vehicle.get_brand() << ","
               << vehicle.get_registration() << "," << vehicle.get_mileage() << "," << vehicle.get_price() << ","
               << vehicle.get_charging().hour << "/" << vehicle.get_charging().min << "," << vehicle.get_range()
               << endl;
        fo.close();
    }
}
