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
void fill_Warrior_vector (ifstream& ifs, vector<Warrior>& v_war);
void status(const vector<Warrior>& v_war);
size_t find_warrior(const string& name, const vector<Warrior>& v_war);
void print_battle(const Warrior& warrior1, const Warrior& warrior2,
                  vector<Warrior>& vector_warrior);

int main() {
    // create an input file stream and check whether we can open the file or not
    ifstream ifs("warriors.txt");
    if (!ifs) {cerr << "Failed to open file."; exit(1);}

    // create variables we need inside the later while loop
    string command, name1, name2;
    vector<Warrior> vector_warrior;
    Warrior warrior1, warrior2;

    // read token(command) from file
    while (ifs >> command) {
        if (command == "Warrior") {
            fill_Warrior_vector(ifs, vector_warrior);
        } else if (command == "Battle") {
            ifs >> name1 >> name2;
            warrior1 = vector_warrior[find_warrior(name1, vector_warrior)];
            warrior2 = vector_warrior[find_warrior(name2, vector_warrior)];
            print_battle(warrior1, warrior2, vector_warrior);
        }  else if (command == "Status") {
            status(vector_warrior);
        }
    }
    ifs.close();
}

// read info from file and fill them into warrior vector
void fill_Warrior_vector (ifstream& ifs, vector<Warrior>& v_war) {
    string name;
    int strength;
    ifs >> name >> strength;
    v_war.push_back(Warrior{name, strength});
}

// print the status command
void status(const vector<Warrior>& v_war) {
    cout << "There are: " << v_war.size() << " warriors" <<endl;
    for (size_t i = 0; i<v_war.size(); i++) {
        cout << "Warrior: " << v_war[i].name << ", ";
        cout << "strength: " << v_war[i].strength << endl;
    }
}

// find the position of specific warrior via given name as input
size_t find_warrior(const string& name, const vector<Warrior>& v_war) {
    for (size_t index = 0; index < v_war.size(); index++) {
        if (v_war[index].name == name) {
            return index;
        }
    }
    return v_war.size();
}

// print the battle info about two warriors
void print_battle(const Warrior& warrior1, const Warrior& warrior2,
                  vector<Warrior>& vector_warrior) {
    cout << warrior1.name << " battles " << warrior2.name << endl;
    
    size_t warrior1_index = find_warrior(warrior1.name, vector_warrior);
    size_t warrior2_index = find_warrior(warrior2.name, vector_warrior);
    
    if (warrior1.strength > 0 && warrior2.strength > 0
        && warrior1.strength == warrior2.strength) {
        cout << "Mutual Annihilation: " << warrior1.name;
        cout << " and " << warrior2.name;
        cout << " die at each other's " << endl;
        cout << "hands" << endl;
        vector_warrior[warrior1_index].strength = 0;
        vector_warrior[warrior2_index].strength = 0;
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
        vector_warrior[warrior1_index].strength = new_strength;
        vector_warrior[warrior2_index].strength = 0;
    }
    else if (warrior1.strength < warrior2.strength) {
        cout << warrior2.name << " defeats " << warrior1.name << endl;
        int new_strength = warrior2.strength - warrior1.strength;
        vector_warrior[warrior1_index].strength = 0;
        vector_warrior[warrior2_index].strength = new_strength;
    }
    else if (warrior1.strength == 0 && warrior2.strength == 0) {
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
}
