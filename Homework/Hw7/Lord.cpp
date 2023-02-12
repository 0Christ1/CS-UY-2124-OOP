//
// Sagar Risal
// Implementation File for Lord
// Lord.cpp
//
#include <iostream>
using namespace std;

#include "Lord.h"
#include "Protector.h"

namespace WarriorCraft {

//          Lord Class Implementation

// initialization
    Lord::Lord(const string &name) : Noble(name) {}

// helper method for battle, GETS total strength of army
    double Lord::getStrength() const {
        double totalArmyStrength = 0.0;
        for (size_t index = 0; index < army.size(); index++) {
            totalArmyStrength += army[index]->getStrength();
        }
        return totalArmyStrength;
    }

// helper method for battle, SETS total strength of army
    void Lord::setStrength(double reduced_portion) {
        for (size_t index = 0; index < army.size(); index++) {
            double newStrength = army[index]->getStrength() * reduced_portion;
            army[index]->setStrength(newStrength);
        }
    }

    bool Lord::hires(Protector &protector) {
        // noble has to be alive and warrior cannot be hired
        if (alive && !protector.isHired() && (protector.getStrength() != 0)) {
            army.push_back(&protector);
            protector.setLord(this);
            return true;
        }
            // if warrior was already hired
        else if (protector.isHired()) {
            //cout << name << " cannot hire " << protector.getName() << endl;

            return false;
        }
            // if warrior is dead
        else if (alive && protector.getStrength() == 0) {
            //cout << name << " cannot hire " << protector.getName() << " because they are DEAD" << endl;
            return false;
        }
            // noble is dead
        else {
            //cout << name << " cannot hire because they're DEAD" << endl;
            return false;
        }
    }

// method to fire a warrior which takes a Warrior's name
// and deletes it to the vector of warrior pointers
    bool Lord::fire(Protector &protector) {
        // have to first make sure that the noble is alive and the warrior is hired
        if (fireHelper(protector)) {
            cout << "You don't work for me anymore " << protector.getName();
            cout << "! -- " << name << '.' << endl;
            return true;
        } else {
            // if the warrior wasn't even hired in the first place
            if (!protector.isHired()) {
                cout
                        << "This warrior hasn't even been hired in the first place. ";
                cout << "WHAT ARE YOU DOING!?" << endl;
                return false;
            }
                // noble is dead
            else if (!alive) {
                cout << name << " cannot fire because they are DEAD" << endl;
                return false;
            } else {
                // if we get past the for loop and didn't find the warrior
                cout << "Warrior, " << protector.getName()
                     << ", is not in this army."
                     << endl;
                return false;
            }
        }
    }


    bool Lord::fireHelper(Protector &protector) {
        if (alive && protector.isHired()) {
            for (size_t index = 0; index < army.size(); index++) {
                // find who to fire
                if (army[index] == &protector) {
                    army[index]->setLord(nullptr);
                    // we go up to army.size() - 1, since we would go out of range
                    // if we didn't
                    for (size_t index2 = index;
                         index2 < army.size() - 1; index2++) {
                        army[index2] = army[index2 + 1];
                    }
                    army.pop_back();
                    return true;
                }
            }
            return false;
        } else {
            return false;
        }
    }

// battle method for Lord that calls Noble's battle method
    void Lord::battle(Noble &noble2) {
        Noble::battle(noble2);
    }

// display function for Lord
    void Lord::display() const {
        for (const Protector *protector: army) {
            protector->display();
        }
    }

}