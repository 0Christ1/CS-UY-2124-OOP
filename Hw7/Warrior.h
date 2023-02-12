//
// Sagar Risal
// Header File for Warrior
// Warrior.h
//

#ifndef HW7_WARRIOR_H
#define HW7_WARRIOR_H

#include "Protector.h"

namespace WarriorCraft {

// Parent class of Archer and Swordsman
    class Warrior : public Protector {
    protected:
        Warrior(const std::string &name, double strength);

        void display() const override;
    };
}

#endif //HW7_WARRIOR_H
