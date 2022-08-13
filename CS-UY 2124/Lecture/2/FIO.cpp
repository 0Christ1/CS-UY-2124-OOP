/* CS2124
  
   FIO.cpp

   Created by Christ ㅤ on 7/27/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
    
    ● fstream: used for working with file
    ● ifstream: used for working with input file
    ● full name: std::ifstream
    ● functionality includes:
        ○ opening and closing files
        ○ testing for successful open
        ○ reading input
        ○ looping over lines in a file
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//-------------------------------------------------------------------------------------------

/* File input example: read token
 
       int main() {
 
           ifstream jab("jabberwocky");
           if (!jab) {
 
               cerr << "failed to open jabberwocky\n\n";
               exit(1);
           }
 
           string something;
           jab >> something;
           cout << something << "\n" << endl;
           jab.close();
}
*/
//-------------------------------------------------------------------------------------------

/* File input example: read line
 
       int main() {
 
           ifstream jab("jabberwocky");
           if (!jab) {
 
               cerr << "failed to open jabberwocky\n\n";
               exit(1);
           }
 
           string something;
           getline(jab, something);
           cout << something << "\n" << endl;
           jab.close();
}
*/
//-------------------------------------------------------------------------------------------

/* File input example: read token by token
 
   ● read operation located in while condition
   ● loop stops when nothing left to read
   ● each read operations gets the next whitespace delimited token
       ○ ' '(space)
       ○ \n (newline)
       ○ \t (tab)
 
           int main() {
     
               ifstream jab("jabberwocky");
               if (!jab) {
     
                   cerr << "failed to open jabberwocky\n\n";
                   exit(1);
               }
     
               string something;
               while (jab >> something) {
     
                   cout << something;
               }
     
               cout << endl;
               jab.close();
}
*/
//-------------------------------------------------------------------------------------------

/* File input example: creating a vector of lines
   
   ● test of open omitted to save space
   ● file closed as soon as contents read
   ● while loop continues so long as getline() successfully extracts line
   ● full name: std::getline()
 
       int main() {
 
           ifstream jab("jabberwocky");
           if (!jab) {
 
               cerr << "failed to open jabberwocky\n\n";
               exit(1);
           }
 
           string line;
           vector<string> lines;
           while (getline(jab, line)) {
 
               lines.push_back(line);
           }
           jab.close();
 
           for (size_t i=0; i < lines.size(); ++i) {          //positive order
 
               cout << lines[i] << endl;
           }
           cout << endl;

           for (size_t i = lines.size(); i > 0; --i) {        //inverted order
 
               cout << lines[i-1] << endl;
           }
           cout << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* File input example: accessing each character in line
 
       int main() {
 
           ifstream jab("jabberwocky");
           if (!jab) {
 
               cerr << "failed to open jabberwocky\n\n";
               exit(1);
           }
 
           string line;
           vector<string> lines;
           while (getline(jab, line)) {
 
               lines.push_back(line);
           }
           jab.close();
 
           for (size_t i=0; i < lines.size(); ++i) {
 
               for (size_t j = 0; j < lines[i].size(); ++j) {
      
                   cout << lines[i][j] << ' ';
               }
           }
           cout << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* 2D vector of vectors
 
   ● filling 2d “matrix” with values from 0 to 99
   ● constants commonly in all caps
   ● Note: vector created and pushed onto mat
 
       int main() {
 
           const int ROWS = 10;
           const int COLS = 10;
           vector<vector<int>> mat;
           
           for (int row = 0; row < ROWS; row++) {
     
               mat.push_back(vector<int>(COLS));
               for (int col = 0; col < COLS; col++) {
               
                   mat[row][col] = row * ROWS + col;
               }
           }
 
           for (int row = 0; row < ROWS; row++) {
 
               for (int col = 0; col < COLS; col++) {
               
                   cout << mat[row][col] << ' ';
               }
               cout << endl;
           }
}
*/
//-------------------------------------------------------------------------------------------
