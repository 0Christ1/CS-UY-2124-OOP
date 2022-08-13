/* CS2124
  
   Classes.cpp

   Created by Christ ㅤ on 7/29/22.

*///-----------------------------------------------------------------------------------------


#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* class format (1)
   
    ● class: keyword indicates class being defined
    ● ClassName: name for class (traditionally capitalized)
    ● [;] semicolon terminates (very important)

        class ClassName {
   
            // class details
        };
*/
//-------------------------------------------------------------------------------------------

/* A minial class
   
    ● full class definition -- code will compile
    ● sim: ○ it is a variable with type Simplest
           ○ it is an object created using a default constructor

               class Simplest {};
   
               int main() {
            
                   Simplest sim;
}
*/
//-------------------------------------------------------------------------------------------

/* class format (2)
   
    ● any members defined in public interface accessible without restriction

        class ClassName {
   
        public:
            
            // public interface
        };
*/
//-------------------------------------------------------------------------------------------

/* A (slightly) more useful class
   
    ● display(): member function (method)

        class Simple {
 
        public:
 
            void display() {
    
                cout << "Displaying a Simple object\n";
            }
        };

        int main() {

            Simplest sim;
            sim.display();
}
*/
//-------------------------------------------------------------------------------------------

/* Invoking an object method
   
    ● current object "sim" : the specific object on which the method is being invoked
    ● dot operator "." : invoke object method
    ● (): open and close parenthesis

        class Simple {
 
        public:
 
            void display() {
    
                cout << "Displaying a Simple object\n";
            }
        };

        int main() {

            Simplest sim;
            sim.display();
}
*/
//-------------------------------------------------------------------------------------------

/* Differentiating class objects
   
    ● my_name: it has no protection from modification

        class Vorlon {
 
        public:
 
            void display() {
    
                cout << "Displaying a Vorlon named " << my_name << endl;
            }
            string my_name;
        };

        int main() {

            Vorlon v1;
            v1.my_name = "Kosh";
            v1.display();
        }
 
     //--------------------------------------------
     What about my_name allows it's value to be modified without restrictions?
 
     ● cannot access private member variable my_name
 
         class Vorlon {

         public:

             void display() {

                 cout << "Displaying a Vorlon named " << my_name << endl;
             }
 
         private:
 
             string my_name;
         };

         int main() {

             Vorlon v1;
             v1.my_name = "Kosh";   // Compilation ERROR!
             v1.display();
}
*/
//-------------------------------------------------------------------------------------------

/* class format (3)
   
    ● private members have restricted access

        class ClassName {
   
        public:
            
            // public interface
        
        private:
 
            // private interface
        };
*/
//-------------------------------------------------------------------------------------------

/* Differentiating class objects
 
    ● One solution: add a public method to set Vorlon name

        class Vorlon {
 
        public:
 
            void display() {
    
                cout << "Displaying a Vorlon named " << my_name << endl;
            }
        
            void set_name(string name) {my_name = name;}
 
        private:
 
            string my_name;
        };

        int main() {

            Vorlon v1;
            v1.set_name("Kosh");    // No compilation error
            v1.display();
        }
*/
//-------------------------------------------------------------------------------------------
