/* CS2124
  
   ICP3 Automobile.cpp

   Created by Christ ㅤ on 7/29/22.

*///-----------------------------------------------------------------------------------------


/* Program design choices:
 
    ● represent vehicle using struct
        ○ year
        ○ make (Nissan, Toyota, Ford, etc)
        ○ model (Altima, Corolla, Mustang, etc)
        ○ mileage
        ○ price
    ● Vehicle structs stored in vector (inventory)
    ● simple input interface for populating inventory
*/
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------

/* Automobile
 
    //--------------------------------------------
    Defining a Vehicle struct

        struct Vehicle {
            
            short year;
            string make, model;
            int mileage;
            double price;
        };
 
     //--------------------------------------------
     Declaring add_to_inventory function

         void add_to_inventory (vector<Vehicle>&);  //function prototype
 
     //--------------------------------------------
     Defining add_to_inventory function

         void add_to_inventory(vector<Vehicle>& inventory) {
 
             Vehicle veh;  // declare Vehicle named veh
             cout << "Enter year: "; cin >> veh.year;
             cout << "Enter make: "; cin >> veh.make;
             cout << "Enter model: "; cin >> veh.model;
             cout << "Enter price: "; cin >> veh.price;
             cout << "Enter mileage: "; cin >> veh.price;
             cout << endl;
             inventory.push_back(veh);
         }
 
     //--------------------------------------------
     Defining main function
 
         int main() {

             char usr_input = 0;
             vector<Vehicle> auto_lot;

             cout << "Welcome to CS 2124 Autos!" << endl << endl;
             cout << "Enter new vehicle details" << endl;

             while (usr_input != 'n') {

                 while (usr_input != 'n' && usr_input != 'y') {
 
                     cout << "Add a vehicle (y/n)? ";
                     cin >> usr_input;
                 }
 
                 if (usr_input == 'y') {
 
                     add_to_inventory(auto_lot);
                     usr_input = 0;
                 }
             }
             cout << "Added " << auto_lot.size() << " vehicles." << endl;
         }
*/
//-------------------------------------------------------------------------------------------


/* Input from a file of vehicles
 
    //--------------------------------------------
    Defining a Vehicle struct

        struct Vehicle {
             
            short year;
            string make, model;
            int mileage;
            double price;
        };
 
    //--------------------------------------------
    Reading vehicles from a file

        void read_inventory (ifstream& ifs, vector<Vehicle>& inventory) {
            
            Vehicle veh;
 
            while (ifs >> veh.year >> veh.make >> veh.model >> veh.price >> veh.mileage) {
        
                inventory.push_back(veh);
            }
        }
 
     //--------------------------------------------
     Defining main function
 
         int main() {

         ifstream vehi("vehicles.txt");
             
             if (!vehi) {
 
                 cerr << "failed to open file.";
                 exit(1);
             }
 
         vector<Vehicle> v_vec;
         read_inventory(vehi, v_vec);
 
         for (int i = 0; i < v_vec.size(); i++) {
 
             cout << "Year: " << v_vec.at(i).year << "\t";
             cout << "Make: " << v_vec.at(i).make << "\t";
             cout << "Model: " << v_vec.at(i).model << "\t";
             cout << "Price: " << v_vec.at(i).price << "\t";
             cout << "Mileage: " << v_vec.at(i).mileage << endl;
         }
         cout << endl;
*/
//-------------------------------------------------------------------------------------------
