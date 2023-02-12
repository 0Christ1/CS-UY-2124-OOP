/*
  hw5: Warriors' Battle 4.0
  Goal: focus on dynamic memory and error handling.
  Created by Haoran Chen on 10/11/22.
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Warrior class
class Warrior {
    friend ostream& operator<<(ostream& os, const Warrior& rhs);
public:
    Warrior(const string& in_name, int in_strength):
            name(in_name), strength(in_strength), hired(false) {};

    // setters and getters
    bool getHire() const {return hired;}
    void setHire(bool in_hire) {hired = in_hire;}
    const string& getName() const {return name;}
    double getStrength() const {return strength;}
    void setStrength(double newStrength) {strength = newStrength;}

private:
    string name;
    double strength;
    bool hired;
};

// Noble class
class Noble {
    friend ostream& operator<<(ostream& os, const Noble& rhs);
public:
    Noble(const string& in_name) : name(in_name), alive(true) {}

    // getter for noble's name
    const string& getName() const {return name;}

    // set new strength method
    void setNewStrength(double ratio) {
        for (size_t i = 0; i < army.size(); ++i) {
            double newStrength = army[i]->getStrength() * ratio;
            army[i]->setStrength(newStrength);
        }
    }

    // get total strength method
    double getTotalStrength() const {
        double totalStrength = 0.0;
        for (size_t i = 0; i < army.size(); ++i) {
            totalStrength += army[i]->getStrength();
        }
        return totalStrength;
    }

    // battle method
    void battle(Noble& nob);

    // hire method
    bool hire(Warrior& war) {
        // if noble is alive and warrior is not hired
        if(alive && !war.getHire()) {
            army.push_back(&war);
            war.setHire(true);
            return true;
        }
        // if warrior is hired
        else if(war.getHire()) {
            cout << "Attempting to hire " << war.getName();
            cout << " by " << name << " failed!" << endl;
            return false;
        }
        // if noble is not alive
        else {
            cout << name << " is dead. He/She cannot hire." << endl;
            return false;
        }
    }

    // fire method
    bool fire(Warrior& war) {
        bool fired = false;
        // if noble is alive and warrior was hired
        if (alive && war.getHire()) {
            for (size_t i = 0; i < army.size(); ++i) {
                // if warrior is not fired and exists inside army
                if (!fired && &war == army[i]) {
                    fired = true;
                    army[i]->setHire(false);
                // if warrior was fired, shift the pointer
                } else if(fired) {
                    army[i - 1] = army[i];
                }
            }
            // if the given warrior inside army and was fired, we pop the last pointer
            if (fired){
                cout << "You don't work for me anymore " << war.getName();
                cout << "! -- " << name << '.' << endl;
                army.pop_back();
                return true;
            }
            // the given warrior is not inside army
            else {
                cout << "Attempting to fire the warrior not inside army.";
                return false;
            }
        }
        // if warrior is not hired
        else if (!war.getHire()) {
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
private:
    string name;
    vector<Warrior*> army;
    bool alive;
};

// function prototypes
size_t find_noble(const string& name, const vector<Noble*>& rhs);
size_t find_warrior(const string& name, const vector<Warrior*>& rhs);
void status(const vector<Noble*>& nobles, const vector<Warrior*>& warriors);
bool hireWarrior(const string& nob_name, const string& war_name,
                 const vector<Noble*>& nobles, const vector<Warrior*>& warriors);
bool fireWarrior(const string& nob_name, const string& war_name,
                 const vector<Noble*>& nobles, const vector<Warrior*>& warriors);

int main() {
    ifstream ifs("nobleWarriors.txt");
    if (!ifs) {cerr << "Failed to open file."; exit(1);}

    // create some variables for while loop
    string command, nob_name, war_name, nob_name2;
    int strength;
    vector<Warrior*> warriors;
    vector<Noble*> nobles;

    // read command from file
    while (ifs >> command) {
        if (command == "Noble") {
            ifs >> nob_name;
            //if a Noble with a given name already exists.
            if (find_noble(nob_name, nobles) < nobles.size()) {
                cout << nob_name << " already exists." << endl;
            } else {
                nobles.push_back(new Noble(nob_name));
            }
        }
        else if (command == "Warrior") {
            ifs >> war_name >> strength;
            // if a Warrior with a given name already exists.
            if (find_warrior(war_name, warriors) < warriors.size()) {
                cout << war_name << " already exists." << endl;
            } else {
                warriors.push_back(new Warrior(war_name, strength));
            }
        }
        else if (command == "Hire") {
            ifs >> nob_name >> war_name;
            hireWarrior(nob_name, war_name, nobles, warriors);
        }
        else if (command == "Status") {
            status(nobles, warriors);
        }
        else if (command == "Fire") {
            ifs >> nob_name >> war_name;
            fireWarrior(nob_name, war_name, nobles, warriors);
        }
        else if (command == "Battle") {
            ifs >> nob_name >> nob_name2;
            size_t nobInd1 = find_noble(nob_name, nobles);
            size_t nobInd2 = find_noble(nob_name2, nobles);

            if ( nobInd1 == nobles.size()) {
                cout << nob_name << " doesn't exists." << endl;
            }
            else if ( nobInd2 == nobles.size()){
                cout << nob_name2 << " doesn't exists." << endl;
            }
            else {
                nobles[nobInd1]->battle(*nobles[nobInd2]);
            }
        }
        else {
            // no memory leak
            for(const Noble* nob: nobles) {
                delete nob;
            }
            for (const Warrior* war: warriors) {
                delete war;
            }
            // no dangling pointer
            nobles.clear();
            warriors.clear();
        }
    }
    // close file
    ifs.close();
}

// print the status command
void status(const vector<Noble*>& nobles, const vector<Warrior*>& warriors) {
    cout << "Status\n" << "======\n" << "Nobles:\n";
    if (nobles.size() == 0){
        cout << "NONE" << endl;
    } else {
        for (size_t i = 0; i < nobles.size(); ++i) {
            cout << *nobles[i] << endl;
        }
    }

    cout << "\nUnemployed Warriors:\n";
    // count for how many warriors were hired
    int employed_count = 0;
    for (size_t i = 0; i < warriors.size(); ++i) {
        if (!warriors[i]->getHire()){
            cout << "\t" << *warriors[i] << endl;
        }else {
            employed_count += 1;
        }
    }
    // if all warriors in vector was hired
    if (employed_count == warriors.size()) {
        cout << "NONE" << endl;
    }
}

// find the noble function
size_t find_noble(const string& name, const vector<Noble*>& rhs) {
    for (size_t i = 0; i < rhs.size(); ++i) {
        if (name == rhs[i]->getName()) return i;
    }
    return rhs.size();
}

// find the warrior function
size_t find_warrior(const string& name, const vector<Warrior*>& rhs) {
    for (size_t i = 0; i < rhs.size(); ++i) {
        if (name == rhs[i]->getName()) return i;
    }
    return rhs.size();
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
        cout << "He's dead, " << nob.name<< endl;

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

// hireWarrior function
bool hireWarrior(const string& nob_name, const string& war_name,
                 const vector<Noble*>& nobles, const vector<Warrior*>& warriors) {

    // noble index and warrior index
    size_t nobInd = find_noble(nob_name, nobles);
    size_t warInd = find_warrior(war_name, warriors);

    // check exist of noble
    if (nobInd == nobles.size()) {
        if (warInd == warriors.size()) {
            cout << nob_name << " and " << war_name;
            cout << " both do not exist.\n";
            return false;
        } else {
            cout << "Attempting to hire using unknown noble: ";
            cout << nob_name << endl;
            return false;
        }
    }
    // check exist of warrior
    else if (warInd == warriors.size()){
        cout << "Attempting to hire using unknown warrior: ";
        cout << war_name << endl;
        return false;
    }
    else {
        // call hire method
        nobles[nobInd]->hire(*warriors[warInd]);
        return true;
    }
}

// fireWarrior function
bool fireWarrior(const string& nob_name, const string& war_name,
                 const vector<Noble*>& nobles, const vector<Warrior*>& warriors) {

    // noble index and warrior index
    size_t nobInd = find_noble(nob_name, nobles);
    size_t warInd = find_warrior(war_name, warriors);

    // check exist of noble
    if(nobInd == nobles.size()) {
        // check exist of warrior
        if (warInd == warriors.size()) {
            cout << nob_name << " and " << war_name;
            cout << " both do not exist.\n";
            return false;
        } else {
            cout << "Attempting to fire using unknown noble: ";
            cout << nob_name << endl;
            return false;
        }
    }
    // check exist of warrior
    else if (warInd == warriors.size()) {
        cout << "Attempting to fire using unknown warrior: ";
        cout << war_name << endl;
        return false;
    }
    else{
        // call fire method
        nobles[nobInd]->fire(*warriors[warInd]);
        return true;
    }
}

// output for Warrior class
ostream& operator<<(ostream& os, const Warrior& rhs) {
    os << rhs.name << ": " << rhs.strength;
    return os;
}

// output for Noble class
ostream& operator<<(ostream& os, const Noble& rhs) {
    os << rhs.name << " has an army of " << rhs.army.size();
    for (size_t i = 0; i < rhs.army.size(); ++i) {
        os << "\n\t" << *rhs.army[i];
    }
    return os;
}