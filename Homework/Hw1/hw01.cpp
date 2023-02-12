/*  CS-UY 2124
    hw01: Caesar Cypher
    Task: Given an encrypted file that needs to decrypt and print it out reversely.
    Created by Haoran Chen on 9/6/22.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


// Function prototype
char decrypted_letter(char letter, int step);
void modified_line(string& line, int step);

int main() {
    // Reading file
    ifstream ifs("encrypted.txt");
    if (!ifs) { cerr << "Failed to open the file encrypted.txt."; exit(1); }
    
    // Obtaining the number of steps
    int step;
    ifs >> step;
    
    // Creating vector of lines
    string line;
    vector<string> lines;
    while (getline(ifs, line)) {
        modified_line(line, step);
        lines.push_back(line);
    }
    
    // Printing it reversely
    for (size_t i = lines.size()-1; i > 0; i--) cout << lines[i]<< endl;
}

// Decrypting the letter via step
char decrypted_letter(char letter, int step) {
    step = step % 26;
    if (letter >= 'A' && letter <= 'Z'){
        char rotate = letter - step;
        if (rotate < 'A')
            rotate += 26;
        if (rotate > 'Z')
            rotate -= 26;
        return rotate;
    }
    return letter;
}

// Modifying the line
void modified_line(string& line, int step) {
    for (size_t i = 0; i < line.size(); i++)
        line[i] = decrypted_letter(line[i], step);
}
