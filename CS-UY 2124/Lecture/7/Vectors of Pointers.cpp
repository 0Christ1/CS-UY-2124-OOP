/* CS2124
  
   Vectors of Pointers.cpp

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
using namespace std;

//-------------------------------------------------------------------------------------------

/* Vectors of pointers
    ● Two problems:
        ○ stack variable no good after function returns
        ○ pushing same address to vector

    //--------------------------------------------
    1st step: previous code
 
        void fill_person_vector(ifstream& ifs, vector<Person*>& vec) {
     
            string name;                    // used to read in the name

            while (ifs >> name) {
            
                Person a_person(name);      // Person object defined inside loop
                vec.push_back(&a_person);   // local variable address added to vector
            }
        }
 
    //--------------------------------------------
    2nd step: access to ptr variable lost when function returns

        void fill_person_vector(ifstream& ifs, vector<Person*>& vec) {

            string name;                        // used to read in the name

            while (ifs >> name) {
                
                Person* ptr = new Person(name); // new Person object defined on each iteration
                vec.push_back(ptr);             // local variable address added to vector
            }
        }
*/
//-------------------------------------------------------------------------------------------

/* Vectors of pointers

    //--------------------------------------------
    1st step: create a function for Person vector point to memory
 
        void display_person_pointer_vector(const vector<Person*>& vpp) {
  
            for (size_t i = 0; i < vpp.size(); i++) {
            vpp[i] -> display();   // arrow operator needed
            }
        }
        
        void free_person_pointer_vector_memory(const vector<Person*>& vpp) {
 
            for (size_t i = 0; i < vpp.size(); i++ {
            
                // free Person object's heap memory
            }
        }
 
    //--------------------------------------------
    2nd step: complete the function via Pointer const lecture notes

        void display_person_pointer_vector(const vector<Person*>& vpp) {

            for (size_t i = 0; i < vpp.size(); i++) {
            vpp[i] -> display();   // arrow operator needed
            }
        }
     
        void free_person_pointer_vector_memory(const vector<Person*>& vpp) {

            for (size_t i = 0; i < vpp.size(); i++ {
         
                // free Person object's heap memory
                delete vpp[i];
                vpp[i] = nullptr;
            }
        }
*/
//-------------------------------------------------------------------------------------------
