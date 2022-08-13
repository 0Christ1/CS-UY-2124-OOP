/* CS2124
  
   OOP Practice.cpp

   Created by Christ ㅤ on 7/31/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
 
    Defining a default constructor:
    ● including a default constructor should be conscious choice
        ○ should it be possible to create a Cat or Vorlon without a name?
            ■ Yes: default constructor may be appropriate
            ■ No: require that a name is provided in constructor
    ● constructor needs to be defined for proper initialization
        ○ "proper" has different meanings for different classes
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Defining a default constructor

    //--------------------------------------------
    1st step: compilation errors
              
        class Cat {

        public:
            
            Cat(const string& the_name, const string& the_color, double the_weight) :        name(the_name), color(the_color), weight(the_weight) {}
 
            void display() const {
        
                cout << "Displaying a Cat named" << name;
                cout << " with color " << color;
                cout << " and weight " << weight << endl;
            }
 
        private:

            string name;
            string color;
            double weight;
        };

        void fill_cat_vector(ifstream& in_fs, vector<Cat>& in_vec) {
        
            Cat kitty;  // compilation error

            while (in_fs >> kitty.name >> kitty.color >> kitty.weight) { // compile error
            
                in_vec.push_back(kitty);
            }
        }
 
    //--------------------------------------------
    2nd step: ● solve the first compilation error
                  ○ add a default constructor
 
        class Cat {

        public:

        Cat(const string& the_name, const string& the_color, double the_weight) :        name(the_name), color(the_color), weight(the_weight) {}

        Cat () {}
 
        void display() const {

           cout << "Displaying a Cat named" << name;
           cout << " with color " << color;
           cout << " and weight " << weight << endl;
        }

        private:

            string name;
            string color;
            double weight;
        };

        void fill_cat_vector(ifstream& in_fs, vector<Cat>& in_vec) {

            Cat kitty; // No compilation error

            while (in_fs >> kitty.name >> kitty.color >> kitty.weight) { // compile error

                in_vec.push_back(kitty);
            }
        }
 
    //--------------------------------------------
    3rd step: still remain the second compilation error
              ●
 
        class Cat {

        public:

        Cat(const string& the_name, const string& the_color, double the_weight) :        name(the_name), color(the_color), weight(the_weight) {}

        Cat () {}
 
        void display() const {

           cout << "Displaying a Cat named" << name;
           cout << " with color " << color;
           cout << " and weight " << weight << endl;
        }

        private:

            string name;
            string color;
            double weight;
        };

        void fill_cat_vector(ifstream& in_fs, vector<Cat>& in_vec) {
 
            Cat kitty;

            while (in_fs >> kitty.name >> kitty.color >> kitty.weight) { // compile error

             in_vec.push_back(kitty);
        }
*/
//-------------------------------------------------------------------------------------------

/* Class design decisions

    //--------------------------------------------
    1st step: ● empty string for name is no better than not providing a name
              ● fill_vector() should not be a Vorlon method
              
        Vorlon temp ("");
        ifstream ifs("vorlons.txt");
        vector<Vorlon> vor_vec;
        temp.fill_vector(vor_vec, ifs);
 
 
    //--------------------------------------------
    2nd step: ● no need for temp Vorlon
 
        ifstream ifs("vorlons.txt");
        vector<Vorlon> vor_vec;
        fill_vector(vor_vec, ifs);  // stand-alone function
 
 
    //--------------------------------------------
    3rd step: ● may wnat to allow Vorlons to marry
              
        Vorlon temp(""), kosh("Kosh"), koshina("Koshina");
        temp.marry(kosh, koshina);
 
 
    //--------------------------------------------
    4th step: ● role/neccessity of Vorlon temp in marriage unclear
           
        Vorlon kosh("Kosh"), koshina("Koshina");
        kosh.marry(koshina);
 
*/
//-------------------------------------------------------------------------------------------
