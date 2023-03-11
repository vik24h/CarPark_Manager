//
// Created by Vik on 28/04/2022.
//

#ifndef OOP_LAB5_REPOSITORY_H
#define OOP_LAB5_REPOSITORY_H

# include "Domain.h"
#include <vector>

using domain::Auto;
using namespace domain;

namespace repository {
    class AutoRepository {

    public:

        virtual vector<domain::Auto> getallVehicles()=0;

        virtual vector<domain::Auto> get_fav()=0;

        virtual void
        add_to_stock(string model, string brand, int registration, int mileage, int price, domain::timetable charging,
                     int range)=0;

        virtual void remove_from_stock(string model, string brand, int registration, int mileage, int price, int range)=0;

        virtual void
        modify_stock(int id, string new_model, string new_brand, int new_registration, int new_mileage,
                     int new_price, domain::timetable new_charging, int new_range)=0;

        virtual void add_to_fav(int id)=0;
    };

}

#endif //OOP_LAB5_REPOSITORY_H
