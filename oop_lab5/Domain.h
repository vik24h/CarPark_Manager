//
// Created by Vik on 28/04/2022.
//

#ifndef OOP_LAB5_DOMAIN_H
#define OOP_LAB5_DOMAIN_H

#include <string>

using namespace std;

namespace domain {

    struct timetable {
        int hour;
        int min;
    };

    class Auto {
    private:
        static int count;
        int id;
        string model;
        string brand;
        int registration;
        int mileage;
        int price;
        timetable charging;
        int range;

    public:
        Auto(string model, string brand, int registration, int mileage, int price, timetable charging, int range);

        int get_id();

        string get_model();

        void set_model(string model);

        string get_brand();

        void set_brand(string brand);

        int get_registration();

        void set_registration(int registration);

        int get_mileage();

        void set_mileage(int mileage);

        int get_price();

        void set_price(int price);

        timetable get_charging();

        void set_charging(timetable charging);

        int get_range();

        void set_range(int range);

        void print_auto();
    };

}

#endif //OOP_LAB5_DOMAIN_H
