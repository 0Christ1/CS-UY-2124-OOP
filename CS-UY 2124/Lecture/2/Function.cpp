/* CS2124
  
   Function.cpp

   Created by Christ ㅤ on 7/27/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
 
 ● help organize code
   ○ break problems into smaller pieces
   ○ produces easier to read code
 ● enable code reuse
 ● main() function starting point of C++ programs
 ● return value must match return type
 ● function must be declared before using
 ● vector: similar to List, ArrayList
 ● function prototypes: declaration of the function
 ● const keyword: ○ specifies that object cannot be modified
                  ○ const + &
                      ■ access to original object
                      ■ no modification permitted
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* C++ functions: local variables only accessible inside function from point of declaration
 
       return_type function_name(param1_type param1, param2_type param2){
 
           lv_type1 local_var1;
           lv_type2 local_var2a, local_var2b;
           //perform operations on parameters and local variables
           return return_val;
       }
*/
//-------------------------------------------------------------------------------------------

/* Function: an example
 
       ● "int" factorial: int means return type
       ● int "factorial": factorial means function name
       ● "int" n: int means param type
       ● int "n": n means param name
       ● { : open curly brace
       ● } : close curly brace
       ● return "result": result mean value
     
           int factorial(int n) {
     
               int result = 1;   // local variable declaration
               for (int i = 2; i <= n; ++i) {
                   
                   result *= i;
               }
               return result;
           }
        
           int main() {
              
               //Two ways to call factorial func:
               int factorial (int n);
               int factorial (int);
           }
*/
//-------------------------------------------------------------------------------------------

/* Function: a full examole
 
       int factorial(int n) {
 
           int result = 1;
           for (int i = 2; i <= n; ++i) {
               
               result *= i;
           }
           return result;
       }
    
       int main() {
     
           int factorial (int n);
           cout << "N? ";
           int value;
           cin >> value;
           int answer = factorial(value);
           cout << value << "! is " << answer << endl;
       }
*/
//-------------------------------------------------------------------------------------------

/* Using function prototypes
    
       ● function prototypes provide important information
           ○ return type
           ○ function name
           ○ function parameter type(s)

               int factorial(int n);     // function prototypes or int factorial(int);
      
               int main() {
     
                   cout << "N? ";
                   int value;
                   cin >> value;
                   int answer = factorial(value);
                   cout << value << "! is " << answer << endl;
               }

               int factorial(int n) {
     
                   int result = 1;
                   for (int i = 2; i <= n; ++i) {
     
                       result *= i;
                   }
                   return result;
               }
*/
//-------------------------------------------------------------------------------------------

/* fuction prototypes layout
 
       ● return_type: type of value returned by function
       ● function_name: name of function
       ● p1_type / p2_type: typed parameters
      
           return_type function_name(p1_type param1, p2_type param2,...);
*/
//-------------------------------------------------------------------------------------------

/* Functions without a return type : void
 
      ● functions not required to return value
      ● return type can be defined as void
         ○ indicates that function will not return a value
 
            //helper function for displaying n!
            void display_factorial(int n) {
 
                cout << n << "! is " << factorial(n) << endl;
            }

            //more explicitly
            void display_factorial(int n) {
 
                cout << n << "! is " << factorial(n) << endl;
                return;
            }
*/
//-------------------------------------------------------------------------------------------

/* Overloading functions
 
      ● functions can have the same name in C++
         ○ parameter lists must different
 
             void print_int(int an_int) {
 
                 cout << "Int value is " << an_int << endl;
             }

             void print_string(string a_str) {
 
                 cout << "String value is " << a_str << endl;
             }
 
             //alternatively
 
             void print(int an_int) {

                 cout << "Int value is " << an_int << endl;
             }

             void print(string a_str) {

                 cout << "String value is " << a_str << endl;
             }
*/
//-------------------------------------------------------------------------------------------

/* Passing arguments to functions
    
   ● C++ allows programmer to determine how arguments provided to function in 3 options:
       ○ pass-by-value (default)
       ○ pass-by-reference
       ○ pass-by-constant-reference
 
   //-------------------------------------------
       pass-by-value :
           ● arguments to functions are passed by value (default)
           ● parameter assigned a copy of the value passed
           ● example: swaps two integers
 
               void swap_nums(int num1, int num2) {
     
                   int temp;
                   temp = num1;
                   num1 = num2;
                   num2 = temp;
               }
     
               int main() {
     
                   int num_1 = 5, num_2 = -3;
                   cout << "Before swap " << endl;
                   cout << "Number 1: " << num_1 << endl;
                   cout << "Number 2: " << num_2 << endl << endl;
                   swap_nums(num_1, num_2);
                   cout << "After swap" << endl;
                   cout << "Number 1: " << num_1 << endl;
                   cout << "Number 2: " << num_2 << endl;
               }
 
   //-------------------------------------------
       pass-by-reference : swaps two integers
           ● alternative naming of objects known as a reference
               ○ reference can be thought of as an alias
           ● ampersand (&) indicates a reference to argument
           ● changes made inside function extend to caller
               ○ reference parameters need arguments with a memory address(l-value)
 
                    void swap_nums(int& num1, int& num2) {        // &: reference operator

                        int temp;
                        temp = num1;
                        num1 = num2;
                        num2 = temp;
                    }

                    int main() {
 
                        swap_nums(5, -3);              // X compile error
                        swap_nums(num_1 + 1, num_2);   // l-value
                        int num_1 = 5, num_2 = -3;
                        cout << "Before swap " << endl;
                        cout << "Number 1: " << num_1 << endl;
                        cout << "Number 2: " << num_2 << endl << endl;
                        swap_nums(num_1, num_2);
                        cout << "After swap" << endl;
                        cout << "Number 1: " << num_1 << endl;
                        cout << "Number 2: " << num_2 << endl;
                    }
 
   //-------------------------------------------
       pass-by-constant-reference : using vector parameters
       
       //------------------
           only reference [int val]
 
               void update_vector(vector<int> int_vec, int new_val){
     
                   for (int& val: int_vec) {
                         
                       val = new_val;
                   }
               }
            
               int main() {
     
                   vector<int> nums{0, 1, 2, 3};
                   update_vector(nums, -2);
                   for (int num: nums) {
     
                       cout << num << ' ';
                   }
                   cout << endl; //[0, 1, 2, 3]
               }
 
       //------------------
           both reference [int val] and [int_vec]

               void update_vector(vector<int>& int_vec, int new_val){

                   for (int& val: int_vec) {
                           
                       val = new_val;
                   }
               }
              
               int main() {

                   vector<int> nums{0, 1, 2, 3};
                   update_vector(nums, -2);
                   for (int num: nums) {

                       cout << num << ' ';
                   }
                   cout << endl; //[-1, -1, -1, -1]
               }
 
       //------------------
           both reference [int val] and [int_vec] && put const before (pass-by-constant-reference)

           void update_vector(vector<int>& int_vec, int new_val){

               for (int& val: int_vec) {
                     
                   val = new_val;
               }
           }
 
           void print_vector(const vector<int>& int_vec) {
                             
               for (int num: int_vec){
                 
                   cout << num << ' ';
               }
               cout << endl;
           }
         
           int main() {
         
               vector<int> nums(1000000000000, 0);
               update_vector(nums, -1);
               print_vector(nums);
           }
*/
//-------------------------------------------------------------------------------------------

/* Constant object references
 
      ● object copies passed as function arguments (pass-by-value)
      ● operating on a copy useful when modifications unwanted/disallowed
 
          void update_vector(vector<int>& int_vec, int new_val) {
            
              for (int& val: int_vec) {
                     
                  val = new_val;
              }
          }
          
          for (int& val : int_vec) {
 
              val = new_val;
          }
          
          int main() {
              
              vector<int> nums{0, 1, 2, 3};
              update_vector(nums, -1);
              for (int num; nums) {
 
                  cout << num << ' ';
              }
              cout << endl;
          }
*/
//-------------------------------------------------------------------------------------------
