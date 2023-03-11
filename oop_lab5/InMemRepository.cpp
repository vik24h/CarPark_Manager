//
// Created by Vik on 16/05/2022.
//

#include "InMemRepository.h"
#include <algorithm>

using namespace repository;

InMemory::InMemory() {
    this->stock = {};
    this->fav={};
}

vector<domain::Auto> InMemory::getallVehicles() {
    return this->stock;
}

vector<domain::Auto> InMemory::get_fav() {
    return this->fav;
}

void InMemory::add_to_stock(string model, string brand, int registration, int mileage, int price,
                                  domain::timetable charging, int range) {
    if (model == "" || brand == "" || registration == 0 || price == 0 || (charging.hour == 0 && charging.min == 0) ||
        range == 0)
        throw exception();
    else
        this->stock.emplace_back(domain::Auto(model, brand, registration, mileage, price, charging, range));

}

void
InMemory::remove_from_stock(string model, string brand, int registration, int mileage, int price, int range) {
    if (model == "" || brand == "" || registration == 0 || price == 0 || range == 0)
        throw exception();
    else
        std::remove_if(this->stock.begin(), this->stock.end(),
                  [model, brand, registration, mileage, price, range](domain::Auto vehicle) {
                      return vehicle.get_model() == model && vehicle.get_brand() == brand &&
                             vehicle.get_registration() == registration && vehicle.get_mileage() == mileage &&
                             vehicle.get_price() == price && vehicle.get_range() == range;

                  });
}

void InMemory::modify_stock(int id, string new_model, string new_brand, int new_registration, int new_mileage,
                            int new_price, domain::timetable new_charging, int new_range) {
    if (new_model == "" || new_brand == "" || new_registration == 0 || new_price == 0 ||
        (new_charging.hour == 0 && new_charging.min == 0) || new_range == 0)
        throw exception();
    else
        for (domain::Auto &vehicle: this->stock) {
            if (vehicle.get_id()==id) {
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
}

void InMemory::add_to_fav(int id) {
    bool found= false;
    string model,brand;
    int registration,mileage,price,range;
    domain::timetable charging;
    for(domain::Auto &vehicle: this->getallVehicles())
        if(vehicle.get_id()==id){
            found= true;
            model=vehicle.get_model();
            brand=vehicle.get_brand();
            registration=vehicle.get_registration();
            mileage=vehicle.get_mileage();
            price=vehicle.get_price();
            charging=vehicle.get_charging();
            range=vehicle.get_range();
        }
    if(found)
        this->fav.emplace_back(domain::Auto(model,brand,registration,mileage,price,charging,range));
}
