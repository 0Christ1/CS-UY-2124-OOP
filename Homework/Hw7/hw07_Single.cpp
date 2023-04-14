/**
  hw07_Single: Medieval Battle 6.0
  Goal: focus on inheritance,
        cyclic association,
        separate compilation and namespace,
        framework
  Problem: We will add more than one type of Noble.
           Now Warriors aren't the only people they can hire to do their fighting
           Nobles are still only ones who go around declaring rhs upon each other
  Created by Haoran Chen on 11/12
 */

#include <iostream>
#include <vector>
using namespace std;

// forward declaration
class Protectors;

class Noble {
    // output overloading
    friend ostream& operator<<(ostream&, const Noble&);
public:
    Noble(const string&);

    // pure virtual methods
    virtual void battleCry() const = 0;
    virtual double getStrength() const = 0;
    virtual void setNewStrength(double) = 0;
    virtual void display() const = 0;

    // getter for Noble's Name
    const string& getNobleName() const;

    // battle method
    void battle(Noble&);

protected:
    // only accessible for battle method and child class
    bool isAlived() const;
private:
    string name;
    bool alive;
};

// derived class of Noble
class Lord : public Noble{
public:
    Lord(const string&);

    // battleCry method
    void battleCry() const;

    // get total strength method
    double getStrength() const;

    // set new strength method
    void setNewStrength(double);

    // hires method
    bool hires (Protectors&);

    // fires method
    bool fires (Protectors&);

    // remove protector method
    bool removePro(const Protectors&);

    // display method
    void display() const;

private:
    vector<Protectors*> army;
};

class Protectors {
    // output overloading
    friend ostream& operator<<(ostream& os, const Protectors& rhs);
public:
    Protectors(const string&, double);

    // getters
    const string& getName() const;
    const string& getBossName() const;
    Lord* getBoss() const;
    double getStrength() const;

    // setters
    void setBoss(Lord*);
    void setStrength(double);

    // pure virtual method
    virtual void defending() const = 0;

    // runaway method
    bool runaway();

private:
    string name;
    double strength;
    Lord* boss;
};

// derived class of Protectors
class Wizard : public Protectors {
public:
    Wizard(const string&, double);
    void defending() const;
};

// derived class of Protectors
class Warriors : public Protectors {
public:
    Warriors(const string&, double);
    void defending() const;
};

// derived class of Warriors
class Archer : public Warriors{
public:
    Archer(const string&, double);
    void defending() const;
};

// derived class of Warriors
class Swordsman : public Warriors {
public:
    Swordsman(const string&, double);
    void defending() const;
};

// derived class of Noble
class PersonWithStrengthToFight : public Noble{
public:
    PersonWithStrengthToFight(const string&, double);
    // battleCry method
    void battleCry() const;

    // getter and setter
    double getStrength() const;
    void setNewStrength(double);

    // display method
    void display() const;

private:
    double strength;
};



// ============== Test Code ===================
int main() {
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250);
    joe.battle(randy);
    joe.battle(sam);
    Lord janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);
    janet.hires(stout);
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);
    janet.battle(barclay);
    janet.hires(samantha);
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);
    sam.battle(barclay);
    joe.battle(barclay);
//    cout << "=========================" << endl;
//
//    Lord daenerys("Daenerys Targaryen");
//    Lord cersei("Cersei Lannister");
//    PersonWithStrengthToFight baelish("baelish", 200);
//
//    Swordsman jaime("Jaime", 300);
//    Swordsman jorah("Jorah", 400);
//    Swordsman jon("Jon Snow", 500);
//    Archer ygritte("Ygritte", 360);
//    Wizard melisandre("Melisandre", 470);
//    Wizard Arya("Arya Stark", 700);
//    Wizard jaqen("Jaqen H’ghar", 800);
//    daenerys.hires(jon);
//    daenerys.hires(jorah);
//    daenerys.hires(Arya);
//    daenerys.hires(ygritte);
//    cersei.hires(jaime);
//    cersei.hires(jaqen);
//    cersei.hires(melisandre);
//
//    //Test for fire
//    daenerys.fires(ygritte);
//    cersei.fires(melisandre);
//
//    //Test for runaway
//    Arya.runaway();
//    jaime.runaway();
//
//    //Test for output operator
//    daenerys.battle(cersei);
//    cout << daenerys << endl;
//    cout << cersei << endl;
//    cout << baelish << endl;
}



// ============== Noble's Definition ===================
ostream& operator<<(ostream& os, const Noble& rhs) {
    os << "\n===========Noble Output=============" << endl;
    os << "Name:\t " << rhs.name << endl;
    os << "Alive: \t " << boolalpha << rhs.alive  << endl;
    os << "Army: ";
    rhs.display();
    os << "=====================================";
    return os;
}

Noble::Noble(const std::string &in_name): name(in_name), alive(true) {}

const string& Noble::getNobleName() const {return name;}

void Noble::battle(Noble &nob) {                           // member of Noble class
    cout << name << " battles " << nob.name << endl;
    // get the total strength from two nobles
    double totalStrength1 = getStrength();
    double totalStrength2 = nob.getStrength();

    // Case 1: if these two nobles were both dead, they wouldn't fight.
    if (!alive && !nob.alive) {
        cout << "Oh, NO! They're both dead! Yuck!" << endl;

        // Case 2: if one noble is dead, they wouldn't fight as well
    }else if (alive && !nob.alive){
        battleCry();
        cout << "He's dead, " << name << endl;
    }else if (!alive && nob.alive){
        nob.battleCry();
        cout << "He's dead, " << nob.name << endl;

        // Case 3: if they are both alive
    }else{
        battleCry();
        nob.battleCry();
        // 3.1 if one total strength is bigger than other
        if (totalStrength1 > totalStrength2) {
            cout << name << " defeats " << nob.name << endl;
            setNewStrength(1 - totalStrength2 / totalStrength1);
            nob.setNewStrength(0);
            nob.alive = false;
        }
        else if (totalStrength1 < totalStrength2) {
            cout << nob.name << " defeats " << name << endl;
            setNewStrength(0);
            nob.setNewStrength(1 - totalStrength1 / totalStrength2);
            alive = false;
        }
            // 3.2 if one total strength is 0, they won't battle
        else if (totalStrength1 == 0) {
            cout << "He cannot fight since no strength or army, ";
            cout << nob.name << endl;
        }
        else if (totalStrength2 == 0) {
            cout << "He cannot fight since no strength or army, ";
            cout << name << endl;
        }
            //3.3 if their total strength is equivalent
        else if (totalStrength1 == totalStrength2) {
            cout << "Mutual Annihilation: " << name;
            cout << " and " << nob.name;
            cout << " die at each other's " << "hands" << endl;
            setNewStrength(0);
            nob.setNewStrength(0);
            alive = false;
            nob.alive = false;
        }
    }
}

bool Noble::isAlived() const {return alive;}



// ================ Lord's Definition ==================
Lord::Lord(const string& in_name): Noble(in_name){}

void Lord::battleCry() const {
    for (size_t i = 0; i < army.size(); ++i) {
        army[i]->defending();
    }
}

// get total strength method
double Lord::getStrength() const {
    double totalStrength = 0.0;
    for (size_t i = 0; i < army.size(); ++i) {
        totalStrength += army[i]->getStrength();
    }
    return totalStrength;
}

// set new strength method
void Lord::setNewStrength(double reduced) {
    for (size_t i = 0; i < army.size(); ++i) {
        double newStrength = army[i]->getStrength() * reduced;
        army[i]->setStrength(newStrength);
    }
}

bool Lord::hires (Protectors& rhs) {
    // if lord is alive and protector is not hired
    if(isAlived() && !rhs.getBoss()) {
        army.push_back(&rhs);
        rhs.setBoss(this);
        return true;
    }
        // if protector is hired
    else if(rhs.getBoss()) {
        return false;
    }
        // if lord is not alive
    else {
        return false;
    }
}

bool Lord::fires (Protectors& rhs) {
    bool fired = false;
    // if lord is alive and protector is hired
    if (isAlived() && rhs.getBoss()) {
        for (size_t i = 0; i < army.size(); ++i) {
            // if protector is not fired and exists inside army
            if (!fired && &rhs == army[i]) {
                fired = true;
                army[i]->setBoss(nullptr);
                // if protector was fired, shift the pointer
            } else if(fired) {
                army[i - 1] = army[i];
            }
        }
        // if the given protector inside army and was fired,
        // we pop the last pointer
        if (fired){
            cout << "You don't work for me anymore " << rhs.getName();
            cout << "! -- " << getNobleName() << '.' << endl;
            army.pop_back();
            rhs.setBoss(nullptr);
            return true;
        }
            // the given protector is not inside army
        else {
            cout << "Attempting to fire the warrior not inside army.";
            return false;
        }
    }
        // if protector is not hired
    else if (!rhs.getBoss()) {
        cout << "Attempting to fire not hired warrior ";
        cout << rhs.getName();
        return false;
    }
        // if lord is not alive
    else {
        cout << getNobleName() << " is dead. He/She cannot fire." << endl;
        return false;
    }
}

bool Lord::removePro(const Protectors& rhs) {
    bool removed = false;
    for (size_t i = 0; i < army.size(); ++i) {
        if (!removed && &rhs == army[i]) {
            removed = true;
            army[i]->setBoss(nullptr);
        } else if (removed) {
            army[i-1] = army[i];
        }
    }
    if (removed) {
        army.pop_back();
        return true;
    }
    return false;
}

void Lord::display() const {
    cout << "\tLord " << getNobleName();
    cout << " owns an army with " << army.size();
    if (army.size() > 1) {
        cout << " protectors" << endl;
    } else {
        cout << " protector" << endl;
    }
    for (size_t i = 0; i < army.size(); ++i) {
        cout << "\t\t" << *army[i];
    }
}



// =============== Protectors' Definition ==============
ostream& operator<<(ostream& os, const Protectors& rhs) {
    os << rhs.name << '\t' << rhs.strength << endl;
    return os;
}

Protectors::Protectors(const string& in_name, double in_strength):
        name(in_name), strength(in_strength), boss(nullptr){}

const string& Protectors::getName() const {return name;}

const string& Protectors::getBossName() const {return boss->getNobleName();}

Lord* Protectors::getBoss() const {return boss;}

void Protectors::setBoss(Lord* in_boss) {boss = in_boss;}

double Protectors::getStrength() const {return strength;}

void Protectors::setStrength(double newStrength) {strength = newStrength;}

bool Protectors::runaway() {
    if (boss) {
        cout << name << " flees in terror, abandoning his lord, ";
        cout << getBossName() << endl;
        boss->removePro(*this);
        return true;
    }
    cout << name << " is not hired so that cannot runaway." << endl;
    return false;
}



// =============== Wizard's Definition ==============
Wizard::Wizard(const string& in_name, double in_strength):
        Protectors(in_name, in_strength){}

void Wizard::defending() const {cout << "POOF!" << endl;}



// =============== Warriors' Definition ==============
Warriors::Warriors(const string& in_name, double in_strength):
        Protectors(in_name, in_strength){}

void Warriors::defending() const {
    cout << " says: Take that in the name of my lord, ";
    cout << getBossName() << endl;
}



// =============== Archer's Definition ==============
Archer::Archer(const string& in_name, double in_strength):
        Warriors(in_name, in_strength){}

void Archer::defending() const {
    cout << "TWANG! " << getName();
    Warriors::defending();
}



// =============== Archer's Definition ==============
Swordsman::Swordsman(const string& in_name, double in_strength):
        Warriors(in_name, in_strength){}

void Swordsman::defending() const {
    cout << "CLANG! " << getName();
    Warriors::defending();
}


// =============== Person's Definition ==============
PersonWithStrengthToFight::PersonWithStrengthToFight
    (const string& in_name, double in_strength):
        strength(in_strength), Noble(in_name) {}

void PersonWithStrengthToFight::battleCry() const {
    cout << "Ugh!" << endl;
}

double PersonWithStrengthToFight::getStrength() const {return strength;}

void PersonWithStrengthToFight::setNewStrength(double newStrength) {
    strength = newStrength;
}

void PersonWithStrengthToFight::display() const {
    cout << "\tNo Army" << endl;
    cout << "\t\tPerson: " << getNobleName() << " was born with strength ";
    cout << getStrength() << endl;
}
