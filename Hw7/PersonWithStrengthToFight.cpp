//
// Sagar Risal
// Implementation File for PersonWithStrengthToFight
// PersonWithStrengthToFight.cpp
//

#include "PersonWithStrengthToFight.h"
#include <iostream>
using namespace std;

namespace WarriorCraft {

//      PersonWithStrengthToFight Class Implementation

    PersonWithStrengthToFight::PersonWithStrengthToFight(const string &name,
                                                         double strength)
            : Noble(name),
              strength(strength) {}

    double PersonWithStrengthToFight::getStrength() const {
        return strength;
    }

    void PersonWithStrengthToFight::setStrength(double reduced_portion) {
        strength *= reduced_portion;
    }

    void PersonWithStrengthToFight::battle(Noble &noble2) {
        Noble::battle(noble2);
    }

// display function for PersonWithStrengthToFight
    void PersonWithStrengthToFight::display() const {
        cout << "Ugh!\n";
    }

}