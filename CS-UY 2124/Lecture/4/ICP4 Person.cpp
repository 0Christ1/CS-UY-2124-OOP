/* CS2124
  
   ICP4 Person.cpp

   Created by Christ ㅤ on 7/30/22.

*///-----------------------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Representing people
   
    //--------------------------------------------
    ● people can be many things
        ○ students
        ○ employees
        ○ customers

            struct Person {
     
                string name;
            };
 
    //--------------------------------------------
    ● create representation of person
        ○ start with struct
        ○ transition to class
    
            void make_eat(const Person& a_person) {
     
                cout << a_person.name << " eating\n";
            }
*/
//-------------------------------------------------------------------------------------------

/* struct Person

    struct Person {

        string name;
    };

    void make_eat(const Person& a_person) {
    
        cout << a_person.name << " eating\n";
    }

    int main() {
    
        Person john;
        john.name = "John";
        make_eat(john);
    }
*/
//-------------------------------------------------------------------------------------------

/* struct to class

    //--------------------------------------------
    1st step: compilation error
     
        class Person {
        
        private:
 
            string name;
        };

        void make_eat(const Person& a_person) {
        
            cout << a_person.name << " eating\n";
        }

        int main() {
        
            Person john;
            john.name = "John";  // compilation error
            make_eat(john);
        }
 
 
    //--------------------------------------------
    2nd step: solve compilation error
              ● add a mutator function for name
              
        class Person {

        public:
            
            void set_name(const string& the_name) { name = the_name; }

        private:

            string name;
        };

        void make_eat(const Person& a_person) {

            cout << a_person.name << " eating\n";
        }

        int main() {

            Person john;
            john.set_name("John"); // But inefficient and unnecessary
            make_eat(john);
        }

    //--------------------------------------------
    3rd step: ● define a constructor, compilation error
           
        class Person {

        public:
             
            Person(const string& the_name) : name(the_name) {} // constructor
     
            void set_name(const string& the_name) { name = the_name; }

        private:

            string name;
        };

        void make_eat(const Person& a_person) {

            cout << a_person.name << " eating\n";  // But .name is compilation error
        }

        int main() {

            Person john("john");
            make_eat(john);
        }
 
    //--------------------------------------------
    4th step: solve compilation error
              ● move make_eat() function inside public
              ● add const after eat() to declare it doesn't change current object
        
        class Person {

        public:
          
            Person(const string& the_name) : name(the_name) {} // constructor

            void eat() const { cout << name << " eating\n"; }
 
            void set_name(const string& the_name) { name = the_name; }

        private:

            string name;
        };

        int main() {

            Person john("john");
            john.eat();
        }
*/
//-------------------------------------------------------------------------------------------
