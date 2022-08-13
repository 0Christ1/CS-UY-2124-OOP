/* CS2124
  
   ICP5 Person.cpp

   Created by Christ ㅤ on 7/31/22.

*///-----------------------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Outputting objects
   
    class Person {

    public:

        Person(const string& the_name) : name(the_name) {}

        void eat() const { cout << name << " eating\n"; }

        void set_name(const string& the_name) { name = the_name; }

    private:

        string name;
        // member variable to track birthday
    };

    int main() {

        Person john("john");
        // output John's name and birthday
    }
*/
//-------------------------------------------------------------------------------------------

/* Outputing objects
 
    class Date {

    public:

        Date(int month, int day, int year) : month(month), day(day), year(year) {}

        void display() {
            
            cout << month << '/' << day << '/' << year;
        }
    
    private:

        int month, day, year;
    };
*/
//-------------------------------------------------------------------------------------------

/* Outputting objects
   
    //--------------------------------------------
    1st step: ● add the Date dob but compilation error
              ● print john but compilation error
 
        class Person {

        public:

            Person(const string& the_name) : name(the_name) {}

            void eat() const { cout << name << " eating\n"; }

            void set_name(const string& the_name) { name = the_name; }

        private:

            string name;
            Date dob;               // Compilation error
        };

        int main() {

            Person john("john");
            cout << john << endl;   // Compilation error
        }
 
    //--------------------------------------------
    2nd step: ● fix the compilation error of Date dob
                  ○ add Date parameters inside Person constructor
 
              ● fix the compilation error of printing john
                  ○ using operator << function

        class Date {
        
            friend ostream& operator << (ostream& os, const Date& rhs) {
            
                os << rhs.month << '/' << rhs.day << '/' << rhs.year;
                return os;
            }

        public:

            Date(int month, int day, int year) : month(month), day(day), year(year) {}

        private:

            int month, day, year;
        };
 
        class Person {
        
            friend ostream& operator << (ostream& os, const Person& rhs) {
            
                os << "Person name = " << rhs.name << " dob = " << rhs.dob << endl;
                return os;
            }

        public:

            Person(const string& the_name, int b_month, int b_day, int b_year) : name(the_name), dob(b_month, b_day, b_year) {}

            void eat() const { cout << name << " eating\n"; }

            void set_name(const string& the_name) { name = the_name; }

        private:

            string name;
            Date dob;      // No compilation error
        };

        int main() {

            Person john("John", 7, 14, 1920);   // change parameters
            cout << john << endl;               // No compilation error
        }
*/
//-------------------------------------------------------------------------------------------
