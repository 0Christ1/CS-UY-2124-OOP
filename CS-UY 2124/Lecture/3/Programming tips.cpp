/* CS2124
  
   Programming tips.cpp

   Created by Christ ㅤ on 7/28/22.

*///-----------------------------------------------------------------------------------------


/* Notes:
 
    ● DON'T USE GLOBAL VARIABLES IN CS 2124
    ● one major exception:
        ○ global constants are helpful AND encouraged
        ○ const int CLASS_NUM = 2124;
    ● limit scope of variables as much as possible
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Scope

    //--------------------------------------------
    1st try:
 
        void updata_vector(vector<int>& int_vec, int new_val);
     
        void print_vector(const vector<int>& int_vec) {
      
            for (int num: int_vec) {
     
                cout << num << ' ';
            }
            cout << endl;
        
         int main() {
     
             vector<int> nums(1000000000000, 0);
             update_vector(nums, -1);
             print_vector(nums);
         }
 
    //--------------------------------------------
    2nd try: code works but uses global

        vector<int> nums(1000000000000, 0);
     
        void updata_vector(vector<int>& int_vec, int new_val);
       
        void print_vector(const vector<int>& int_vec) {
        
            for (int num: int_vec) {
       
                cout << num << ' ';
            }
            cout << endl;
        
        int main() {
       
            update_vector(nums, -1);
            print_vector(nums);
        }
 
    //--------------------------------------------
    sum needed outside of for loop

        int main() {
            
            int num;
            cout << "Enter a positive integer: ";
            cin >> num;
 
            int sum = 0;
 
            for (int i = 0; i <= num; i++) {
                
                sum += 1;
            }
            cout << "Sum =" << sum << endl;
}
*/
//-------------------------------------------------------------------------------------------
