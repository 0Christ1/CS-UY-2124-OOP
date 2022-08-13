/* CS2124
  
   Dynamic memory.cpp

   Created by Christ ㅤ on 8/3/22.

*///-----------------------------------------------------------------------------------------


#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Dynamic memory

    //--------------------------------------------
    Heap allocation
        ● 1st step:
                                                                  _______________
        int add(int numA, int numB) {                            |_______________|
                                            end of call stack--->|_______________|
            return numA + numB;                                  |_______________|
        }                                                        |_______________|
                                                                 |_______________|
        int main() {                                             |_______________|
                                                                 |_______________|
        --> int num1 = 1, num2 = 3;                              |_______________|
            ...
            add(num1, num2);
            return 0;
        }
 
    //--------------------------------------------
    2nd step:
                                                                  _______________
        int add(int numA, int numB) {                            |_______________|
                                                                 |_______________|
            return numA + numB;                                  |_______1_______|
        }                                   end of call stack___>|_______3_______|
                                                                 |_______________|
        int main() {                                             |_______________|
                                                                 |_______________|
            int num1 = 1, num2 = 3;                              |_______________|
        --> ...
            add(num1, num2);
            return 0;
        }
 
    //--------------------------------------------
    3rd step:
                                                                  _______________
        int add(int numA, int numB) {                            |_______________|
                                                                 |_______________|
            return numA + numB;                                  |_______1_______|
        }                                                        |_______3_______|
                                            end of call stack___>|______...______|
        int main() {                                             |_______________|
                                                                 |_______________|
            int num1 = 1, num2 = 3;                              |_______________|
            ...
        --> add(num1, num2);
            return 0;
        }
 
    //--------------------------------------------
    4th step: stack size limited
                                                                  _______________
        int add(int numA, int numB) {                            |_______________|
                                                                 |_______________|
       --> return numA + numB;                                   |_______1_______|
        }                                                        |_______3_______|
                                                                 |______...______|
        int main() {                                             |_______1_______|
                                            end of call stack___>|_______3_______|
            int num1 = 1, num2 = 3;                              |_______________|
            ...
            add(num1, num2);
            return 0;
        }
 
    //--------------------------------------------
    5th step: numA/numB no longer accessible to program
                                                                  _______________
        int add(int numA, int numB) {                            |_______________|
                                                                 |_______________|
            return numA + numB;                                  |_______1_______|
        }                                                        |_______3_______|
                                            end of call stack___>|______...______|
        int main() {                                             |_______1_______|
                                                                 |_______3_______|
            int num1 = 1, num2 = 3;                              |_______________|
            ...
            add(num1, num2);
        --> return 0;
        }
*/
//-------------------------------------------------------------------------------------------

/* Dynamic memory
    
    ● Need for a large memory source
        ○ call stack limited in size
        ○ local variables lost when function returns

    //--------------------------------------------
    Heap allocation
        ● 1st step:
            ○ new int(17) = 0x7ffee69088cc
                                             ________________
        int main() {                        |________________|       _____________________
                                            |______..._______|      |       heap          |
           int* ptr = new int(17);       ptr|_0x7ffee69088cc_|---------|   __________     |
           cout << *ptr << endl;            |________________|      |  |->|____17____|    |
           cout << ptr << endl;             |________________|      |                     |
                                            |________________|      |                     |
           // *ptr = 17                     |________________|      |_____________________|
           // ptr = 0x7ffee69088cc          |________________|
        }
            
    //--------------------------------------------
        ● 2nd step:
            ○ new int(17) = 0x7ffee69088cc
                                             ________________
        int main() {                        |________________|       _____________________
                                            |______..._______|      |       heap          |
            int* ptr = new int(17);      ptr|_0x7ffee69088cc_|---------|   __________     |
            cout << *ptr << endl;           |________________|      |  |->|____42____|    |
            cout << ptr << endl;            |________________|      |                     |
            *ptr = 42;                      |________________|      |                     |
            cout << *ptr << endl;           |________________|      |_____________________|
            cout << ptr << endl;            |________________|
             
            // *ptr = 17
            // ptr = 0x7ffee69088cc
            // *ptr = 42
            // ptr = 0x7ffee69088cc
        }
 
    //--------------------------------------------
    Freeing memory
        ● Need for a large memory source
            ○ call stack limited in size
            ○ local variables lost when function returns
            ○ ability to indicate that memory no longer needed
        ● 1st step: delete ptr
                                             ________________
        int main() {                        |________________|       _____________________
                                            |______..._______|      |       heap          |
            int* ptr = new int(17);      ptr|_0x7ffee69088cc_|---X-----|   __________     |
            cout << *ptr << endl;           |________________|      |  |->|____42____|    |
            cout << ptr << endl;            |________________|      |                     |
            *ptr = 42;                      |________________|      |                     |
            cout << *ptr << endl;           |________________|      |_____________________|
            cout << ptr << endl;            |________________|
            
            delete ptr;
        }
 
    //--------------------------------------------
    Freeing memory
        ● 1st step: delete ptr
            ○ after delete, ptr value unchanged
 
                                             ________________
        int main() {                        |________________|       _____________________
                                            |______..._______|      |        heap         |
            int* ptr = new int(17);      ptr|_0x7ffee69088cc_|      |     ___________     |
            cout << *ptr << endl;           |______..._______|      |    |____42_____|    |
            cout << ptr << endl;            |________________|      |                     |
            *ptr = 42;                      |________________|      |                     |
            cout << *ptr << endl;           |________________|      |_____________________|
            cout << ptr << endl;            |________________|        memory now available
            
            delete ptr;
            ...
        }

    //--------------------------------------------
    Freeing memory
        ● 2nd step: add ptr2
                                             ________________
        int main() {                        |________________|       _____________________
                                            |______..._______|      |        heap         |
            int* ptr = new int(17);      ptr|_0x7ffee69088cc_|      |     ___________     |
            cout << *ptr << endl;           |______..._______|      |    |____42_____|    |
            cout << ptr << endl;        ptr2|_0x7ffee76543cc_|--------|   ___________     |
            *ptr = 42;                      |________________|      | |->|____4390___|    |
            cout << *ptr << endl;           |________________|      |                     |
            cout << ptr << endl;            |________________|      |_____________________|
         
            delete ptr;     // dangling pointer
            ...
            int* ptr2 = new int(4390);
            ...
            int res = 5 * (*ptr2);
        }

    //--------------------------------------------
    Freeing memory
        ● 3rd step: set the value of ptr to nullpter
                                             ________________
        int main() {                        |________________|       _____________________
                                            |______..._______|      |        heap         |
            int* ptr = new int(17);      ptr|_0x7ffee69088cc_|      |     ___________     |
            cout << *ptr << endl;           |______..._______|      |    |____42_____|    |
            cout << ptr << endl;        ptr2|_0x7ffee76543cc_|--------|   ___________     |
            *ptr = 42;                      |________________|      | |->|____4390___|    |
            cout << *ptr << endl;           |________________|      |                     |
            cout << ptr << endl;            |________________|      |_____________________|
      
            delete ptr;
            ptr = nullptr;  // best practice
            int* ptr2 = new int(4390);
            ...
            int res = 5 * (*ptr2);
        }
*/
//-------------------------------------------------------------------------------------------
