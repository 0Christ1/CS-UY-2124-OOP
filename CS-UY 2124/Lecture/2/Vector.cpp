/* CS2124
  
   Vector.cpp

   Created by Christ ㅤ on 7/29/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
 
    ● available after #include <vector>
    ● full name: std::vector<type>
    ● similar to Python list and Java's ArrayList
    ● generic type
    ● other useful methods:
        ○ back()
        ○ pop_back()
        ○ capacity()
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Collections: Vector
 
       int main() {
 
           // vec can ONLY hold integers
           vector<int> vec;
           cout << "vec.size(): " << vec.size() << "\n" << endl;
           vec.push_back(17);
           vec.push_back(42);
           cout << "vec.size(): " << vec.size() << "\n" << endl;

           for (size_t i = 0; i < vec.size(); ++i) {
 
               cout << vec[i] << ' ';
           }
           cout << endl;
           vec.clear();
           vec.pop_back();
           vec.pop_back();
           cout << "vec.capacity(): " << vec.capacity() << "\n" << endl;
 
           for (size_t i = 0; i < vec.size(); ++i) {
 
               cout << vec[i] << ' ';
           }
           cout << "\n" << endl;
           cout << "vec.capacity(): " << vec.capacity() << "\n" << endl;
           cout << "vec.size(): " << vec.size() << "\n" << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* Collections: Vector Initialization
 
   ● Initialize the size of the vetcor and the value of that all the entries will start with
   ● The vector v1 will be of size 7, with every entry = 42
   ● specify the distinct values to initialize each entry to
 
       int main() {
 
           vector<int> vec1(7, 42);   // parentheses
           vector<int> vec2{1, 1, 2, 3, 5, 8, 13, 21}; // curly braces
}
*/
//-------------------------------------------------------------------------------------------

/* What is the value of vec1[3] ?  // 42
 
      int main() {
 
           vector<int> vec1(7, 42);   // parentheses
           vector<int> vec2{1, 1, 2, 3, 5, 8, 13, 21}; // curly braces
           cout << "vec1[3]: " << vec1[3] << "\n " << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* What is the value of vec2[3] ?  // 3

      int main() {
 
           vector<int> vec1(7, 42);   // parentheses
           vector<int> vec2{1, 1, 2, 3, 5, 8, 13, 21}; // curly braces
           cout << "vec2[3]: " << vec2[3] << "\n " << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* Loops: two ways of ranged for

   //---------------------------------------
   1st way:
 
      int main() {
 
          vector<int> vec;
          vec.push_back(10);
          vec.push_back(9);
          vec.push_back(8);
          vec.push_back(7);
          for (size_t i = 0; i < vec.size(); i++) {
 
              cout << vec[i] << ' ';
          }
          cout << endl;
 
   //---------------------------------------
   2nd way:

    int main() {

        vector<int> vec;
        vec.push_back(10);
        vec.push_back(9);
        vec.push_back(8);
        vec.push_back(7);
        for (int value : vec){

            cout << value << ' ';
        }
        cout << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* What is the output ?  // 3

      int main() {
 
           vector<int> vec{2, 3, 5, 7, 11};
           for (int value : vec) {
 
               value = 42;
           }
           
           for (int value : vec) {
 
               cout << value << ' ';
           }
           cout << endl;
}
*/
//-------------------------------------------------------------------------------------------
