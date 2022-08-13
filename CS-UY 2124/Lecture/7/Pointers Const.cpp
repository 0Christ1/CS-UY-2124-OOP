/* CS2124
  
   Pointers const.cpp

   Created by Christ ㅤ on 8/3/22.

*///-----------------------------------------------------------------------------------------


#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* The const keyword and Pointers:

    //--------------------------------------------
    1st way:
        ● int* const ptr = &x_coord;
            ○ ptr can only point to x_coord
            ○ cannot change RHS
 
        int main() {

            int x_coord = 17, y_coord = 6;
            int* const ptr = &x_coord;      // ptr can only point to x_coord
            *ptr = 42;
            ptr = &y_coord;                 // Compilation error
        }
 
    //--------------------------------------------
    2nd way:
        ● const int*  ptr = &x_coord;
            ○ ptr will treat x_coord as const

        int main() {

            int x_coord = 17, y_coord = 6;
            const int* ptr = &x_coord;       // ptr will treat x_coord as const
            *ptr = 42;                       // Compilation error
            ptr = &y_coord;
        }
 
    //--------------------------------------------
    3rd way:
        ● const int* const ptr = &x_coord;
            ○ ptr will treat x_coord as const AND ptr can only point to x_coord

        int main() {

            int x_coord = 17, y_coord = 6;
            const int* const ptr = &x_coord;
            *ptr = 42;                       // Compilation error
            ptr = &y_coord;                  // Compilation error
        }

*/
//-------------------------------------------------------------------------------------------
