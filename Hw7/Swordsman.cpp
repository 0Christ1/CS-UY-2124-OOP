//
// Sagar Risal
// Implementation File for Swordsman
// Swordsman.cpp
//

#include <iostream>
using namespace std;

#include "Swordsman.h"

namespace WarriorCraft {

//      Swordsman Class Implementation (Child of Warrior Class)

    Swordsman::Swordsman(const string &name, double strength) : Warrior(name,
                                                                        strength) {}

    void Swordsman::display() const {
        if (strength > 0) {
            cout << "CLANG! " << name << " says: ";
            Warrior::display();
        }
        return;
    }

}