/* CS2124
  
   Nested types 2.cpp

   Created by Christ ㅤ on 8/3/22.

*///-----------------------------------------------------------------------------------------


#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Nested types: composition vs association
   
    ● Goal: bind objects together
        ○ racall Person/Date relationship for composition
 
         Composition            association
         ___________            ___________
        |Foo        |          |Foo        |
        |___________|          |           |           _____________
        |Bar        |          |___________|          |Bar          |
        |___________|          |__Bar*_____|--------->|             |
        |Foo        |          |           |          |_____________|
        |___________|          |___________|
*/
//-------------------------------------------------------------------------------------------

/* Composition
                                                         ___________
    consequences of design choice:                      |Foo        |
        ● creation of Foo creates Bar                   |___________|
        ● destorying Foo destorys Bar                   |Bar        |
        ● Foo stuck with bar once created               |___________|
        ● Bar cannot be shared                          |Foo        |
        ● Foo size impacted by Bar size                 |___________|
 
    //--------------------------------------------
    1st step: draft of code
 
        class Bar {}; // Not interested Bar details for now
    
        class Foo {
    
        public:
    
             ... // ignoring details
                        
        private:
                
            Bar my_bar;  // Every Foo has a Bar
            int some_other_data;
        };
 
    //--------------------------------------------
    2nd step: modifiy the code
        ● Question: how do we include a Foo inside of another Foo ?

        class Foo {

        public:

            ... // ignoring details
                     
        private:
             
            int some_other_data;
        };
*/
//-------------------------------------------------------------------------------------------

/* Association
                                                         ___________
    consequences of design choice:                      |Foo        |
        ● Associate Bar with Foo on-demand              |           |           _____________
        ● destorying Bar independently                  |___________|          |Bar          |
        ● Foo not stuck with the same bar               |__Bar*_____|--------->|             |
        ● multiple Foos can share Bar                   |           |          |_____________|
        ● Foo can exist without Bar association         |___________|
            ○ my_bar = nullptr;
 
            class Bar {};

            class Foo {

            public:

                 ... // ignoring details
                            
            private:
                    
                Bar* my_bar;  // pointer to Bar
                int some_other_data;
            };
*/
//-------------------------------------------------------------------------------------------

/* Defining a nested class (elaboration)
   
    ● Date is only accessible through Vorlon class
        ○ Date is private class of Vorlon
        ○ must use Vorlon::Date
            ■ :: is scope resolution operator
 
        //--------------------------------------------
        1st step: add birthday info ouput inside display() function (compilation error)
 
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
     
                void display() {    // compilation error
                    
                    cout << "Displaying a Vorlon named: " << my_name << endl;
                    cout << "Born on" << bday.month << '/' << bday.day << '/' << bday.year;
                }
            
            private:
     
                const string my_name;
                Date bday;   // using class Date
            };
 
        //--------------------------------------------
        2nd step: fix the compilation error via adding friend Vorlon ahead

            class Vorlon {

                class Date {
        
                    friend Vorlon;

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

                void display() {    // No compilation error
                 
                    cout << "Displaying a Vorlon named: " << my_name << endl;
                    cout << "Born on" << bday.month << '/' << bday.day << '/' << bday.year;
                }
         
            private:

                const string my_name;
                Date bday;   // using class Date
            };
*/
//-------------------------------------------------------------------------------------------
