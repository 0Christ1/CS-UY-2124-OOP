/* CS2124
 
  Pointers and objects.cpp

  Created by Christ ㅤ on 8/2/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
 
   Symbols: ● &  : address operator
            ● *  : address pointer
            ● -> : arrow operator
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Access object member via pointers
  
   ● dot (.) higher precedence than dereference (*)
   
   //-------------------------------------------
   1st step, display george using ptr (compilation error)

       class Person {
    
       public:
    
           Person(const string& name) : name(name) {}
           void display() {

               cout << "Name: " << name << endl;
           }
    
       private:
    
           string name;
       };

       int main() {
    
           Person george("George");
           Person* ptr = &george;
    
           // display george using ptr
           *ptr.display();   // compilation error
        }

   //-------------------------------------------
   2nd step, fix the compilation error (Works but cumbersome syntax)

       class Person {

       public:

           Person(const string& name) : name(name) {}
           void display() {

               cout << "Name: " << name << endl;
           }

       private:

           string name;
       };

       int main() {

           Person george("George");
           Person* ptr = &george;

           // display george using ptr
           (*ptr).display();   // No compilation error
       }

   //-------------------------------------------
   3rd step, better it as possible

       class Person {

       public:

           Person(const string& name) : name(name) {}
           void display() {

               cout << "Name: " << name << endl;
           }

       private:

           string name;
       };

       int main() {

           Person george("George");
           Person* ptr = &george;

           ptr -> display();  // equivalent to (*ptr).display() but looks better
       }
*/
//-------------------------------------------------------------------------------------------

/* The this pointer
  
   //-------------------------------------------
   1st step:
       ● add set_name constructor
           ○ name: member variable
           ○ the_name: function parameter

       class Person {
    
       public:
    
           Person(const string& name) : name(name) {}
           void display() {

               cout << "Name: " << name << endl;
           }
       
           void set_name(const string& the_name) {name = the_name;}
    
       private:
    
           string name;
       };

   //-------------------------------------------
   2nd step:
       ● change the function parameter the_name to name will cause compilation error
           ○ computer cannot distinguish two same thing

       class Person {

       public:

           Person(const string& name) : name(name) {}
           void display() {

               cout << "Name: " << name << endl;
           }

           void set_name(const string& name) {name = name;}    // Compilation error

       private:

           string name;
       };

   //-------------------------------------------
   3rd step: fix the above compilation error via this pointer
       
       ● this - access to current object from within a method
           ○ pointer to current object (stores address of current object)
           ○ use -> for member access
               ■ this -> name
               ■ this -> dob
               ■ etc
   
       class Person {

       public:

           Person(const string& name) : name(name) {}
           void display() {

               cout << "Name: " << name << endl;
           }
       
           void set_name(const string& name) {this -> name = name;}

       private:

           string name;
       };
*/
//-------------------------------------------------------------------------------------------
