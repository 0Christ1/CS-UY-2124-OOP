/* CS2124
  
   Strings.cpp

   Created by Christ ㅤ on 7/29/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
  
    ● #include <string>
    ● string literals use double quotes
        ○ string str = "this is a string";
    ● string variable acts much like a vector of characters
        ○ e.g. push_back(), pop_back(), size(), clear()
    ● string has some additional useful features
        ○ e.g. input to/output from string possible (not possible for vector)
    ● characters are a separate type from strings
        ○ character literals use single quotes
        ○ char c = 'q';
 
    string and char :
        ● #include <string> needed
        ● double quotes for str, single quotes for char ["Apple", 'A']
        ● elements of a string are of type char
        ● chars are ints so we can do arithmetic with them
        ● chars hold the ascii value of the character
        ● strings are mutable (we can modify their contents)
        ● full name: std::string
        ● string literals are in double quotes
        ● char literals use single quotes
        ● char type holds a single character
        ● char is a type of integer
        ● strings can be output with the << operator
        ● strings can be looped over (like vectors)
        ● plus (+) operator concatenates strings

*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------------------------------------------------------

/* string example
 
       int main() {
 
           string str1 = "Twas brilling and";
           cout << str1 << endl;
 
           for (char ch : str1) {
 
               cout << ch << ' ';
           }
           cout << endl;
 
           string str2 = " the slithy toves";
           string str3 = str1 + str2;
           cout << str3 << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* C++ strings are mutable
 
       int main() {
 
           string animal = "bat";
           animal[0] += 1;
           cout << animal << endl;
}
*/
//-------------------------------------------------------------------------------------------

/* What is the type of animal[0] and what is the ouput?
 
       int main() {
 
           string animal = "bat";
           animal[0] += 1;
           cout << animal << endl;  //[cat]
}
*/
//-------------------------------------------------------------------------------------------
