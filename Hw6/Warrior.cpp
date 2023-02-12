/*
  hw06: Warriors' Battle 5.0
  Goal: focus on Cyclic Association and Separate Compilation
  Problem: We are revisiting the world of Nobles and Warriors,
           now adding one new feature: not only can warriors be fired,
           they can also run away.
  Created by Haoran Chen on 10/25/22.
 */

#include "Warrior.h"
#include "Noble.h"
#include <iostream>
using namespace std;

namespace WarriorCraft{

    Warrior::Warrior(const string& in_name, double in_strength):
            name(in_name), strength(in_strength), boss(nullptr), hired(false) {};
    const string& Warrior::getName() const {return name;}
    double Warrior::getStrength() const {return strength;}
    bool Warrior::isHired() const {return hired;}
    void Warrior::setHired(bool in_hired){hired = in_hired;}
    void Warrior::setStrength(double newStrength) {strength = newStrength;}
    void Warrior::setBoss(Noble* in_boss) {boss = in_boss;}
    bool Warrior::runaway() {
        if (boss != nullptr) {
            boss->removeWar(*this);
            cout << name << " flees in terror, abandoning his lord, ";
            cout << boss->getName() << endl;
            boss = nullptr;
            return true;
        }
        return false;
    }
    ostream& operator<<(ostream& os, const Warrior& rhs){
        os << rhs.name << ": " << rhs.strength;
        return os;
    }

}
