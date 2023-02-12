//
// Sagar Risal
// Implementation File for Wizard
// Wizard.cpp
//

#include "Wizard.h"
#include <iostream>
using namespace std;

namespace WarriorCraft {

//          Wizard Class Implementation

// constructor
    Wizard::Wizard(const string &name, double strength) : Protector(name,
                                                                    strength) {}

// display method
    void Wizard::display() const {
        if (strength > 0) {
            cout << "POOF!\n";
        }
        return;
    }

}