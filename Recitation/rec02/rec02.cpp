//
//  rec02.cpp
//  CS-UY 2124
//
//  Created by Haoran Chenㅤ on 9/9/22.
//  conway's game of life
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream ifs("life.txt");
    if (!ifs) {
        cerr << "Failed to open file life.txt.";
        exit(1);
    }
    
    cout << "Initial world" << endl;
    string cells;
    vector<string> old_matrix;
    while (getline(ifs, cells)){
        old_matrix.push_back(cells);
    }
    ifs.close();

    for (size_t i = 0; i < old_matrix.size(); i++) {
        cout << old_matrix[i] << endl;
    }
    cout << "===========================" << endl;

    
    // Get original hight and width
    size_t ROWS = old_matrix.size();
    size_t COLS = old_matrix[0].size();
    
    // 10 generations
    for (int i = 1; i <= 10; i++) {
        cout << "Generation: " << i << endl;
        
        // Creating a buffer matrix
        vector<string> new_matrix = old_matrix;
        
        // Calculate the alive cells in the new_matrix
        for (size_t row = 0; row < ROWS; row++) {
            for (size_t col = 0; col < COLS; col++) {
                int Alive = 0;
                
                // Test for left and right neighbor
                if (col > 0 && old_matrix[row][col-1] == '*') Alive += 1;
                if (col < COLS-1 && old_matrix[row][col+1] == '*') Alive += 1;
                // Test for above and below neighbor
                if (row > 0 && old_matrix[row-1][col] == '*') Alive += 1;
                if (row < ROWS-1 && old_matrix[row+1][col] == '*') Alive += 1;
    
                // Test for above left and above right
                if (row > 0 && col > 0 && old_matrix[row-1][col-1] == '*') Alive += 1;
                if (row > 0 && col < COLS-1 && old_matrix[row-1][col+1] == '*') Alive += 1;
                   
                // Test for below left and below right
                if (row < ROWS-1 && col > 0 && old_matrix[row+1][col-1] == '*') Alive += 1;
                if (row < ROWS-1 && col < COLS-1 && old_matrix[row+1][col+1] == '*') Alive += 1;
            
                // Alive cell with fewer than 2 alive neighbors would die from loneliness or overcrowding
                if (old_matrix[row][col] == '*' && (Alive < 2 || Alive > 3))
                    new_matrix[row][col] = '-';
                // Empty/Dead cell with 3 alive neighbors would revive in the next generation
                if (old_matrix[row][col] == '-' && Alive == 3)
                    new_matrix[row][col] = '*';
                
            }
        }
        
        for (size_t g = 0; g < new_matrix.size(); g++) {
            cout << new_matrix[g] << endl;
        }
        
        old_matrix = new_matrix;
        
        cout << "====================" << endl;
    }
}
