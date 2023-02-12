/*
  hw06: Warriors' Battle 5.0
  Goal: focus on Cyclic Association and Separate Compilation
  Problem: We are revisiting the world of Nobles and Warriors,
           now adding one new feature: not only can warriors be fired,
           they can also run away.
  Created by Haoran Chen on 10/25/22.
 */

#include "Noble.h"
#include "Warrior.h"
#include <iostream>
using namespace std;

namespace WarriorCraft{

    Noble::Noble(const string& in_name) : name(in_name), alive(true){};
    const string& Noble::getName() const {return name;}
    void Noble::setNewStrength(double reduced) {
        for (size_t i = 0; i < vec_war.size(); ++i) {
            double newStrength = vec_war[i]->getStrength() * reduced;
            vec_war[i]->setStrength(newStrength);
        }
    }
    double Noble::getTotalStrength() const{
        double totalStrength = 0.0;
        for (size_t i = 0; i < vec_war.size(); ++i) {
            totalStrength += vec_war[i]->getStrength();
        }
        return totalStrength;
    }
    bool Noble::removeWar(const Warrior& war) {
        bool removed = false;
        for (size_t i = 0; i < vec_war.size(); ++i) {
            if (!removed && &war == vec_war[i]) {
                removed = true;
                vec_war[i]->setHired(false);
            } else if (removed) {
                vec_war[i-1] = vec_war[i];
            }
        }
        if (removed) {
            vec_war.pop_back();
            return true;
        }
        return false;
    }
    void Noble::battle(Noble& nob) {
        cout << name << " battles " << nob.name << endl;

        // get the total strength from two nobles
        double totalStrength1 = getTotalStrength();
        double totalStrength2 = nob.getTotalStrength();

        // Case 1: if these two nobles were both dead, they wouldn't fight.
        if (!alive && !nob.alive) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;

            // Case 2: if one noble is dead, they wouldn't fight as well
        }else if (alive && !nob.alive){
            cout << "He's dead, " << name << endl;
        }else if (!alive && nob.alive){
            cout << "He's dead, " << nob.name << endl;

            // Case 3: if they are both alive
        }else{
            // Case 3.1: if their total strength is equivalent and not 0
            if (totalStrength1 == totalStrength2 &&
                totalStrength1 != 0 && totalStrength2 != 0) {
                cout << "Mutual Annihilation: " << name;
                cout << " and " << nob.name;
                cout << " die at each other's " << "hands" << endl;
                setNewStrength(0);
                nob.setNewStrength(0);
                alive = false;
                nob.alive = false;
            }
                // Case 3.2: if one total strength is bigger than other
            else if (totalStrength1 > totalStrength2 && alive && nob.alive) {
                cout << name << " defeats " << nob.name << endl;
                setNewStrength(1 - totalStrength2 / totalStrength1);
                nob.setNewStrength(0);
                nob.alive = false;
            }
            else if (totalStrength1 < totalStrength2 && alive && nob.alive) {
                cout << nob.name << " defeats " << name << endl;
                setNewStrength(0);
                nob.setNewStrength(1 - totalStrength1 / totalStrength2);
                alive = false;
            }
        }
    }
    bool Noble::hire(Warrior& war) {
        // if noble is alive and warrior is not hired
        if(alive && !war.isHired()) {
            vec_war.push_back(&war);
            war.setHired(true);
            war.setBoss(this);
            return true;
        }
            // if warrior is hired
        else if(war.isHired()) {
            return false;
        }
            // if noble is not alive
        else {
            cout << name << " is dead. He/She cannot hire." << endl;
            return false;
        }
    }
    bool Noble::fire(Warrior& war) {
        bool fired = false;
        // if noble is alive and warrior was hired
        if (alive && war.isHired()) {
            for (size_t i = 0; i < vec_war.size(); ++i) {
                // if warrior is not fired and exists inside army
                if (!fired && &war == vec_war[i]) {
                    fired = true;
                    vec_war[i]->setHired(false);
                    // if warrior was fired, shift the pointer
                } else if(fired) {
                    vec_war[i - 1] = vec_war[i];
                }
            }
            // if the given warrior inside army and was fired, we pop the last pointer
            if (fired){
                cout << "You don't work for me anymore " << war.getName();
                cout << "! -- " << name << '.' << endl;
                vec_war.pop_back();
                war.setBoss(nullptr);
                return true;
            }
                // the given warrior is not inside army
            else {
                cout << "Attempting to fire the warrior not inside army.";
                return false;
            }
        }
            // if warrior is not hired
        else if (!war.isHired()) {
            cout << "Attempting to fire not hired warrior ";
            cout << war.getName();
            return false;
        }
            // if noble is not alive
        else {
            cout << name << " is dead. He/She cannot fire." << endl;
            return false;
        }
    }
    ostream& operator<<(ostream& os, const Noble& rhs){
        os << rhs.name << " has an army of " << rhs.vec_war.size();
        for (size_t i = 0; i < rhs.vec_war.size(); ++i) {
            os << endl << "\t" << *rhs.vec_war[i];
        }
        os << endl;
        return os;
    }

}
