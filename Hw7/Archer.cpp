//
// Sagar Risal
// Implementation File for Archer
// Archer.cpp
//

#include <iostream>
using namespace std;

#include "Archer.h"

namespace WarriorCraft {

    // constructor
    Archer::Archer(const string &name, double strength) :
                                Warrior(name,strength) {}

    // prints out in battle
    void Archer::display() const {
        if (strength > 0) {
            cout << "TWANG! " << name << " says: ";
            Warrior::display();
        }
        return;
    }

}