/* CS2124
  
   Encapsulation.cpp

   Created by Christ ㅤ on 7/30/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
 
    Encapsulation: ● Bundling of data and methods that operate on the data into                                                                                                          a single structure preventing unwanted or unintended modification
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Encapsulation
   
   ● display(): method
   ● my_name: data

        class Vorlon {

        public:

            Vorlon(const string& a_name){my_name = a_name;}

            Vorlon() {}

            void display() const {
     
                cout << "Displaying a Vorlon named " << my_name << endl;
            }

        private:

            const string my_name;
        };
*/
//-------------------------------------------------------------------------------------------

/* Consequences of encapsulation
   
    //--------------------------------------------
    struct Cat
    
    ● kitty.name, kitty.color, kitty.weight: direct access to Cat member variables

        struct Cat {
 
            string color;
            string name;
            double weight;
        };

        void fill_cat_vector(ifstream& in_fs, vector<Cat>& in_vec) {
 
            Cat kitty;
 
            while (in_fs >> kitty.name >> kitty.color >> kitty.weight) {
            
                in_vec.push_back(kitty);
            }
        }
 
    //--------------------------------------------
    struct Cat convert to class Cat with compile error
    
        class Cat{
     
        public:
 
            Cat(const string& the_name, const string& the_color, const double& the_weight): name(the_name), color(the_color), weight(the_weight) {}
     
            void display() const {
     
                cout << "Displaying a Cat named " << name;
                cout << " with color " << color;
                cout << " and weight " << weight << endl;
            }
        
        private:
     
            string name;
            string color;
            double weight;
        };
     
        void fill_cat_vector(ifstream in_fs, vector<Cat> in_vec) {
     
            Cat kitty;  // Compile error
     
            while (in_fs >> kitty.name >> kitty.color >> kitty.weight) {  // Compile error
                
                in_vec.push_back(kitty);
            }
        }
 
    //--------------------------------------------
    struct Cat convert to class Cat without compile error

        class Cat{

        public:

            Cat(const string& the_name, const string& the_color, const double& the_weight): name(the_name), color(the_color), weight(the_weight) {}

            void display() const {

                cout << "Displaying a Cat named " << name;
                cout << " with color " << color;
                cout << " and weight " << weight << endl;
            }
         
        private:

            string name;
            string color;
            double weight;
        };

        void fill_cat_vector2(ifstream in_fs, vector<Cat> vc) {

            string;         // used to read in the name
            string color;   // used to read in the color
            double weight;  // used to read in the weight

            while (in_fs >> name >> color >> weight) {
                 
                Cat a_cat(name, color, weight);     //Cat object defined inside loop
                vc.push_back(a_cat);
            }
        }
        
        void display_cat_vector(const vector<Cat>& cat_vec) {
        
            for  (size_t i = 0; i < cat_vec.size(); i++) {
 
                cat_vec[i].display();    //vector passed as const reference
            }
        }
*/
//-------------------------------------------------------------------------------------------

/* Encapsulation : complete code

    class Cat{

    public:

        Cat(const string& the_name, const string& the_color, const double& the_weight): name(the_name), color(the_color), weight(the_weight) {}

    void display() const {

        cout << "Displaying a Cat named " << name;
        cout << " with color " << color;
        cout << " and weight " << weight << endl;
    }

    private:

        string name;
        string color;
        double weight;
    };

    void fill_cat_vector2(ifstream in_fs, vector<Cat> vc) {

        string;
        string color;
        double weight;

        while (in_fs >> name >> color >> weight) {
          
            Cat a_cat(name, color, weight);
            vc.push_back(a_cat);
        }
    }

    void display_cat_vector(const vector<Cat>& cat_vec) {

        for (size_t i = 0; i < cat_vec.size(); i++) {

            cat_vec[i].display();
        }
    }
 
    int main() {
        
        ifstream catt("cat.txt");
     
        if (!catt) {
         
            cerr << "failed to open file." << endl;
            exit(1);
        }
     
        vector<Cat> vec;
        fill_cat_vector2(catt, vec);
        display_cat_vector(vec);
        catt.close();
}
*/
//-------------------------------------------------------------------------------------------
