/* CS2124
  
   ICP7 Person.cpp

   Created by Christ ㅤ on 8/3/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
    
    ● Tips for using pointers
        ○ Always initialize before use
        ○ After deleting a pointer, assign nullptr to deleted pointer
        ○ Don't delete a pointer more than once
        ○ Never return the address of a local variable
        ○ Take extreme caution with two pointers pointing the same address
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Person objects with ages
   
    //--------------------------------------------
    1st step:
        ● original Person class
            ○ add variable for age
 
        class Person {
        
            friend ostream& operator << (ostream& os, const Person& someone) {
            
                os << "Person: " << someone.name;
                return os;
            }
     
        public:

            Person(const string& the_name) : name(name) {}      // Compilation error
            const string& get_name() const { return name; }

        private:

            string name;
            int age;        // variable for age
        };
 
    //--------------------------------------------
    2nd step:
        ● fix the compilation error of constructor
        ● display age in << function

        class Person {

            friend ostream& operator << (ostream& os, const Person& someone) {
         
                os << "Person: " << someone.name << ', ' << someone.age;
                return os;
            }

        public:

            Person(const string& name, int age): name(name), age(age) {}
            const string& get_name() const { return name; }

        private:

            string name;
            int age;
        };
*/
//-------------------------------------------------------------------------------------------

/* Person objects and pointers
   
    //--------------------------------------------
    1st step:
        ● read file and catch Exception
 
        int main() {
            
            ifstream ifs("stooges.txt");    // open file
            
            if (!ifs) {                     // catch Exception
    
                cerr << "Faile to open the file named stooges";
                exit(1);
            }
        }
 
    //--------------------------------------------
    2nd step:
        ● get context from file

        int main() {
         
            ...
 
            vector<Person*> stooges;
            string name;
            int age;
            
            while (ifs >> name >> age) {
            
                Person* ptr = new Person(name, age); // create Person object from the heap
                stooges.push_back(ptr);              // add Person object's address to vector
                // stooges.push_back(new Person(name, age);
            }
            ifs.close();
        }
        
    //--------------------------------------------
    3rd step:
        ● print out the context from vector

        int main() {
      
            ...
 
            for (Person* ptr: stooges):
                    
                cout << ptr->get_name() << '\t' << ptr << endl;
            }
        }
 
    //--------------------------------------------
    4th step:
        ● free allocated memory
            ○ Person* ptr : copy of vector item
            ○ delete ptr: dangling pointers remain
            ○ ptr = nullptr: variable storing copy modified to store nullptr

        int main() {
 
            ...
 
            for (Person* ptr: stooges) {
            
                delete ptr;     // compilation error
                ptr = nullptr;  // eliminate dangling pointer
            }
        }
 
    //--------------------------------------------
    5th step:
        ● How can we modify the for loop to ensure that the dangling pointers are eliminated?
            ○ fixt the compilation error
                ■ using Person*& allows modification of vector items
 
        int main() {

            for (Person*& ptr: stooges) {
         
                delete ptr;     // free allocated memory
                ptr = nullptr;  // eliminate dangling pointer
            }
     }
 
    //--------------------------------------------
    6th step: entire code for main function

     int main() {

         vector<Person*> stooges;
         string name;
         int age;
         
         while (ifs >> name >> age) {
         
             Person* ptr = new Person(name, age); // create Person object from the heap
             stooges.push_back(ptr);              // add Person object's address to vector
             // stooges.push_back(new Person(name, age);
         }
         ifs.close();
 
         for (Person* ptr: stooges):
                 
             cout << ptr->get_name() << '\t' << ptr << endl;
         }
 
         for (Person*& ptr: stooges) {
      
             delete ptr;     // free allocated memory
             ptr = nullptr;  // eliminate dangling pointer
         }
    }
*/
//-------------------------------------------------------------------------------------------

/* Complete code with tiny adjustment
 
    class Person {
 
        friend ostream& operator << (ostream& os, const Person& someone) {
 
            os << "Person: " << someone.name << ", " << someone.age << endl;
            return os;
        }
 
    public:
     
        Person(const string& name, int age) : name(name), age(age) {}
        const string& get_name() const {return name;}
        const int& get_age() const {return age;}
    
    private:
     
        string name;
        int age;
    };

    void fill_person_vector (ifstream& ifs, vector<Person*>& vec) {
     
        string name;
        int age;
 
        while (ifs >> name >> age) {
 
            vec.push_back(new Person(name, age));
        }
    }

    void display_person_vector (vector<Person*>& vec) {
     
        for (Person* ptr: vec) {
         
            cout << ptr->get_name() << " \t" << ptr->get_age() << endl;
        }
     
        for (Person*& ptr: vec) {
            
            delete ptr;
            ptr = nullptr;
        }
    }

    int main() {
        
        ifstream ifs("stooges.txt");
        
        if (!ifs) {
         
            cerr << "Failed to open file." << endl;
            exit(1);
        }
     
        vector<Person*> stooges;
        fill_person_vector(ifs, stooges);
        ifs.close();
        display_person_vector(stooges);
    }
*/
//-------------------------------------------------------------------------------------------
