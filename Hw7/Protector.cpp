//
// Sagar Risal
// Implementation File for Protector
// Protector.cpp
//
#include <iostream>
#include "Protector.h"
using namespace std;

namespace WarriorCraft {

//          Protector class implementations

// initialization
    Protector::Protector(const string &name, double strength)
            : name(name), strength(strength), lord(nullptr) {}

// returns name of warrior
    const string &Protector::getName() const {
        return name;
    }

// returns strength of warrior
    double Protector::getStrength() const {
        return strength;
    }

// sets strength of warrior
    void Protector::setStrength(double new_strength) {
        strength = new_strength;
    }

// returns false if not hired and true if hired
    bool Protector::isHired() const {
        return lord != nullptr;
    }

// sets the hired status for warrior
    void Protector::setLord(Lord *newLord) {
        lord = newLord;
    }

    bool Protector::runaway() {
        if (lord) {
            cout << name << " flees in terror, abandoning his lord, "
                 << lord->getName() << endl;
            lord->fireHelper(*this);
            lord = nullptr;
            return true;
        } else {
            return false;
        }
    }

}