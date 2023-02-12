/*  CS-UY 2124
    hw03: Warriors' Battle 2.0 (using class)
    Task: Model a game of medieval time about warriors.
    Created by Haoran Chen on 9/28/22.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Warrior class includes Weapon class inside private field.
class Warrior {
    // friend the Warrior output operator to have the access to its private variables
    friend ostream& operator<<(ostream& os, const Warrior& warrior);
    
public:
    // warrior constructor with initialization list
    Warrior(const string& in_name, const string& in_weaponName,
            int in_weaponStrength): warrior_name(in_name),
                weapon(in_weaponName, in_weaponStrength) {}
    
    // Battle method
    void Battle(Warrior& warrior2);
    
    // getter for warrior_name
    const string& get_warriorName() const { return warrior_name;}

private:
    class Weapon {
        // friend the Weapon output operator to have the access to its private variables
        friend ostream& operator<<(ostream& os, const Weapon& weapon);
        
    public:
        // Weapon constructor with initialization list
        Weapon(const string& in_weaponName, int in_weaponStrength) :
            weapon_name(in_weaponName), weapon_strength(in_weaponStrength) {};
        
        // getter for weapon_strength
        int getWeaponStrength() const {return weapon_strength;}
        
        // setter for weapon_strength
        void setWeaponStrength(int weaponStrength) {
            weapon_strength = weaponStrength;
        }
    
    private:
        string weapon_name;
        int weapon_strength;
    };
    // friend the weapon output operator to let warrior have the access to the private variables
    friend ostream& operator<<(ostream& os, const Warrior::Weapon& weapon);
    string warrior_name;
    Weapon weapon;
};

// function prototypes
void status(const vector<Warrior>& vector_warrior);
void fill_Warrior_vector(ifstream& ifs, vector<Warrior>& vector_warrior);
size_t find_warrior(const string& name, const vector<Warrior>& vector_warrior);

int main() {
    // reading file and check whether we can open or not
    ifstream ifs("warriors.txt");
    if(!ifs) {cerr << "Failed to open file."; exit(1);}

    // creating variables for while loop
    string command, name1, name2;
    vector<Warrior> vector_warrior;

    // read token(command) from file
    while (ifs >> command) {
        // if it is Warrior command
        if (command == "Warrior") {
            // call function to fill vector
            fill_Warrior_vector(ifs, vector_warrior);
            
        }
        // if it is Battle command
        else if (command == "Battle") {
            ifs >> name1 >> name2;
            size_t warrior1_index = find_warrior(name1, vector_warrior);
            size_t warrior2_index = find_warrior(name2, vector_warrior);
            
            // Error handling for the situation that warrior doesn't exist
            if (warrior1_index >= vector_warrior.size()) {
                cout << name1 << " doesn't exist." << endl;
            } else if (warrior2_index >= vector_warrior.size()) {
                cout << name2 << " doesn't exist." << endl;
            } else if (warrior1_index >= vector_warrior.size() &&
                        warrior2_index >= vector_warrior.size()) {
                cout << "Neither " << name1 << " nor " << name2 << " exist.";
            } else {
                // calling the battle method
                (vector_warrior[warrior1_index])
                    .Battle(vector_warrior[warrior2_index]);
            }
        }
        // if it is Status command
        else if (command == "Status") {
            // calling the status function
            status(vector_warrior);
        }
    }
    // close the file
    ifs.close();
}

// print the status command
void status(const vector<Warrior>& vector_warrior) {
    cout << "There are: " << vector_warrior.size() << " warriors" <<endl;
    for (size_t i = 0; i < vector_warrior.size(); i++) {
        cout << vector_warrior.at(i) << endl;
    }
}

// find the index of the specific warrior via his name if we could
size_t find_warrior(const string& name, const vector<Warrior>& vector_warrior){
    for (size_t index = 0; index < vector_warrior.size(); index++) {
        if (vector_warrior[index].get_warriorName() == name) {
            return index;
        }
    }
    return vector_warrior.size();
}

// fill warrior vector function
void fill_Warrior_vector(ifstream& ifs, vector<Warrior>& vector_warrior) {
    string warriorName, weaponName;
    int weaponStrength;
    ifs >> warriorName >> weaponName >> weaponStrength;
    
    // Error handling for reading file if the warrior already exists (same name again)
    size_t repeated_warrior_index = find_warrior(warriorName, vector_warrior);
    if (repeated_warrior_index < vector_warrior.size()){
        cout << "The warrior " << warriorName << "already exists";
    }
    // using emplace_back to add warrior's attributes
    vector_warrior.emplace_back(warriorName, weaponName, weaponStrength);
}

// print the battle info about two warriors
void Warrior::Battle(Warrior& warrior2) {

    cout << get_warriorName() << " battles ";
    cout << warrior2.get_warriorName() << endl;

    // Case 1: if their weapon strengths are all != 0 and > 0,
    //         they would both die.
    if (weapon.getWeaponStrength() > 0
            && warrior2.weapon.getWeaponStrength() > 0
            && weapon.getWeaponStrength()
                == warrior2.weapon.getWeaponStrength()) {
        cout << "Mutual Annihilation: " << get_warriorName();
        cout << " and " << warrior2.get_warriorName();
        cout << " die at each other's " << "hands" << endl;
        weapon.setWeaponStrength(0);
        warrior2.weapon.setWeaponStrength(0);
    }

    // Case 2: if one warrior is dead, they won't fight.
    else if (weapon.getWeaponStrength() > 0
             && warrior2.weapon.getWeaponStrength() == 0) {
        cout << "He's dead, " << get_warriorName() << endl;
    }
    else if (weapon.getWeaponStrength() == 0
             && warrior2.weapon.getWeaponStrength() > 0) {
        cout << "He's dead, " << warrior2.get_warriorName() << endl;
    }
    
    // Case 3: if one warrior's weapon strength is better than the other,
    //         the loser would be dead and winner's weapon strength would be changed
    else if (weapon.getWeaponStrength()
             > warrior2.weapon.getWeaponStrength()) {
        cout << get_warriorName() << " defeats ";
        cout << warrior2.get_warriorName() << endl;
        int new_strength =
            weapon.getWeaponStrength()
                - warrior2.weapon.getWeaponStrength();
        weapon.setWeaponStrength(new_strength);
        warrior2.weapon.setWeaponStrength(0);
    }
    else if (weapon.getWeaponStrength()
                < warrior2.weapon.getWeaponStrength()) {
        cout << warrior2.get_warriorName() << " defeats ";
        cout << get_warriorName() << endl;
        int new_strength =
            warrior2.weapon.getWeaponStrength()
                - weapon.getWeaponStrength();
        weapon.setWeaponStrength(0);
        warrior2.weapon.setWeaponStrength(new_strength);
    }
    
    // Case 4: if they are both dead, they won't fight as well.
    else if (weapon.getWeaponStrength() == 0
             && warrior2.weapon.getWeaponStrength() == 0) {
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
}

// output operator of warrior class
ostream& operator<<(ostream& os, const Warrior& warrior) {
    os << "Warrior: " << warrior.warrior_name << ", ";
    os << warrior.weapon;
    return os;
}

// output operator of Warrior::Weapon
ostream& operator<<(ostream& os, const Warrior::Weapon& weapon) {
    os << "weapon: " << weapon.weapon_name<< ", ";
    os << weapon.weapon_strength;
    return os;
}
