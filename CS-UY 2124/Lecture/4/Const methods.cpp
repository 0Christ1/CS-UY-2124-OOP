/* CS2124
  
   Const methods.cpp

   Created by Christ ㅤ on 7/30/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
 
    Passing an object to a function (review)
    ● Pass-by-value
        ○ param value is a copy of object  [wastes resources]
    ● Pass-by-reference
        ○ param value is the object  [sometimes useful but requires care]
    ● Pass-by-constant-reference
        ○ param value is the (immutable) object  [safe and efficient]
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Implications of pass-by-constant-reference
 
    ● simple_function has declared not to modify fred
    ● display method makes no promise to leave object unchanged
 
        void simple_function(const Vorlon& fred) {
     
            fred.display();  // Compile error
        }

        class Vorlon {

        public:

            Vorlon(const string& a_name){my_name = a_name;}

            Vorlon() {}

            void display() {
     
                cout << "Displaying a Vorlon named " << my_name << endl;
            }

        private:

            const string my_name;
        };
*/
//-------------------------------------------------------------------------------------------

/* Const: a non-modification guarantee
    
    //--------------------------------------------
    Wrong way: compile error
 
        class Vorlon {

        public:

            Vorlon(const string& a_name){my_name = a_name;}

            Vorlon() {}

            void display() {
     
                cout << "Displaying a Vorlon named " << my_name << endl;
            }

        private:

            const string my_name;
        };
 
        void simple_function(const Vorlon& fred) {
         
            fred.display(); // No compile error
        }
 
    //--------------------------------------------
    const method: ● indicates that function will not modify current object
                      ○ const keyword located after parameter list
                      ○ const keyword located before function body
    ● Important: mark methods as const when no current object members modified
 
        class Vorlon {

        public:

            Vorlon(const string& a_name){my_name = a_name;}

            Vorlon() {}

            void display() {

                cout << "Displaying a Vorlon named " << my_name << endl;
            }

        private:

            const string my_name;
        };
 
        void simple_function(const Vorlon& fred) {
        
            fred.display(); // No compile error
        }
*/
//-------------------------------------------------------------------------------------------
