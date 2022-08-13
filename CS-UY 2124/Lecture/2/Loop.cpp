/* CS2124
  
   Loop.cpp

   Created by Christ ㅤ on 7/29/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
    
    while: ● condition must be in parenthesis
           ● code for loop located in block
           ● -- is the pre-decrement operator
               ○ Python: i_num -= 1
    for: ● for loop has 3 components specified in parentheses and separated by semicolons (;)
             ○ initialization: first value assigned to loop variable
                 ■ i initialized to 10
             ○ test: condition determining when to enter loop
                 ■ i must be greater than 0
             ○ update: modification of loop variable's value
                 ■ i decremented
    do-while: ● often more concise than equivalent while loop
              ● scope of loop variable (i) limited to for loop
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Loops: While
 
    int main() {
 
        int i_num = 10;
        while (i_num > 0) {
 
            cout << i_num << ' ';
            i_num--;
        }
        cout << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* Loops: for
 
    int main() {
 
        for (int i = 10; i > 0; --i) {
        
            if (i == 5) continue;   //only not print the specific number
            cout << i << ' ';       //yes, C++ has continue and break
        }
        cout << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* Loops: do-while
 
    int main() {
 
        int i_num = 10;
        do {
            cout << i_num << ' ';
            i--;
        } while (i_num > 0);      // remember the semicolon
        cout << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* Question: What would happen if i_num initialized to -1?
 
    int main() {
 
        int i_num = -1;
        do {
            cout << i_num << ' ';
            i--;
        } while (i_num > 0);      // remember the semicolon
        cout << endl;
}
*/
//-------------------------------------------------------------------------------------------
