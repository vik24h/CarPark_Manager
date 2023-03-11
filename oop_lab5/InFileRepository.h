//
// Created by Vik on 16/05/2022.
//

#ifndef OOP_LAB5_INFILEREPOSITORY_H
#define OOP_LAB5_INFILEREPOSITORY_H

#include "Domain.h"
#include "Repository.h"

namespace repository{

    class InFile : public AutoRepository {
    private:
        vector<domain::Auto> stock;
        vector<domain::Auto> fav;

    public:

        InFile();

        vector<domain::Auto> getallVehicles();

        vector<domain::Auto> get_fav();

        void add_to_stock(string model, string brand, int registration, int mileage, int price, domain::timetable charging,
                          int range);

        void remove_from_stock(string model, string brand, int registration, int mileage, int price, int range);

        void modify_stock(int id, string new_model, string new_brand, int new_registration, int new_mileage,
                          int new_price, domain::timetable new_charging, int new_range);

        void add_to_fav(int id);
    };
}

#endif //OOP_LAB5_INFILEREPOSITORY_H
