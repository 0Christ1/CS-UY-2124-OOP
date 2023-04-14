/**
 * hw07: Medieval Battle 6.0
 * Haoran Chen
 * Noble cpp: class definitions
 */

#include "Noble.h"
#include "Protectors.h"
#include <iostream>
using namespace  std;

namespace WarriorCraft {

    ostream& operator<<(ostream& os, const Noble& rhs) {
        os << "\n===========Noble Output=============" << endl;
        os << "Name:\t " << rhs.name << endl;
        os << "Alive: \t " << boolalpha << rhs.alive  << endl;
        os << "Army: ";
        rhs.display();
        os << "=====================================";
        return os;
    }

    Noble::Noble(const std::string &in_name): name(in_name), alive(true) {}

    const string& Noble::getNobleName() const {return name;}

    void Noble::battle(Noble &nob) {                           // member of Noble class
        cout << name << " battles " << nob.name << endl;
        // get the total strength from two nobles
        double totalStrength1 = getStrength();
        double totalStrength2 = nob.getStrength();

        // Case 1: if these two nobles were both dead, they wouldn't fight.
        if (!alive && !nob.alive) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;

            // Case 2: if one noble is dead, they wouldn't fight as well
        }else if (alive && !nob.alive){
            battleCry();
            cout << "He's dead, " << name << endl;
        }else if (!alive && nob.alive){
            nob.battleCry();
            cout << "He's dead, " << nob.name << endl;

            // Case 3: if they are both alive
        }else{
            battleCry();
            nob.battleCry();
            // 3.1 if one total strength is bigger than other
            if (totalStrength1 > totalStrength2) {
                cout << name << " defeats " << nob.name << endl;
                setNewStrength(1 - totalStrength2 / totalStrength1);
                nob.setNewStrength(0);
                nob.alive = false;
            }
            else if (totalStrength1 < totalStrength2) {
                cout << nob.name << " defeats " << name << endl;
                setNewStrength(0);
                nob.setNewStrength(1 - totalStrength1 / totalStrength2);
                alive = false;
            }
                // 3.2 if one total strength is 0, they won't battle
            else if (totalStrength1 == 0) {
                cout << "He cannot fight since no strength or army, ";
                cout << nob.name << endl;
            }
            else if (totalStrength2 == 0) {
                cout << "He cannot fight since no strength or army, ";
                cout << name << endl;
            }
                //3.3 if their total strength is equivalent
            else if (totalStrength1 == totalStrength2) {
                cout << "Mutual Annihilation: " << name;
                cout << " and " << nob.name;
                cout << " die at each other's " << "hands" << endl;
                setNewStrength(0);
                nob.setNewStrength(0);
                alive = false;
                nob.alive = false;
            }
        }
    }

    bool Noble::isAlived() const {return alive;}

    Lord::Lord(const string &in_name) : Noble(in_name) {}

    void Lord::battleCry() const {
        for (size_t i = 0; i < army.size(); ++i) {
            army[i]->defending();
        }
    }

    double Lord::getStrength() const {
        double totalStrength = 0.0;
        for (size_t i = 0; i < army.size(); ++i) {
            totalStrength += army[i]->getStrength();
        }
        return totalStrength;
    }

    void Lord::setNewStrength(double reduced) {
        for (size_t i = 0; i < army.size(); ++i) {
            double newStrength = army[i]->getStrength() * reduced;
            army[i]->setStrength(newStrength);
        }
    }

    bool Lord::hires(Protectors &rhs) {
        // if lord is alive and protector is not hired
        if (isAlived() && !rhs.getBoss()) {
            army.push_back(&rhs);
            rhs.setBoss(this);
            return true;
        }
            // if protector is hired
        else if (rhs.getBoss()) {
            return false;
        }
            // if lord is not alive
        else {
            return false;
        }
    }

    bool Lord::fires(Protectors &rhs) {
        bool fired = false;
        // if lord is alive and protector is hired
        if (isAlived() && rhs.getBoss()) {
            for (size_t i = 0; i < army.size(); ++i) {
                // if protector is not fired and exists inside army
                if (!fired && &rhs == army[i]) {
                    fired = true;
                    army[i]->setBoss(nullptr);
                    // if protector was fired, shift the pointer
                } else if (fired) {
                    army[i - 1] = army[i];
                }
            }
            // if the given protector inside army and was fired,
            // we pop the last pointer
            if (fired) {
                cout << "You don't work for me anymore " << rhs.getName();
                cout << "! -- " << getNobleName() << '.' << endl;
                army.pop_back();
                rhs.setBoss(nullptr);
                return true;
            }
                // the given protector is not inside army
            else {
                cout << "Attempting to fire the warrior not inside army.";
                return false;
            }
        }
            // if protector is not hired
        else if (!rhs.getBoss()) {
            cout << "Attempting to fire not hired warrior ";
            cout << rhs.getName();
            return false;
        }
            // if lord is not alive
        else {
            cout << getNobleName() << " is dead. He/She cannot fire." << endl;
            return false;
        }
    }

    bool Lord::removePro(const Protectors &rhs) {
        bool removed = false;
        for (size_t i = 0; i < army.size(); ++i) {
            if (!removed && &rhs == army[i]) {
                removed = true;
                army[i]->setBoss(nullptr);
            } else if (removed) {
                army[i - 1] = army[i];
            }
        }
        if (removed) {
            army.pop_back();
            return true;
        }
        return false;
    }

    void Lord::display() const {
        cout << "\tLord " << getNobleName();
        cout << " owns an army with " << army.size();
        if (army.size() > 1) {
            cout << " protectors" << endl;
        } else {
            cout << " protector" << endl;
        }
        for (size_t i = 0; i < army.size(); ++i) {
            cout << "\t\t" << *army[i];
        }
    }

    PersonWithStrengthToFight::PersonWithStrengthToFight
            (const string& in_name, double in_strength):
            strength(in_strength), Noble(in_name) {}

    void PersonWithStrengthToFight::battleCry() const {
        cout << "Ugh!" << endl;
    }

    double PersonWithStrengthToFight::getStrength() const {return strength;}

    void PersonWithStrengthToFight::setNewStrength(double newStrength) {
        strength = newStrength;
    }

    void PersonWithStrengthToFight::display() const {
        cout << "\tNo Army" << endl;
        cout << "\t\tPerson: " << getNobleName() << " was born with strength ";
        cout << getStrength() << endl;
    }
}