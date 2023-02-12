/*
  hw06: Warriors' Battle 5.0
  Goal: focus on Cyclic Association and Separate Compilation
  Problem: We are revisiting the world of Nobles and Warriors,
           now adding one new feature: not only can warriors be fired,
           they can also run away.
  Created by Haoran Chen on 10/25/22.
 */

#include <iostream>
#include <vector>
using namespace std;

// forward class declarations
class Noble;

// Warrior class
class Warrior {
    // output operator
    friend ostream& operator<<(ostream&, const Warrior&);
public:
    Warrior(const string&, double);
    // getters and setters
    const string& getName() const;
    double getStrength() const;
    bool isHired() const;
    void setHired(bool);
    void setStrength(double);
    void setBoss(Noble*);
    bool runaway();

private:
    string name;
    double strength;
    bool hired;
    Noble* boss;
};

// Noble class
class Noble {
    // output operator
    friend ostream& operator<<(ostream&, const Noble&);
public:
    Noble(const string&);

    // get Noble's name
    const string& getName() const;

    // set new strength method
    void setNewStrength(double);

    // get total strength method
    double getTotalStrength() const;

    // battle method
    void battle(Noble&);

    // hire method
    bool hire(Warrior&);

    // fire method
    bool fire(Warrior&);

    // remove warrior
    bool removeWar(const Warrior& war);

private:
    string name;
    vector<Warrior*> vec_war;
    bool alive;
};

int main() {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 4);
    Warrior sky("Leia", 6);
    Warrior wizard("Merlin", 9);
    Warrior jaffa("Teal'c", 9);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(jaffa);
    art.hire(cheetah);
    art.hire(wizard);
    art.hire(sky);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(nimoy);

    cout << "================ Initial Status ===============" << endl;
    cout << art << endl
         << lance << endl
         << jim << endl
         << linus << endl
         << billie << endl;
    cout << "===============================================\n\n";

    art.fire(cheetah);
    wizard.runaway();
    cout << endl << art << endl;

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "\n================ Final Status ===============" << endl;
    cout << art << endl
         << lance << endl
         << jim << endl
         << linus << endl
         << billie << endl;

    // Tarzan and Merlin should be unemployed
    cout << "Tarzan's Hire Status: " << boolalpha
         << cheetah.isHired() << endl;
    cout << "Merlin's Hire Status: " << boolalpha
         << wizard.isHired() << endl;
    cout << "===============================================\n\n";
}

// Warriors constructor, methods, and output operator
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


// Noble's constructor, methods, and output operator
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
