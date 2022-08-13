/* CS2124
  
   The << operator.cpp

   Created by Christ ㅤ on 7/31/22.

*///-----------------------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Printing structs
   
   ● will learn implementation later

        struct Cat {
 
            string color = "brown";
            string name = "Charlie";
            double weight = 6.5;
        };
 
        void print_cat(const Cat& kitty) {
 
            cout << kitty.name << ' ' << kitty.color << ' ' << kitty.weight << endl;
        }
 
        int main() {
 
            Cat my_cat;

            cout << my_cat << endl;  // compilation error
}
*/
//-------------------------------------------------------------------------------------------

/* Object output
   
    class Cat {

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
 
    //--------------------------------------------
    1st way:
    
        int main() {
    
            Cat my_cat("Whiskers", "brown", 8);
            my_cat.display();
        }
 
    //--------------------------------------------
    2nd way:

     int main() {

         Cat my_cat("Whiskers", "brown", 8);
         cout << my_cat << endl;    // compilation error
     }
*/
//-------------------------------------------------------------------------------------------

/* The output operator <<
   
    ● solution for the 2nd way

    //--------------------------------------------
    1st step: ● delete display() function
              ● add new things
 
        class Cat {

        public:

            Cat(const string& the_name, const string& the_color, const double& the_weight): name(the_name), color(the_color), weight(the_weight) {}

        private:

            string name;
            string color;
            double weight;
        };
        
        ostream& operator << () {}
 
    //--------------------------------------------
    2nd step: ● complete the operator

        class Cat {

        public:

            Cat(const string& the_name, const string& the_color, const double& the_weight): name(the_name), color(the_color), weight(the_weight) {}

        private:

            string name;
            string color;
            double weight;
        };

        ostream& operator << (ostream& os, const Cat& rhs) {
            
            os << "Displaying a Cat named " << rhs.get_name();        // compilation error
            os << " with color " << rhs.get_color();                  // compilation error
            os << " and weight " << rhs.get_weight() << "." << endl;  // compilation error
            return os;
        }
 
    //--------------------------------------------
    3rd step: ● fix the compilatin error
                  ○ add accessor methods: get_..()
                      ■ const + & avoids making copy of string

        class Cat {

        public:

            Cat(const string& the_name, const string& the_color, const double& the_weight): name(the_name), color(the_color), weight(the_weight) {}
            const string& get_name() const { return name; }
            const string& get_color() const { return color; }
            double get_weight() const { return weight; }
  
        private:

            string name;
            string color;
            double weight;
        };

        ostream& operator << (ostream& os, const Cat& rhs) {   // No compilation error
         
            os << "Displaying a Cat named " << rhs.get_name();
            os << " with color " << rhs.get_color();
            os << " and weight " << rhs.get_weight() << "." << endl;
            return os;
        }
*/
//-------------------------------------------------------------------------------------------

/* The output operator << format
   
    ● return type is ostream& (ostream reference)
    ● first parameter is ostream&
    ● second parameter is const Cat& (const Cat reference)

        ostream& operator << (ostream& os, const Cat& rhs {
            
            // output Cat rhs to ostream
            // return modified ostream
        }
*/
//-------------------------------------------------------------------------------------------

/* Friend status
    ● effectiver way than accessr methods

    //--------------------------------------------
    1st step: ● delete all accessor methods
 
        class Cat {

        public:

            Cat(const string& the_name, const string& the_color, const double& the_weight): name(the_name), color(the_color), weight(the_weight) {}

        private:

            string name;
            string color;
            double weight;
        };

        ostream& operator << (ostream& os, const Cat& rhs) {   // No compilation error

            os << "Displaying a Cat named " << rhs.___;
            os << " with color " << rhs.___;
            os << " and weight " << rhs.___ << "." << endl;
            return os;
        }
 
    //--------------------------------------------
    2nd step: add ostream function prototype before public

        class Cat {
 
            ostream& operator << (ostream&, const Cat&); // function prototype

        public:

            Cat(const string& the_name, const string& the_color, const double& the_weight): name(the_name), color(the_color), weight(the_weight) {}

        private:

            string name;
            string color;
            double weight;
        };

        ostream& operator << (ostream& os, const Cat& rhs) {   // No compilation error

            os << "Displaying a Cat named " << rhs.___;
            os << " with color " << rhs.___;
            os << " and weight " << rhs.___ << "." << endl;
            return os;
        }
 
    //--------------------------------------------
    3rd step: ● give function prototype access to Cat's private member variables (friend)
              ● function modifier not a return type

        class Cat {

            friend ostream& operator << (ostream&, const Cat&); // function prototype

        public:

            Cat(const string& the_name, const string& the_color, const double& the_weight): name(the_name), color(the_color), weight(the_weight) {}

        private:

            string name;
            string color;
            double weight;
        };

        ostream& operator << (ostream& os, const Cat& rhs) {

            os << "Displaying a Cat named " << rhs.name;
            os << " with color " << rhs.color;
            os << " and weight " << rhs.weight << "." << endl;
            return os;
        }
*/
//-------------------------------------------------------------------------------------------
