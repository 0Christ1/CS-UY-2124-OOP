/**
 * hw07: Medieval Battle 6.0
 * Haoran Chen
 * Protectors cpp: class definitions
 */

#include "Protectors.h"
#include "Noble.h"
#include <iostream>
#include <vector>
using namespace std;

namespace WarriorCraft {

    ostream& operator<<(ostream& os, const Protectors& rhs) {
        os << rhs.name << '\t' << rhs.strength << endl;
        return os;
    }

    Protectors::Protectors(const string& in_name, double in_strength):
            name(in_name), strength(in_strength), boss(nullptr){}

    const string& Protectors::getName() const {return name;}

    const string& Protectors::getBossName() const {return boss->getNobleName();}

    Lord* Protectors::getBoss() const {return boss;}

    void Protectors::setBoss(Lord* in_boss) {boss = in_boss;}

    double Protectors::getStrength() const {return strength;}

    void Protectors::setStrength(double newStrength) {strength = newStrength;}

    bool Protectors::runaway() {
        if (boss) {
            cout << name << " flees in terror, abandoning his lord, ";
            cout << getBossName() << endl;
            boss->removePro(*this);
            return true;
        }
        cout << name << " is not hired so that cannot runaway." << endl;
        return false;
    }

    Wizard::Wizard(const string& in_name, double in_strength):
            Protectors(in_name, in_strength){}

    void Wizard::defending() const {cout << "POOF!" << endl;}

    Warriors::Warriors(const string& in_name, double in_strength):
            Protectors(in_name, in_strength){}

    void Warriors::defending() const {
        cout << " says: Take that in the name of my lord, ";
        cout << getBossName() << endl;
    }

    Archer::Archer(const string& in_name, double in_strength):
            Warriors(in_name, in_strength){}

    void Archer::defending() const {
        cout << "TWANG! " << getName();
        Warriors::defending();
    }

    Swordsman::Swordsman(const string& in_name, double in_strength):
            Warriors(in_name, in_strength){}

    void Swordsman::defending() const {
        cout << "CLANG! " << getName();
        Warriors::defending();
    }
}