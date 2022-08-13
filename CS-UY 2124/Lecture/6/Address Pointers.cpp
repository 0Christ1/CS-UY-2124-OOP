/* CS2124
  
   Addresses and Pointers.cpp

   Created by Christ ㅤ on 8/2/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
  
    Background:
        ● Memory addresses
            ○ programs without memory access not very useful
                ■ instructions stored in memory while program running
                ■ values need to be stored for later use
            ○ memory access largely invisible in some languages (Python)
            ○ C/C++ enable direct access to computer memory
                ■ powerful feature with many benefits
                ■ directly accessing memory requires care
 
    Symbols: ● & : address operator
             ● * : address pointer
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Obtaining an address
   
    ● preceding variable with & evaluates to variable's address
    ● & -address-of operator (reference operator as well)
 
        int mian () {
 
            int day = 17;
 
            cout << day << endl;        // 17
        
            cout << &day << endl;       // 0x7ff7bfeff35c  this is memory address
}
*/
//-------------------------------------------------------------------------------------------

/* Storing an address
        
    //-------------------------------------------
    1st step, compilation error

        int main () {

            int day = 17;

            cout << day << endl;
 
            cout << &day << endl;
 
            
            addr = &day;           // Compilation error
 
            cout << addr << endl;

        }
 
    //-------------------------------------------
    2nd step, fix the compilation error
    
        ● * after a type defineds the avriable as a pointer of that type
        ● pointer variables store memory address
        ● a pointer can be declared for any type
            ○ Vorlon*
            ○ double*
            ○ char*
            ○ etc
        ● pinters are all of the same size

            int main () {

                int day = 17;

                cout << day << endl;

                cout << &day << endl;

             
                int* addr = &day;       // No compilation error

                cout << addr << endl;
            }
*/
//-------------------------------------------------------------------------------------------

/* Pointer declarations
   
     int*   addr = &day;      addr  - pointer to int(int "star")
 
     int   *addr2 = &week;    addr2 - pointer to int
 
     int *  addr3 = &year;    addr3 - pointer to int
*/
//-------------------------------------------------------------------------------------------

/* Pointer declarations - What is the type of other? int* addr, other;
 
    ● int* addr: asterisk binds to nearest variable name
    ● other: regular int
 
    int* addr, other;
 
*/
//-------------------------------------------------------------------------------------------

/* Accessing values
 
    ● outside of declaration, asterisk(*) used as deference opterator
        ○ only works with pointer types
    ● experssion *ptr evaluates to value stored at address
    ● *addr <==> day
    
        int main() {
 
            int day = 17;

            cout << day << endl;

            cout << &day << endl;

            int* addr = &day;

            cout << addr << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* Initializing pointers
    
    ● initializing variables always a good idea
        ○ int day = -1;
        ○ double salray = 0;
    ● nullptr can be assigned to any pointer variable
        ○ represents an address that cannot be used

            //-------------------------------------------
            1st: ● previous value at address may be important
                 ● i_ptr = 0s and 1s, value interpreted as an address
 
            int main() {
             
                int* i_ptr;
                ...
                *i_ptr = 23;   // Compilation error
            }
 
            //-------------------------------------------
            2nd: ● program crash
                 ● nullptr evaluated as 0, which i_ptr = 0
 
            int main() {

                int* i_ptr = nullptr;
                ...
                *i_ptr = 23;   // the program will crash
            }
 
            //-------------------------------------------
            3rd: ● alternative (use NULL in code)
                 ● NULL evaluated as 0, which i_ptr = 0

            int main() {

                int* i_ptr = NULL;
            }
*/
//-------------------------------------------------------------------------------------------
