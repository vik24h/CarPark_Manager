//
// Created by Vik on 28/04/2022.
//

#ifndef OOP_LAB5_UI_H
#define OOP_LAB5_UI_H

#include "Controller.h"

namespace ui{
    class AutoUI{
    private:
        shared_ptr<controller::AutoController> control;
    public:
        AutoUI(shared_ptr<controller::AutoController> &control);

        controller::AutoController get_control();

        void manager_menu(int save_id);

        void kunde_menu(int save_id);

    };
}

#endif //OOP_LAB5_UI_H
