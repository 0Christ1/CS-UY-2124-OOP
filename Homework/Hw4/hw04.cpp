/*
  hw4: Warriors' Battle 3.0
  Association: Noble - Warrior
  Created by Haoran Chen on 10/7/22.
 */

#include <iostream>
#include <vector>
using namespace std;

// Define your classes here
// Warrior class
class Warrior {
    // output operator
    friend ostream& operator<<(ostream& os, const Warrior& rhs);
public:
    Warrior(const string& in_name, double in_strength)
            : name(in_name), strength(in_strength) {hired = false;}

    // getters and setters
    const string& getName() const {return name;}
    double getStrength() const {return strength;}
    bool getHired() const {return hired;}
    void setHired(bool in_hired){hired = in_hired;}
    void setStrength(double newStrength) {strength = newStrength;}

private:
    string name;
    double strength;
    bool hired;
};

// Noble class
class Noble {
    // output operator
    friend ostream& operator<<(ostream& os, const Noble& rhs);
public:
    Noble(const string& in_name) : name(in_name), alive(true){};

    // get Noble's name
    const string& getName() const {return name;}

    // set new strength method
    void setNewStrength(double reduced) {
        for (size_t i = 0; i < vec_war.size(); ++i) {
            double newStrength = vec_war[i]->getStrength() * reduced;
            vec_war[i]->setStrength(newStrength);
        }
    }

    // get total strength method
    double getTotalStrength() {
        double totalStrength = 0.0;
        for (size_t i = 0; i < vec_war.size(); ++i) {
            totalStrength += vec_war[i]->getStrength();
        }
        return totalStrength;
    }

    // battle method
    void battle(Noble& nob);

    // hire method
    bool hire(Warrior& war) {
        // if Noble is alive, warrior is not hired, and warrior's strength is not 0
        if (alive && !war.getHired() && war.getStrength() != 0) {
            vec_war.push_back(&war);
            war.setHired(true);
            return true;
        }
        return false;
    }

    // fire method
    bool fire(Warrior& war) {
        // use bool variable to supervise the warrior's status
        bool fired = false;
        // if noble is alive and the warrior is hired
        if (alive && war.getHired()) {
            for (size_t i = 0; i < vec_war.size(); ++i) {
                // if fire is false, we need to find the warrior
                if (!fired){
                    // if the address are the same, we will find the warrior
                    if (&war == vec_war[i]) {
                        fired = true;
                        vec_war[i]->setHired(false);
                    }
                // if the fire is true, we will shift the pointer
                } else {
                    vec_war[i-1] = vec_war[i];
                }
            }
        }
        // if fired is true, we will pop that pointer
        if(fired) {
            vec_war.pop_back();
        }
        return fired;
    }

private:
    string name;
    vector<Warrior*> vec_war;
    bool alive;
};

// Utility functions provided for you, defined below.
void hire(Noble& nob, Warrior& war);
void fire(Noble& nob, Warrior& war);

int main() {

    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    hire(jim, nimoy);
    hire(lance, theGovernator);
    hire(art, wizard);
    hire(lance, dylan);
    hire(linus, lawless);
    hire(billie, mrGreen);
    hire(art, cheetah);
    hire(art, nimoy);

    cout << "==========\n\n"
         << "Status before all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n\n";

    fire(art, cheetah);
    cout << art << endl;
    fire(lance, nimoy);
    cout << lance << endl;
    cout << "==========\n\n";

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
    cout << "==========\n\n";

    cout << "Status after all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";
}

// battle method
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

// output for warrior class
ostream& operator<<(ostream& os, const Warrior& rhs){
    os << rhs.name << ": " << rhs.strength;
    return os;
}

// output for noble class
ostream& operator<<(ostream& os, const Noble& rhs){
    os << rhs.name << " has an army of " << rhs.vec_war.size();
    for (size_t i = 0; i < rhs.vec_war.size(); ++i) {
        os << endl << "\t" << *rhs.vec_war[i];
    }
    return os;
}

//
// Utility functions
//
// hire. Calls Noble's hire method and displays error message on failure.
void hire(Noble& nob, Warrior& war) {
    if (!nob.hire(war)) {
        cerr << nob.getName() << " failed to hire " << war.getName() << endl;
    }
}

// fire. Calls Noble's fire method, displaying message on succsess and error message on failure
void fire(Noble& nob, Warrior& war) {
    if (nob.fire(war)) {
        cout << war.getName() << ", you don't work for me anymore! -- " << nob.getName() << ".\n";
    } else {
        cerr << nob.getName() << " failed to fire " << war.getName() << endl;
    }
}
