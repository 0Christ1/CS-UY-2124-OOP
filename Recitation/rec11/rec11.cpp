/*
  rec11.cpp
  Starting code 21F
  Haoran Chen
 */

#include <iostream>
#include <vector>
using namespace std;


class Instrument {
public:
    virtual void makeSound() const = 0;
    virtual void play() const = 0;
};

void Instrument::makeSound() const{   // optional but have to define outside
    cout << "To make a sound...";
}

class Brass : public Instrument{
public:
    Brass(unsigned in_m): mouthpiece(in_m) {}

    void makeSound() const {
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size " << mouthpiece << endl;
    }

private:
    unsigned mouthpiece;
};

class String : public Instrument{
public:
    String(unsigned in_pitch): pitch(in_pitch){}
    void makeSound() const {
        Instrument::makeSound();
        cout << "bow a string with pitch " << pitch << endl;
    }
private:
    unsigned pitch;
};

class Percussion : public Instrument {
public:
    void makeSound() const {
        Instrument::makeSound();
        cout << "hit me!" << endl;
    }
};

class Trombone : public Brass {
public:
    Trombone(unsigned in_pitch): Brass(in_pitch) {}

    void play() const {
        cout << "Blat";
    }
};
class Trumpet : public Brass {
public:
    Trumpet(unsigned in_pitch): Brass(in_pitch) {}

    void play() const {
        cout << "Toot";
    }
};

class Violin : public String {
public:
    Violin(unsigned in_pitch): String(in_pitch) {}

    void play() const {
        cout << "Screech";
    }
};

class Cello : public String {
public:
    Cello(unsigned in_pitch): String(in_pitch) {}

    void play() const {
        cout << "Squawk";
    }
};

class Drum : public Percussion {
public:
    void play() const {
        cout << "Boom";
    }
};

class Cymbal : public Percussion {
public:
    void play() const {
        cout << "Crash";
    }
};

class MILL {
public:
    void receiveInstr (Instrument& rhs) {
        rhs.makeSound();
        for (size_t i = 0; i < inventory.size(); ++i) {
            if (!inventory[i]) {
                inventory[i] = &rhs;
                return; // method/non-member: jump;  break: loop jump. exit: program stop
            }
        }
        inventory.push_back(&rhs);
    }

    Instrument* loanOut() {
        for (size_t i = 0; i < inventory.size(); ++i) { // don't add more statement
            if (inventory[i]) {
                Instrument* inst = inventory[i];
                inventory[i] = nullptr;
                return inst;
            }
        }
        return nullptr;
    }

    void dailyTestPlay() const {
        for (size_t i = 0; i < inventory.size(); ++i) {
            if (inventory[i]) {
                inventory[i]->makeSound();
            }
        }
    }

private:
    vector<Instrument*> inventory;
};

class Musician {
public:
    Musician() : instr(nullptr) {}

    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    Instrument* giveBackInstr() { 
        Instrument* result(instr); 
        instr = nullptr;
        return result;
    }

    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }

    void play() const {
        if (instr){
            instr->play();
        }
    }

private:
    Instrument* instr;
};

class Orch {
public:
    void addPlayer(Musician& rhs) {
        for (size_t i = 0; i < musicians.size(); ++i) {
            if (musicians[i] == &rhs) {
                return;
            }
        }
        musicians.push_back(&rhs);
    }

    void play() const {
        for (size_t i = 0; i < musicians.size(); ++i) {
            musicians[i]->play();
        }
        cout << endl;
    }
private:
    vector<Musician*> musicians;
};

int main() {

    //
    // PART ONE
    //
    cout << "P A R T  O N E\n";

    cout << "Define some instruments ----------------------------------------\n";
     Drum drum;
     Cello cello(673);
     Cymbal cymbal;
     Trombone tbone(4);
     Trumpet trpt(12) ;
     Violin violin(567) ;
  
    // use the debugger to look at the mill
    cout << "Define the MILL ------------------------------------------------\n";
     MILL mill;
  
    cout << "Put the instruments into the MILL ------------------------------\n";
     mill.receiveInstr(trpt);
     mill.receiveInstr(violin);
     mill.receiveInstr(tbone);
     mill.receiveInstr(drum);
     mill.receiveInstr(cello);
     mill.receiveInstr(cymbal);
  
    cout << "Daily test -----------------------------------------------------\n"
	 << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();   // determine nullptr
     cout << endl;
  
    cout << "Define some Musicians-------------------------------------------\n";
     Musician harpo;
     Musician groucho;
  	
     cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
     groucho.testPlay();
     cout << endl;
     groucho.acceptInstr(mill.loanOut());
     cout << endl;
     groucho.testPlay();
     cout << endl;
     cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
  
     cout << endl << endl;
  
     groucho.testPlay();
     cout << endl;
     mill.receiveInstr(*groucho.giveBackInstr());
     harpo.acceptInstr(mill.loanOut());
     groucho.acceptInstr(mill.loanOut());
     cout << endl;
     groucho.testPlay();
     cout << endl;
     harpo.testPlay();
     cout << endl;
     cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
  
     cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
  
     // fifth
     mill.receiveInstr(*groucho.giveBackInstr());
     cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
     mill.receiveInstr(*harpo.giveBackInstr());

  
     cout << endl;
     cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
     cout << endl;
  
     cout << endl;


    //
    // PART TWO
    //
    

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
	
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

}
