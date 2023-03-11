//
// Created by Vik on 28/04/2022.
//

#include "Controller.h"
#include <algorithm>

using namespace controller;
using namespace repository;

AutoController::AutoController(shared_ptr<repository::InMemory> &reposit) : reposit_m(reposit){}

AutoController::AutoController(shared_ptr<repository::InFile> &reposit) : reposit_f(reposit){}

repository::InMemory AutoController::get_InMemory() {
    return *this->reposit_m;
}

repository::InFile AutoController::get_InFile() {
    return *this->reposit_f;
}

vector<domain::Auto> AutoController::list_specific_model_brand(int save_id, string model, string brand) {
    vector<domain::Auto> filtered = {};
    if(save_id==1) {
        if (model.empty() && brand.empty()) {
            for (domain::Auto vehicle: this->reposit_m->getallVehicles())
                filtered.emplace_back(vehicle);
        } else {
            if (model.empty()) {
                for (domain::Auto vehicle: this->reposit_m->getallVehicles())  //auflisten nach model oder brand
                    if (vehicle.get_brand() == brand)
                        filtered.emplace_back(vehicle);
            } else {
                if (brand.empty()) {
                    for (domain::Auto vehicle: this->reposit_m->getallVehicles())
                        if (vehicle.get_model() == model)
                            filtered.emplace_back(vehicle);
                } else {
                    for (domain::Auto vehicle: this->reposit_m->getallVehicles())
                        if (vehicle.get_model() == model && vehicle.get_brand() == brand)
                            filtered.emplace_back(vehicle);
                }
            }
        }
    }
    if(save_id==2) {
        if (model.empty() && brand.empty()) {
            for (domain::Auto vehicle: this->reposit_f->getallVehicles())
                filtered.emplace_back(vehicle);
        } else {
            if (model.empty()) {
                for (domain::Auto vehicle: this->reposit_f->getallVehicles())  //auflisten nach model oder brand
                    if (vehicle.get_brand() == brand)
                        filtered.emplace_back(vehicle);
            } else {
                if (brand.empty()) {
                    for (domain::Auto vehicle: this->reposit_f->getallVehicles())
                        if (vehicle.get_model() == model)
                            filtered.emplace_back(vehicle);
                } else {
                    for (domain::Auto vehicle: this->reposit_f->getallVehicles())
                        if (vehicle.get_model() == model && vehicle.get_brand() == brand)
                            filtered.emplace_back(vehicle);
                }
            }
        }
    }
    return filtered;
}

vector<domain::Auto> AutoController::list_by_registration(int save_id, int from, int to) {
    vector<domain::Auto> filtered = {};
    if (from > to)
        throw exception();
    else {
        if(save_id==1) {
            for (domain::Auto vehicle: this->reposit_m->getallVehicles()) {
                if (vehicle.get_registration() >= from &&
                    vehicle.get_registration() <= to) {   //auflisten nach alter in einem Intervall sortiert
                    filtered.emplace_back(vehicle);
                }
            }
        }
        if(save_id==2) {
            for (domain::Auto vehicle: this->reposit_f->getallVehicles()) {
                if (vehicle.get_registration() >= from &&
                    vehicle.get_registration() <= to) {   //auflisten nach alter in einem Intervall sortiert
                    filtered.emplace_back(vehicle);
                }
            }
        }
    }
    sort(filtered.begin(), filtered.end(), [](domain::Auto &vehicle1, domain::Auto &vehicle2) {
        return vehicle1.get_registration() < vehicle2.get_registration();
    });
    return filtered;
}

vector<domain::Auto> AutoController::list_by_mileage(int save_id, int from, int to) {
    vector<domain::Auto> filtered = {};
    if (from > to)
        throw exception();
    else {
        if(save_id==1) {
            for (domain::Auto vehicle: this->reposit_m->getallVehicles()) {
                if (vehicle.get_mileage() >= from &&
                    vehicle.get_mileage() <= to) {    //auflisten nach kilometer in einem Intervall sortiert
                    filtered.emplace_back(vehicle);
                }
            }
        }
        if(save_id==2) {
            for (domain::Auto vehicle: this->reposit_f->getallVehicles()) {
                if (vehicle.get_mileage() >= from &&
                    vehicle.get_mileage() <= to) {    //auflisten nach kilometer in einem Intervall sortiert
                    filtered.emplace_back(vehicle);
                }
            }
        }
    }
    sort(filtered.begin(), filtered.end(), [](domain::Auto &vehicle1, domain::Auto &vehicle2) {
        return vehicle1.get_mileage() < vehicle2.get_mileage();
    });
    return filtered;
}

vector<domain::Auto> AutoController::list_by_price_ascending(int save_id, int from, int to) {
    vector<domain::Auto> filtered = {};
    if (from > to)
        throw exception();
    else {
        if(save_id==1) {
            for (domain::Auto vehicle: this->reposit_m->getallVehicles()) {
                if (vehicle.get_price() >= from && vehicle.get_price() <= to) {   //auflisten nach Preis aufsteigend
                    filtered.emplace_back(vehicle);
                }
            }
        }
        if(save_id==2) {
            for (domain::Auto vehicle: this->reposit_f->getallVehicles()) {
                if (vehicle.get_price() >= from && vehicle.get_price() <= to) {   //auflisten nach Preis aufsteigend
                    filtered.emplace_back(vehicle);
                }
            }
        }
    }
    std::sort(filtered.begin(), filtered.end(),
         [](domain::Auto &vehicle1, domain::Auto &vehicle2) { return vehicle1.get_price() < vehicle2.get_price(); });
    return filtered;
}

void AutoController::add_vehicle(int save_id, string model, string brand, int registration, int mileage, int price,
                                 domain::timetable charging, int range) {
    if(save_id==1)
        this->reposit_m->add_to_stock(model, brand, registration, mileage, price, charging, range);
    if(save_id==2)
        this->reposit_f->add_to_stock(model, brand, registration, mileage, price, charging, range);
}

void AutoController::remove_vehicle(int save_id, string model, string brand, int registration, int mileage, int price, int range) {
    if(save_id==1)
        this->reposit_m->remove_from_stock(model, brand, registration, mileage, price, range);
    if(save_id==2)
        this->reposit_f->remove_from_stock(model, brand, registration, mileage, price, range);
}

void AutoController::modify_vehicle(int save_id, int id, string new_model, string new_brand,
                                    int new_registration, int new_mileage, int new_price,
                                    domain::timetable new_charging, int new_range) {
    if(save_id==1)
        this->reposit_m->modify_stock(id, new_model, new_brand, new_registration, new_mileage, new_price, new_charging, new_range);
    if(save_id==2)
        this->reposit_f->modify_stock(id, new_model, new_brand, new_registration, new_mileage, new_price, new_charging, new_range);
}

void AutoController::add_favourite(int save_id, int id) {
    if(save_id==1)
        this->reposit_m->add_to_fav(id);
    if(save_id==2)
        this->reposit_f->add_to_fav(id);
}
