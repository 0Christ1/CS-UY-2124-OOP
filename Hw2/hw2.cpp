/*  CS-UY 2124
    hw02: Warrior
    Task: Model a game of medieval time about warriors' fight.
    Created by Haoran Chen on 9/19/22.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// create the Warrior structure
struct Warrior {
    string name;
    int strength;
};

// function prototypes
void fill_Warrior_vector(ifstream& ifs, vector<Warrior>& vector_warrior);
void status(const vector<Warrior>& vector_warrior);
size_t find_warrior(const string& name,
                    const vector<Warrior>& vector_warrior);
void print_battle(const Warrior& warrior1, const Warrior& warrior2,
                  vector<Warrior>& vector_warrior);

int main() {
    // create an input file stream
    ifstream ifs("warriors.txt");
    // check whether we can open the file or not
    if (!ifs) {cerr << "Failed to open file."; exit(1);}

    // create variables we need inside the later while loop
    string command, name1, name2;
    vector<Warrior> vector_warrior;
    Warrior warrior1, warrior2;
    size_t warrior1_index, warrior2_index;

    // read token(command) from file
    while (ifs >> command) {
        if (command == "Warrior") {
            fill_Warrior_vector(ifs, vector_warrior);
        } else if (command == "Battle") {
            ifs >> name1 >> name2;
            warrior1_index = find_warrior(name1, vector_warrior);
            warrior2_index = find_warrior(name2, vector_warrior);
            warrior1 = vector_warrior[warrior1_index];
            warrior2 = vector_warrior[warrior2_index];
            print_battle(warrior1, warrior2, vector_warrior);
        }  else if (command == "Status") {
            status(vector_warrior);
        }
    }
    ifs.close();
}

// read info from file and fill them into warrior vector
void fill_Warrior_vector (ifstream& ifs, vector<Warrior>& vector_warrior) {
    string name;
    int strength;
    ifs >> name >> strength;
    vector_warrior.push_back(Warrior{name, strength});
}

// print the status command
void status(const vector<Warrior>& vector_warrior) {
    cout << "There are: " << vector_warrior.size() << " warriors" <<endl;
    for (size_t i = 0; i<vector_warrior.size(); i++) {
        cout << "Warrior: " << vector_warrior[i].name << ", ";
        cout << "strength: " << vector_warrior[i].strength << endl;
    }
}

// find the position of specific warrior via given name as input
size_t find_warrior(const string& name,
                    const vector<Warrior>& vector_warrior) {
    for (size_t index = 0; index < vector_warrior.size(); index++) {
        if (vector_warrior[index].name == name) {
            return index;
        }
    }
    return vector_warrior.size();
}

// print the battle info about two warriors
void print_battle(const Warrior& warrior1, const Warrior& warrior2,
                  vector<Warrior>& vector_warrior) {
    cout << warrior1.name << " battles " << warrior2.name << endl;

    size_t w1_ind = find_warrior(warrior1.name, vector_warrior);
    size_t w2_ind = find_warrior(warrior2.name, vector_warrior);

    if (warrior1.strength > 0 && warrior2.strength > 0 &&
            warrior1.strength == warrior2.strength) {
        cout << "Mutual Annihilation: " << warrior1.name;
        cout << " and " << warrior2.name;
        cout << " die at each other's " << endl;
        cout << "hands" << endl;
        vector_warrior[w1_ind].strength = 0;
        vector_warrior[w2_ind].strength = 0;
    }
    else if (warrior1.strength > 0 && warrior2.strength == 0) {
        cout << "He's dead, " << warrior1.name << endl;
    }
    else if (warrior1.strength == 0 && warrior2.strength > 0) {
        cout << "He's dead, " << warrior2.name << endl;
    }
    else if (warrior1.strength > warrior2.strength) {
        cout << warrior1.name << " defeats " << warrior2.name << endl;
        int new_strength = warrior1.strength - warrior2.strength;
        vector_warrior[w1_ind].strength = new_strength;
        vector_warrior[w2_ind].strength = 0;
    }
    else if (warrior1.strength < warrior2.strength) {
        cout << warrior2.name << " defeats " << warrior1.name << endl;
        int new_strength = warrior2.strength - warrior1.strength;
        vector_warrior[w1_ind].strength = 0;
        vector_warrior[w2_ind].strength = new_strength;
    }
    else if (warrior1.strength == 0 && warrior2.strength == 0) {
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
}