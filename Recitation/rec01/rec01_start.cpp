// rec01_start.cpp
// 2124 22F

#include <iostream>    // Tasks 3, 4, 5 and 6
#include <fstream>     // Task 4, 5 and 6
#include <string>      // Task 5
#include <vector>      // Task 8, 9
using namespace std;

int main() {
    // Task 3
    cout << "Task 3\n========\n";
    cout << "Bonjour CS2124!!!";

    // Task 4
    cout << "\nTask 4\n========\n";
    ifstream ifs("integers.txt");
    if (!ifs) {
        cerr << "Failed to open integer.txt file.";
        exit(1);
    }
    int nums;
    int total = 0;
    while (ifs >> nums) {
        total += nums;
    }
    cout << total;
    ifs.close();
    
    // Task 5
    cout << "\nTask 5\n========\n";
    ifstream ifs2("text.txt");
    if (!ifs2) {
        cerr << "Failed to open text.txt file.";
        exit(1);
    }
    string word;
    while (ifs2 >> word) {
        cout << word << endl;
    }
    ifs2.close();

    // Task 6
    cout << "Task 6\n========\n";
    ifstream ifs3("mixed.txt");
    if (!ifs3) {
        cerr << "Failed to open mixed.txt file.";
        exit(1);
    }
    int nums2;
    int total2 = 0;
    while (ifs3 >> nums2) {
        total2 += nums2;
    }
    cout << total2 << endl;     //total2 is 15 because it stopped reading while the context is string
    ifs3.close();
    
    //Task 7        just for fun
    cout << "Task 7\n========\n";
    ifstream ifs4("text.txt");
    if (!ifs4) {
        cerr << "Failed to open text.txt file.";
        exit(1);
    }
    string line;
    getline(ifs4, line);
    cout << "Read a line of text" << line << "\n";
    ifs4.close();
    
    //Task 8   just for fun
    cout << "Task 8\n========\n";
    ifstream ifs5("text.txt");
    if (!ifs5) {
        cerr << "Failed to open text.txt.";
        exit(1);
    }
    string line2;
    vector<string> lines;
    while (getline(ifs5, line2)) {
        lines.push_back(line2);
    }
    ifs5.close();
    cout << "in order of context: " << endl;
    for (size_t i = 0; i<lines.size(); i++) {
        cout << lines[i] << endl;
    }
    cout << "\nreverse order of context: " << endl;
    for (size_t i = lines.size(); i > 0; i--) {
        cout << lines[i-1] << endl;
    }
    
    //Task 9        just for fun
    cout << "Task 9\n========\n";
    ifstream ifs6("text.txt");
    if (!ifs6) {
        cerr << "Failed to open text.txt.";
        exit(1);
    }
    string line3;
    vector<string> lines2;
    while (getline(ifs6, line3)){
        lines2.push_back(line3);
    }
    ifs6.close();
    cout << "accessing each character in line: " << endl;
    for (size_t i = 0; i < lines.size(); i++) {
        for (size_t j = 0; j < lines[i].size(); j++) {
            cout << lines[i][j] << ' ';
        }
    }
    cout << endl;
}
