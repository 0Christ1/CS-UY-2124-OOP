/* CS2124
  
   Intro.cpp

   Created by Christ ㅤ on 7/27/22.

*///-------------------------------------------------------------------------------------------


/* Notes:
 
    C++ history: ● Created by Bjarne Stroustrup
                     ○ Danish Computer Scientist
                     ○ Bell Labs (1979)
                     ○ Inspired by Simula (OOP) and C (speed/portability)
                     ○ http://www.stroustrup.com/
                 ● Continues to evolve
                     ○ Current standard: C++20
                     ○ modern C++: a completely type-safe and resource-safe language
 
    rules: ● Every program must have a function named main
           ● Blocks of code are surrounded by braces: {}
           ● Statements end with a semicolon: ;
           ● Each function must state the type it returns
               ○ type returned by main is int (an integer)
           ● Each function must be declared and defined before it is used
           ● main function must return an integer
               ○ 0 means successful completion
           ● Every function that returns a value must include a return statement
           ● Without a return statement, main returns 0 (by default)
           ● Comments begin with //
    
    keys: ● "<<" is the output operator
              ○ target stream appears on the left
              ○ what is output on the right
              ○ angle brackets "point to" the output stream
          ● std::cout represents standard output (the screen, by default)
          ● #include specifies a library for compiler
          ● iostream provides the definition for std::cout (and much more)
          ● using namespace std;
             ○ allows reference to cout and other symbols without needing to type std::
             ○ save your life
          ● endl: an end-of-line character
              ○ full reference: std::endl
              ○ alternative to writing "\n"
              ○ also flushes the output stream (not crucial to understand now)
          ● cin: charactrer input
          ● cout: character output
          ● void: no return
          ● endl: an end line character

    Variables: ● variables are declared to have a type
                   ○ only things of that type can be stored in the variable
                   ○ examples:
                       ■ int num;
                       ■ double score;
                       ■ string name;
               ● specifying types also done for
                    ○ function parameters
                    ○ function return types
               ● other programming languages work similarly (e.g. C, C#, Java)
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------------------

/* std::
 
    int main() {
 
        //two ways with std::
        std::cout << "Hello CS2124!\n" << std::endl;
        std::cout << "Hello CS2124!\n";

        //two ways without std::
        cout << "Hello CS2124!\n" << endl;
        cout << "Hello CS2124!\n";
}
*/
//-------------------------------------------------------------------------------------------

/* variables & an uninitialized variable
 
    int main() {
 
        int age = 42;
        int age2;
        double pi = 3.1415926535;
        string txt = "the cat in the hat";
        cout << "age: " << age << ", pi: " << pi << ", txt: " << txt << endl;
        cout << age2 << endl;    // 0
}
*/
//-------------------------------------------------------------------------------------------

/* An uninitialized variable
 
    void foo() {
 
        int num1 = 17;
        cout << "num1: " << num1 << endl;
    }
    
    // uninitialized variable
    void bar() {

        int num2;
        cout << "num2: " << num2 << endl;   It will use the same value of num1
    }

    int main() {
    
        foo();
        bar();
}
*/
//-------------------------------------------------------------------------------------------

/* Getting input
 
    int main() {
 
        int i_var = -1;
        cout << "i_var: " << i_var << endl;
        cout << "input an integer value: ";
        cin >> i_var;
        cout << "i_var : " << i_var << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* Conditions
 
    int main() {
 
        int a_num;
        cout << "a_num? ";
        cin >> a_num;
        if (a_num == 6) {
 
            cout << "a_num is a samll perfect number" << endl;
        }else if (a_num == 42) {
 
            cout << "a_num is the answer" << endl;
        }else {
 
            cout << "a_num is something eles" << endl;
        }
}
*/
//-------------------------------------------------------------------------------------------

/* Logical Operations: ||, &&, !
 
    int main() {

        int a_num;
        cout << "a_num? ";
        cin >> a_num;
        if (a_num == 6 || a_num == 28) {
 
            cout << "a_num is a samll perfect number\n";
        }else if (a_num >= 0 && a_num <= 9) {
            
            cout << "a_num is an imperfect single digit number\n";
        }else if (!(a_num < 0 || a_num > 99)){
         
            cout << "a_num is a two digit number\n";
        }else {
         
            cout << "a_num is something eles\n";
        }
}
*/
//-------------------------------------------------------------------------------------------
