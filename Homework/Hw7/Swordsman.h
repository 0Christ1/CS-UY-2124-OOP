//
// Sagar Risal
// Header File for Swordsman
// Swordsman.h
//

#ifndef HW7_SWORDSMAN_H
#define HW7_SWORDSMAN_H

#include "Warrior.h"

namespace WarriorCraft {

    class Swordsman : public Warrior {
    public:
        Swordsman(const std::string &name, double strength);

    protected:
        void display() const override;
    };

}

#endif //HW7_SWORDSMAN_H
