/* CS2124
  
   ICP6 Person Relationships.cpp

   Created by Christ ㅤ on 8/3/22.

*///-----------------------------------------------------------------------------------------


#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Person class (so far)
   
    //--------------------------------------------
    1st step: original Person class
 
        class Person {
        
            friend ostream& operator << (ostream& os, const Person& rhs) {
            
                os << "Person: name = " << rhs.name << " , dob = " << rhs.dob;
                return os;
            }
     
        public:

            Person(const string& the_name, int b_month, int b_day, int b_year) :       name(the_name), dob(b_month, b_day, b_year) {}

            void eat() const { cout << name << " eating\n"; }

            void set_name(const string& name) { name = name; }

        private:

            string name;
            Date dob;
        };
 
    //--------------------------------------------
    2nd step: delete part of code

        class Person {

            friend ostream& operator << (ostream& os, const Person& rhs) {
         
                os << "Person: name = " << rhs.name << ", ";
                return os;
            }

        public:

            Person(const string& name): name(name) {}

        private:

            string name;
        };
 
    //--------------------------------------------
    3rd step: add spouse variable
        ● Person* allows Person object to be unmarried

        class Person {

            friend ostream& operator << (ostream& os, const Person& rhs) {

                os << "Person: name = " << rhs.name << ", ";
                return os;
            }

        public:
     
            Person(const string& name): name(name), spouse(nullptr) {}

        private:

            string name;
            Person* spouse;
        };

    //--------------------------------------------
    4th step: Person class marriage
        ● enable one Person to marry another via marry() function
        ● Compilation error if use "const" inside the marry() function
 
        class Person {

            friend ostream& operator << (ostream& os, const Person& rhs) {

                os << "Person: name = " << rhs.name << ", ";
                return os;
            }

        public:

            Person(const string& name): name(name), spouse(nullptr) {}
            
            void marry(Person& fiance) {
 
                this->spouse = &fiance;     // marry fiance
                fiance.spouse = this;       // fiance marry this Person
            }

        private:

            string name;
            Person* spouse;
        };

    //--------------------------------------------
    5th step: share the marriage status inside oerator function

        class Person {

            friend ostream& operator << (ostream& os, const Person& rhs) {

                os << "Person: name = " << rhs.name << ", ";
                
                if ( rhs.spouse == nullptr) {   // share marriage status
                    
                    os << "Single";
                } else {
                
                    os << "Married to" << rhs.spouse->name;
                }
                return os;
            }

        public:

            Person(const string& name): name(name), spouse(nullptr) {}
         
            void marry(Person& fiance) {

                this->spouse = &fiance;
                fiance.spouse = this;
            }

        private:

            string name;
            Person* spouse;
        };
 
        int main() {
        
            Person john("John");
            Person mary("Mary");
            john.marry(mary);
            cout << john << '\n' << mary << '\n';
 
            Person bill("Bill");
            john.marry(bill);
            cout << '\n' << john << '\n';           // Errors
            cout << bill << '\n' << mary << '\n';
        }
 
    //--------------------------------------------
    6th step: fix the above errors
        ● Enabling Person object to marry as long as neither already married
        ● Change the return type of marry() to boolean

        class Person {

            friend ostream& operator << (ostream& os, const Person& rhs) {

                os << "Person: name = " << rhs.name << ", ";
             
                if ( rhs.spouse == nullptr) {
                 
                    os << "Single";
                } else {
             
                    os << "Married to" << rhs.spouse->name;
                }
                return os;
            }

        public:
 
            Person(const string& name): name(name), spouse(nullptr) {}
      
            bool marry(Person& fiance) {
                
                // check if Person object already married
                if (fiance.spouse == nullptr && this->spouse == nullptr) {
 
                    this->spouse = &fiance;
                    fiance.spouse = this;
                    return True;
                }
                return False;
            }

        private:
 
            string name;
            Person* spouse;
        };
 
        int main() {

            Person john("John");
            Person mary("Mary");
            john.marry(mary);
            cout << john << '\n' << mary << '\n';

            Person bill("Bill");
            john.marry(bill);
            cout << '\n' << john << '\n';               // No errors
            cout << bill << '\n' << mary << '\n';
        }
*/
//-------------------------------------------------------------------------------------------

/* Tiny improvement for the situation that Person object cannot marry itself

    class Person {

        friend ostream& operator << (ostream& os, const Person& rhs) {

            os << "Person: name = " << rhs.name << ", ";
         
            if ( rhs.spouse == nullptr) {
             
                os << "Single";
            } else if (rhs.spouse -> name == rhs.name) {
            
                os << "Cannot marry youself"
            } else {
         
                os << "Married to" << rhs.spouse->name;
            }
            return os;
        }

    public:

        Person(const string& name): name(name), spouse(nullptr) {}
  
        bool marry(Person& fiance) {
            
            if (fiance.spouse == nullptr && this->spouse == nullptr) {

                this->spouse = &fiance;
                fiance.spouse = this;
                return True;
            }
            return False;
        }

    private:

        string name;
        Person* spouse;
    };

    int main() {

        Person john("John");
        Person mary("Mary");
        john.marry(mary);
        cout << john << '\n' << mary << '\n';

        Person bill("Bill");
        john.marry(bill);
        cout << '\n' << john << '\n';
        cout << bill << '\n' << mary << '\n';
 
        Person ross("Ross");
        ross.marry(ross);
        cout << '\n' << ross << '\n';               // No errors
    }
*/
//-------------------------------------------------------------------------------------------
