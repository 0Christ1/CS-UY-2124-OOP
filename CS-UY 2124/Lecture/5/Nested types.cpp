/* CS2124
  
   Nested types.cpp

   Created by Christ ㅤ on 7/31/22.

*///-----------------------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Including objects in a class
   
   ● string objects available with #include <string>
 
        class Vorlon {
 
        public:
 
            Vorlon(const string& a_name) : my_name(a_name) {}
 
            void display() {
                
                cout << "Displaying a Vorlon named: " << my_name << endl;
            }
        
        private:
 
            const string my_name;
        };
*/
//-------------------------------------------------------------------------------------------

/* Add birth date member inside private
   
    ● an isntance of a user-defined class
 
        class Vorlon {
 
        public:
 
            Vorlon(const string& a_name) : my_name(a_name) {}
 
            void display() {
                
                cout << "Displaying a Vorlon named: " << my_name << endl;
            }
        
        private:
 
            const string my_name;
            // birth date member variable
        };
*/
//-------------------------------------------------------------------------------------------

/* A Date class
 
    ● Date the_fourth(month, day, year)
 
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

/* Add birth date member inside private
   
    ● an isntance of a user-defined class
 
        class Vorlon {
 
        public:
 
            Vorlon(const string& a_name) : my_name(a_name) {}
 
            void display() {
                
                cout << "Displaying a Vorlon named: " << my_name << endl;
            }
        
        private:
 
            const string my_name;
            Date bday;   // using class Date
        };
*/
//-------------------------------------------------------------------------------------------

/* Including objects in a class
   
    ● Two options for initializing bday
        ○ pass a Date object to Vorlon constructor   // Not a good idea
        
        //-------------------------------------------
        ○ pass Date constructor values to Vorlon constructor
 
            class Date {

            public:

                Date(int month, int day, int year) : month(month), day(day), year(year) {}

                void display() {
                 
                    cout << month << '/' << day << '/' << year;
                }

            private:

                int month, day, year;
            };
 
            class Vorlon {
     
            public:
     
                Vorlon(const string& a_name, int b_month, int b_day, int b_year) : my_name(a_name), bday(b_month, b_day, b_year) {}
     
                void display() {
                    
                    cout << "Displaying a Vorlon named: " << my_name << endl;
                }
            
            private:
     
                const string my_name;
                Date bday;
            };
*/
//-------------------------------------------------------------------------------------------

/* Defining a nested class
   
    ● alternatively Date class can be defined within Vorlon class
    ● class Date ○ is private class of Vorlon
                 ○ is only accessible through Vorlon class
                     ■ must use Vorlon::Date  (:: is scope resolution operator)
 
        class Vorlon {
 
            class Date {

            public:

                Date(int month, int day, int year) : month(month), day(day), year(year) {}

                void display() {
              
                    cout << month << '/' << day << '/' << year;
                }

            private:

                int month, day, year;
            };
 
        public:
 
            Vorlon(const string& a_name, int b_month, int b_day, int b_year) : my_name(a_name), bday(b_month, b_day, b_year) {}
 
            void display() {
                
                cout << "Displaying a Vorlon named: " << my_name << endl;
            }
        
        private:
 
            const string my_name;
            Date bday;   // using class Date
        };
*/
//-------------------------------------------------------------------------------------------
