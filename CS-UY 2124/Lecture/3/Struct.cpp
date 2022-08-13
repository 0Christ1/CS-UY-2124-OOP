/* CS2124
  
   Struct.cpp

   Created by Christ ㅤ on 7/28/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
 
    ● grouping related values often desired
    ● vectors provide ability with restrictions (type)
    ● structs allow us to store 2 or more values together
        ○ values can be different types
        ○ names given to values for referencing
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Structures for grouping values
 
    vector<string> student_name{"Charlene", "John", "Simon", "Julie"};
 
    struct Cat {
        
        string color;
        string name;
        double weight;
};
*/
//-------------------------------------------------------------------------------------------

/* struct format
   
    ● struct: keyword indicates struct being defined
    ● StructName: name for sturct (traditionally capitalized)
    ● type_1, type_2, and type_3: type must be specified for each attribute
    ● attribute_1,...3: each value in the struct must be given an attribute name
    ● attributes: aka fields or member variables
    ● CAUTION: semicolon terminates definition (very important)

        struct StructName {
            
            type_1 attribute_1;
            type_2 attribute_2;
            type_3 attribute_3;
            ...
};
*/
//-------------------------------------------------------------------------------------------

/* Assigning struct values
 
   ● Note: dot-notation used to access attributes
 
    struct Cat {
        
        string color;
        string name;
        double weight;
    };
 
    int main() {
 
        Cat my_cat;
        my_cat.name = "Felix";
        my_cat.color = "Grey";
        my_cat.weight = 3.14;
        cout << my_cat.name << '\t' << my_cat.color << '\t' << my_cat.weight << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* Initializing struct on creation
 
   ● requires C++ 11
 
    struct Cat {                     Cat my_cat;
         
        string color;                my_cat.name = "Whiskers";
        string name;        +        my_cat.color = "brown";
        double weight;               my_cat.weight = 8;
    };
 
  |_____________________________________________________________|
                            |
 
                    struct Cat{
                        
                        string color = "brown";
                        string name = "Whiskers";
                        double weight = 8;
                    };
*/
//-------------------------------------------------------------------------------------------

/* Assigning struct objects: (sort of shallow copy in py)
 
    struct Cat {
        
        string color;
        string name;
        double weight;
    };
 
    int main() {
 
        Cat my_cat;
        my_cat.name = "Felix";
        my_cat.color = "Grey";
        my_cat.weight = 3.14;
        
        Cat jims_cat;
        jims_cat = my_cat;
}
*/
//-------------------------------------------------------------------------------------------

/* Test for equality
 
    //--------------------------------------------
    1st try:
 
        if (my_cat == jims_cat ) {     // compilation error
     
            cout << "cats are the same!" << endl;
        }
 
    //--------------------------------------------
    2nd try:

         if (my_cat.name == jims_cat.name &&                                        my_cat.color == jims_cat.color &&                                       my_cat.weight == jims_cat.weight) {   // No compilation error
      
             cout << "cats are the same!" << endl;
         }
*/
//-------------------------------------------------------------------------------------------


/* Printing structs
 
    //--------------------------------------------
    1st try: using cout
        
        struct Cat {
             
            string color;
            string name;
            double weight;
        };
 
        int main() {
 
            Cat my_cat;
            my_cat.name = "Felix";
            my_cat.color = "Grey";
            my_cat.weight = 3.14;
            cout << my_cat << endl;   // compilation error
        }
 
    //--------------------------------------------
    2nd try: using function

        struct Cat {
              
            string color;
            string name;
            double weight;
        };
 
        void print_cat(const Cat& kitty) {
       
            cout << kitty.name << ' ' << kitty.color << ' '<< kitty.weight << endl;
        }

        int main() {

            Cat my_cat;
            my_cat.name = "Felix";
            my_cat.color = "Grey";
            my_cat.weight = 3.14;
            print_cat(my_cat);        // No compilation error
}
*/
//-------------------------------------------------------------------------------------------

/* Reading struct from file
 
   ● references used for ifstream and vector parameters
   ● references used for ifstream and vector parameters
   ● assumes a file with one cat per line
       ○ components separated by space
 
           void fill_cat_vector(ifstream& in_fs, vector<Cat>& in_vec) {
                
               Cat kitty;
               while (in_fs >> kitty.name >> kitty.color >> kitty.weight) {
         
                   in_vec.push_back(kitty);
               }
            }
 
            int main() {
                ifstream catt("cat");
 
                if (!catt) {
                    cerr << "failed to open file.";
                    exit(1);
                }
 
                vector<Cat> c_vec;
                fill_cat_vector(catt, c_vec);
                catt.close();
 
                for (int i = 0; i < c_vec.size(); ++i){
 
                    cout << c_vec.at(i).name << ' ';
                    cout << c_vec.at(i).color << ' ';
                    cout << c_vec.at(i).weight << endl << endl;
                }
}
*/
//-------------------------------------------------------------------------------------------
