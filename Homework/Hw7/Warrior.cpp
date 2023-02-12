//
// Sagar Risal
// Implementation File for Warrior
// Warrior.cpp
//

#include <iostream>

#include "Lord.h"
#include "Warrior.h"
using namespace std;

namespace WarriorCraft {

//              Warrior Class Implementation

// constructor
    Warrior::Warrior(const string &name, double strength) :
            Protector(name, strength) {}

    void Warrior::display() const {
        cout << "Take that in the name of my lord, " << lord->getName() << endl;
        return;
    }

}