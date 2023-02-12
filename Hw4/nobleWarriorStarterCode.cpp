/*
  nobleWarriorStarterCode.cpp
  Association: Noble - Warrior
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define your classes here


// Utility functions provided for you, defined below.
void hire(Noble& nob, Warrior& war);
void fire(Noble& nob, Warrior& war);

int main() {
	
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
	
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
	
    hire(jim, nimoy);
    hire(lance, theGovernator);
    hire(art, wizard);
    hire(lance, dylan);
    hire(linus, lawless);
    hire(billie, mrGreen);
    hire(art, cheetah);
    hire(art, nimoy);
	
    cout << "==========\n\n"
         << "Status before all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n\n";

    fire(art, cheetah);
    cout << art << endl;    
    fire(lance, nimoy);
    cout << lance << endl;    
    cout << "==========\n\n";

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
    cout << "==========\n\n";

    cout << "Status after all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";
	
}

//
// Utility functions
//
// hire. Calls Noble's hire method and displays error message on failure.
void hire(Noble& nob, Warrior& war) {
    if (!nob.hire(war)) {
	cerr << nob.getName() << " failed to hire " << war.getName() << endl;
    }
}

// fire. Calls Noble's fire method, displaying message on succsess and error message on failure
void fire(Noble& nob, Warrior& war) {
    if (nob.fire(war)) {
	cout << war.getName() << ", you don't work for me any more! -- " << nob.getName() << ".\n";
    } else {
	cerr << nob.getName() << " failed to fire " << war.getName() << endl;
    }
}
