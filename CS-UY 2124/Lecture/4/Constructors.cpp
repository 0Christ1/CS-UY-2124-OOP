/* CS2124
  
   Constructors.cpp

   Created by Christ ㅤ on 7/30/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
 
    The default constructor:
        ● special constructor that takes no arguments
        ● initializes all member variables of a type that is itself a class
            ○ excludes C++ built in types (int, char, double, etc)
            ○ excludes pointer types
        ● member variables without explicit initialization use default constructor
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Initializing member variables
 
    ● special methods for initializing objects: constructors
   
    //--------------------------------------------
    last class:

        class Vorlon {
        
        public:
            
            void display() {
 
                cout << "Displaying a Vorlon named " << my_name << endl;
            }
 
        private:
    
            string my_name;
        };
 
    //--------------------------------------------
    shorter way:

        class Vorlon {
         
        public:
             
            Vorlon(const string& a_name){my_name = a_name;}
 
            void display() {

                cout << "Displaying a Vorlon named " << my_name << endl;
            }

        private:
     
            string my_name;
        };
 
     //--------------------------------------------
     Complete code: No need to directly access private member

        class Vorlon {
          
        public:
              
            Vorlon(const string& a_name){my_name = a_name;}

            void display() {

                cout << "Displaying a Vorlon named " << my_name << endl;
            }

        private:
      
            string my_name;
        };
 
        int main() {

            Vorlon v1("Kosh");
            v1.display();
        }
*/
//-------------------------------------------------------------------------------------------

/* Assignment vs. initialization
 
    //--------------------------------------------
    ● two steps way: ○ Create an empty string
                     ○ Assign value "Felix"
    
        string cat;
        cat = "Felix";   // waste resources
 
    //--------------------------------------------
    ● One step way: ○ Create a string with the value "Felix"
        
        // string cat = "Felix";
        string cat("Felix");
*/
//-------------------------------------------------------------------------------------------

/* Initializing member variables
 
    //--------------------------------------------
    We used two steps as follows, which it is not the best

        class Vorlon {
         
        public:
             
            Vorlon(const string& a_name){my_name = a_name;}
 
            void display() {

                cout << "Displaying a Vorlon named " << my_name << endl;
            }

        private:
     
            string my_name;
        };
 
    //--------------------------------------------
    Better way:
 
    ● : my_name(a_name) {} is initialization list
    ● {} constructorr body can be empty
 
        class Vorlon {
          
        public:
              
            Vorlon(const string& a_name) : my_name(a_name) {}

            void display() {

                cout << "Displaying a Vorlon named " << my_name << endl;
            }

        private:
      
            string my_name;
        };
*/
//-------------------------------------------------------------------------------------------

/* class format (4)
   
    ● colon (:) indicates initialization list to follow

    //--------------------------------------------
    If no private:
 
        class ClassName {
   
        public:
            
            ClassName(param_type param_name, ...) : initialization_list {
 
                constructor body
            }
        };
 
    //--------------------------------------------
    Multiple variables in private:
 
    ● p_t1, p_n1: parameter_type1, parameter_name1
    ● m_t1, m_n1: my_type1, my_name1

        class ClassName {

        public:
             
            ClassName(p_t1 p_n1, p_t2 p_n2, ...) : m_n1(p_n1), m_n2(p_n2), ... {

                constructor body
            }
 
        private:
 
            m_t1 m_n1;
            m_t2 m_n2;
            ...
        };
*/
//-------------------------------------------------------------------------------------------

/* Initializing member variables
    
    ● What if my_name should be immutable?

    //--------------------------------------------
    original:
 
        class Vorlon {
         
        public:
             
            Vorlon(const string& a_name){my_name = a_name;}
 
            void display() {

                cout << "Displaying a Vorlon named " << my_name << endl;
            }

        private:
     
            string my_name;
        };
 
    //--------------------------------------------
    add const in front of string my_name
 
    ● const member variable ensures that once initialized, member is not modifiable
 
         class Vorlon {
          
         public:
              
             Vorlon(const string& a_name){my_name = a_name;}

             void display() {

                 cout << "Displaying a Vorlon named " << my_name << endl;
             }

         private:
      
             const string my_name;
         };
*/
//-------------------------------------------------------------------------------------------

/* The default constructor
 
    ● default constructor (automatically) provided when no constructor defined
    ● default constructor must be defined if class contains any constructor definition

        //--------------------------------------------
        Wrong way:
 
            class Vorlon {
     
            public:
     
                Vorlon(const string& a_name){my_name = a_name;}
     
                void display() {
        
                    cout << "Displaying a Vorlon named " << my_name << endl;
                }
     
            private:
     
                const string my_name;
            };

            int main() {

                Vorlon v1;  // Compile error!
            }
         
        //--------------------------------------------
        Correct way: ● no compiler error when class lacks constructor definition
        
            class Vorlon {

            public:

                Vorlon(const string& a_name){my_name = a_name;}
 
                Vorlon() {}      // default constructor

                void display() {
         
                    cout << "Displaying a Vorlon named " << my_name << endl;
                }

            private:

                const string my_name;
            };

            int main() {

                Vorlon v1;  // No compile error!
            }
 
*/
//-------------------------------------------------------------------------------------------

/* What value would the member variable my_name have                                        when declaring a Vorlon in the manner displayed below?  It would be empty.

    class Vorlon {

    public:

        Vorlon(const string& a_name){my_name = a_name;}

        Vorlon() {}      // default constructor

        void display() {
 
            cout << "Displaying a Vorlon named " << my_name << endl;
        }

    private:

        const string my_name;
    };

    int main() {

        Vorlon v1;
    }
 
*/
//-------------------------------------------------------------------------------------------
