//
// Created by Vik on 28/04/2022.
//

#ifndef OOP_LAB5_CONTROLLER_H
#define OOP_LAB5_CONTROLLER_H

#include "InMemRepository.h"
#include "InFileRepository.h"
#include <memory>

namespace controller{
    class AutoController{
    private:
        shared_ptr<repository::InMemory> reposit_m;
        shared_ptr<repository::InFile> reposit_f;

    public:
        AutoController(shared_ptr<repository::InMemory> &reposit);

        AutoController(shared_ptr<repository::InFile> &reposit);

        repository::InMemory get_InMemory();

        repository::InFile get_InFile();

        vector<domain::Auto> list_specific_model_brand(int save_id, string model, string brand);

        vector<domain::Auto> list_by_registration(int save_id, int from, int to);

        vector<domain::Auto> list_by_mileage(int save_id, int from, int to);

        vector<domain::Auto> list_by_price_ascending(int save_id, int from, int to);

        void add_vehicle(int save_id, string model, string brand, int registration, int mileage, int price, domain::timetable charging, int range);

        void remove_vehicle(int save_id, string model, string brand, int registration, int mileage, int price, int range);

        void modify_vehicle(int save_id, int id, string new_model, string new_brand, int new_registration, int new_mileage, int new_price, domain::timetable new_charging, int new_range);

        void add_favourite(int save_id, int id);
    };

}

#endif //OOP_LAB5_CONTROLLER_H
