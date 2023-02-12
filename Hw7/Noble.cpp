//
// Sagar Risal
// Implementation File for Noble
// Noble.cpp
//
#include "Noble.h"
#include <iostream>
using namespace std;

namespace WarriorCraft {

//          Noble Class Implementation

// initialization
    Noble::Noble(const string &name) : name(name), alive(true) {}

// returns name of noble
    const string &Noble::getName() const {
        return name;
    }

// returns alive status of noble
    bool Noble::isAlive() const {
        return alive;
    }

// sets alive status of noble
    void Noble::setAlive(bool new_alive) {
        alive = new_alive;
    }

// battle method for noble
    void Noble::battle(Noble &noble2) {
        cout << name << " battles " << noble2.getName() << endl;

        // initializes and gets noble1 and noble2's strength
        double noble1_Strength = getStrength();
        double noble2_Strength = noble2.getStrength();

        // Case 1: One of the nobles are already dead so nothing happens
        if (noble1_Strength > 0 && !noble2.isAlive()) {
            display();
            cout << "He's dead, " << name << endl;
            return;
        }
        if (noble2_Strength > 0 && !alive) {
            noble2.display();
            cout << "He's dead, " << noble2.getName() << endl;
            return;
        }

            // Case 2: They have the same strength so mutual annihilation
        else if ((noble1_Strength == noble2_Strength) &&
                 (noble1_Strength != 0) && (noble2_Strength != 0)) {

            display();
            noble2.display();

            cout << "Mutual Annihilation: " << name << " and "
                 << noble2.getName();
            cout << " die at each other's " << "hands" << endl;

            setStrength(0);
            noble2.setStrength(0);

            alive = false;
            noble2.setAlive(false);

            return;
        }

            // Case 3: noble 1 beats noble 2
        else if (noble1_Strength > noble2_Strength) {

            display();
            noble2.display();

            double reduced_portion = 1 - (noble2_Strength / noble1_Strength);
            cout << getName() << " defeats " << noble2.getName() << endl;

            setStrength(reduced_portion);
            noble2.setStrength(0);

            noble2.setAlive(false);
            return;
        }

            // Case 4: noble 2 beats noble 1
        else if (noble2_Strength > noble1_Strength) {

            display();
            noble2.display();

            double reduced_portion = 1 - (noble1_Strength / noble2_Strength);
            cout << noble2.getName() << " defeats " << getName() << endl;

            setStrength(0);
            noble2.setStrength(reduced_portion);

            alive = false;
            return;
        }
            // Case 5: they're both dead
        else if (!alive && !noble2.isAlive()) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
            return;
        }
    }

}