//
// Created by Vik on 28/04/2022.
//

#include "Domain.h"
#include <iostream>

using namespace domain;

Auto::Auto(string model, string brand, int registration, int mileage, int price, timetable charging, int range) {
    this->id = count;
    this->model = model;
    this->brand = brand;
    this->registration = registration;
    this->mileage = mileage;
    this->price = price;
    this->charging = charging;
    this->range = range;
    count++;
}

int Auto::get_id() {
    return this->id;
}

string Auto::get_model() {
    return this->model;
}

void Auto::set_model(string model) {
    this->model = model;
}

string Auto::get_brand() {
    return this->brand;
}

void Auto::set_brand(string brand) {
    this->brand = brand;
}

int Auto::get_registration() {
    return this->registration;
}

void Auto::set_registration(int registration) {
    this->registration = registration;
}

int Auto::get_mileage() {
    return this->mileage;
}

void Auto::set_mileage(int mileage) {
    this->mileage = mileage;
}

int Auto::get_price() {
    return this->price;
}

void Auto::set_price(int price) {
    this->price = price;
}

timetable Auto::get_charging() {
    return this->charging;
}

void Auto::set_charging(timetable charging) {
    this->charging.hour = charging.hour;
    this->charging.min = charging.min;
}

int Auto::get_range() {
    return this->range;
}

void Auto::set_range(int range) {
    this->range = range;
}

void Auto::print_auto() {
    cout << this->get_model() << " " << this->get_brand() << " " << this->get_registration() << " "
         << this->get_mileage() << " " << this->get_price() << " " << this->get_charging().hour << "/"
         << this->get_charging().min << " " << this->get_range() << endl;
}