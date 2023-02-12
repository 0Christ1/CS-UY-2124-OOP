/*
 * Haoran Chen
 * rec02: Print chemical formulas
 */
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Molecular {
    vector<string> names;
    int carbon_atoms;
    int hydrogen_atoms;
};

size_t find_repeated(int carbon, int hydrogen, const vector<Molecular>& vec);
void insert_info(const string& name, int carbon, int hydrogen, vector<Molecular>& vec);
void fill_molecular_vector(ifstream& ifs, vector<Molecular>& vec);
void stream(ifstream& ifs);
void display_single_formula(const Molecular& mol);
void print_all(const vector<Molecular>& mol);
void sort(vector<Molecular>& mol);

int main() {
    vector<Molecular> mol;
    ifstream ifs;
    stream(ifs);
    fill_molecular_vector(ifs, mol);
    ifs.close();
    sort(mol);
    print_all(mol);
}

// find the repeated chemical formulas if they have the same carbon and hydrogen
size_t find_repeated(int carbon, int hydrogen, const vector<Molecular>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i].carbon_atoms == carbon && vec[i].hydrogen_atoms == hydrogen) {
            return i;
        }
    }
    return vec.size();
}

// insert the name, carbon, hydrogen into the vec
void insert_info(const string& name, int carbon, int hydrogen, vector<Molecular>& vec) {
    size_t foundIdx = find_repeated(carbon, hydrogen, vec);
    if (foundIdx < vec.size()){
        vec[foundIdx].names.push_back(name);
    } else {
        Molecular new_mol;
        new_mol.names.push_back(name);
        new_mol.carbon_atoms = carbon;
        new_mol.hydrogen_atoms = hydrogen;
        vec.push_back(new_mol);
    }
}

// fill individual variables from file ifs
void fill_molecular_vector(ifstream& ifs, vector<Molecular>& vec) {
    string name;
    char C;
    char H;
    int carbon, hydrogen;
    while (ifs >> name >> C >> carbon >> H >> hydrogen) {
        insert_info(name, carbon, hydrogen, vec);
    }
}

// let user enter the filename
void stream(ifstream& ifs) {
    cout << "Enter the filename: ";
    string filename;
    cin >> filename;
    ifs.open(filename);
    while (!ifs) {
        ifs.clear();
        cout << "Failed to open file, enter the filename: " << endl;
        cin >> filename;
        ifs.open(filename);
    }
}

// display the single formula
void display_single_formula(const Molecular& mol) {
    cout << 'C' << mol.carbon_atoms << 'H' << mol.hydrogen_atoms << ' ';
    for (size_t i = 0; i < mol.names.size(); i++) {
        cout << mol.names[i];
    }
    cout << "\n";
}

// display the whole context
void print_all(const vector<Molecular>& mol) {
    for (size_t i = 0; i < mol.size(); i++) {
        display_single_formula(mol[i]);
    }
}

// sort the whole context
void sort(vector<Molecular>& mol) {
    for (size_t i = 0; i < mol.size(); i++) {
        for (size_t j = 0; j < mol.size()-1; j++) {
            if (mol[j].carbon_atoms > mol[j+1].carbon_atoms) {
                Molecular temp = mol[j];
                mol[j] = mol[j+1];
                mol[j+1] = temp;
            }else if (mol[j].carbon_atoms == mol[j+1].carbon_atoms
            && mol[j].hydrogen_atoms > mol[j+1].hydrogen_atoms){
                Molecular temp = mol[j];
                mol[j] = mol[j+1];
                mol[j+1] = temp;
            }
        }
    }
}

