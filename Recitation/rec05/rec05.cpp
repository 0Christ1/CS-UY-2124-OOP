/*
  CS 2124
  rec05: Task based recitation about pointers and operators
  created by Haoran Chen on 09/30
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Complex {
    double real;
    double img;
};

class PlainOldClass {
public:
    PlainOldClass() : x(-72) {}
    int getX() const {return x;}
    void setX(int val) {x =val;}
private:
    int x;
};

class PlainOldClassV2 {
public:
    PlainOldClassV2() : x(-72) {}
    int getX() const { return x; }
//    void setX( int x )  { x = x; } // HMMMM???

//    int getX( const PlainOldClass* const this = &poc ) const { return x; }
//    void setX( PlainOldClass* const this = &poc, int x )  { x = x; } // Still HMMMM???
    void setX(int x) {this->x = x;}  // No confusion
private:
    int x;
};

class Colour {
public:
    Colour(const string& name, unsigned r, unsigned g, unsigned b)
            : name(name), r(r), g(g), b(b) {}
    void display() const {
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
    }
private:
    string name;      // what we call this colour
    unsigned r, g, b; // red/green/blue values for displaying
};


class SpeakerSystem {
public:
    void vibrateSpeakerCones(unsigned signal) const {

        cout << "Playing: " << signal << "Hz sound..." << endl;
        cout << "Buzz, buzzy, buzzer, bzap!!!\n";
    }
};

class Amplifier {
public:

    void attachSpeakers(SpeakerSystem& spkrs)
    {
        if(attachedSpeakers)
            cout << "already have speakers attached!\n";
        else
            attachedSpeakers = &spkrs;
    }

    void detachSpeakers() { // should there be an "error" message if not attached?
        attachedSpeakers = nullptr;
    }

    void playMusic() const {
        if (attachedSpeakers)
            attachedSpeakers -> vibrateSpeakerCones(440);
        else
            cout << "No speakers attached\n";
    }
private:
    SpeakerSystem* attachedSpeakers = nullptr;
};

class Person {
public:
    Person(const string& name) : name(name) {}
    bool movesInWith(Person& newRoomate) {
        if (!roomie && !newRoomate.roomie
        && newRoomate.roomie != this) {
            roomie = &newRoomate;        // now I have a new roomie
            newRoomate.roomie = this;    // and now they do too
            return true;
        }
        return false;
    }
    const string& getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    const string& getRoomiesName() const { return roomie->getName(); }
private:
    Person* roomie = nullptr;
    string name;
};

int main() {

    // Task 1
    // write a usual comment at the top.

    // Task 2
    int x;
    x = 10;
    cout << "x = " << x << endl;

    // Task 3
//    cout << "Task3: " << '\n';
//    int x;      // The garbage value stored in x is 1
//    x = 10;
//    cout << "x = " << x << endl;

    // Task 4
//    cout << "Task4: " << '\n';
//    int x;
//    x = 10;      // The value of x changed to 10
//    cout << "x = " << x << endl;

    // Task 5
//    cout << "Task5: " << '\n';
//    // if expression is x*y-17, it wouldn't compile (no y)
//    // if expression is x-17, it would be -16 at this moment
//    int x;
//    x = 10;
//    cout << "x = " << x << endl;

    // Task 6
    // unary operator: &(address-of)
    // Note: & is NOT the "reference to" operator
//    cout << "Task6: " << '\n';
//    int x;
//    // &x = 0x7ff7b32b79c
//    x = 10;
//    cout << "x = " << x << endl;
//    cout << 0xB << endl;            // 11
//    cout << hex << 0xB << endl;     // b
//    cout << dec << 0xB << endl;     // 11

    // Task 7
//    cout << "Task7: " << '\n';
//    int x;
//    x = 10;   // the value stored AT the address of x (&x)
//    cout << "x = " << x << endl;

    // Task 8
    int* p;
    p = &x;
    cout << "p = " << p << endl;

    // Task 9
    // unary operator: * (deference operator)
//    cout << "Task9: " << '\n';
//    p = 0x7ff7b32b79c;      // cannot convert from 'int' to 'int*'
//    p = 100000;

//    int* p1;
//    int *p2;
//    int * p3;               // p1, p2, p3 are all the same
//    int* p1, p2, *p3;       // not clear to p2 and p3

    // Task 10
//    cout << "Task10: " << '\n';
//    cout << "p = " << p << endl;
//    // *p is the "dereference operator" applied to the variable p
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;

    // Task 11
    *p = -2763;
    cout << "p points to where " << *p << " is      stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "x now contains " << x << endl;

    // Task 12
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;

    // Task 13
    int* q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;

    // Task 14
    double d(33.44);
    double* pD(&d);
    *pD = *p;
    *pD = 73.2343;
    *p = *pD;
    *p = *q;
//    pD = p;
//    p = pD;

    // Task 15
//    int joe = 24;
//    const int sal = 19;
//    int*  pI;
//    pI = &joe;
//    *pI = 234;
//    pI = &sal;      // Assigning to 'int *' from 'const int *' discards qualifiers
//    *pI = 7623;
//
//    const int* pcI;
//    pcI = &joe;
//    *pcI = 234;     // because of const int, cannot change the value
//    pcI = &sal;     // but we can change the address
//    *pcI = 7623;
//
//    int* const cpI;         // need to initialize the address
//    int* const cpI(&joe);   // redefine
//    int* const cpI(&sal);   // cannot change the address
//    cpI = &joe;             // cannot change the address
//    *cpI = 234;             // but can change dereference
//    cpI = &sal;
//    *cpI = 7623;
//
//    const int* const cpcI;          // need to initialize the address
//    const int* const cpcI(&joe);    // cannot change the address
//    const int* const cpcI(&sal);
//    cpcI = &joe;  // *cpcI = 234;
//    cpcI = &sal;
//    *cpcI = 7623;                   // cannot change dereference

    // Task 16
    // unary operator: -> (arrow)
    Complex c = {11.23, 45.67};
    Complex* pC(&c);
//    cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
    cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;

    // Task 17
    PlainOldClass pos;
    PlainOldClass* ppoc(&pos);
    cout << ppoc -> getX() << endl;
    ppoc ->setX( 2837 );
    cout << ppoc -> getX() << endl;

    // Task 18
//    void setX( int x )  { this->x = x; } // No confusion!

    // Task 19
    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap;
    *pDyn = 17;
    cout << "The " << *pDyn
         << " is stored at address " << pDyn
         << " which is in the heap\n";

    // Task 20
    cout << pDyn << endl;
    int* pDyn2 = pDyn;
    delete pDyn;
    cout << pDyn << endl;

    cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";
    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
    cout << "pDyn2: " << *pDyn2 << endl;

    // Task 21
    pDyn = nullptr;
    double* pDouble = nullptr;

    // Task 22
//    cout << "Can we dereference nullptr?  " << *pDyn << endl;
//    cout << "Can we dereference nullptr?  " << *pDouble << endl;

    // Task 23
    // this pointer cannot be nullptr

    // Task 24
    double* pTest = new double(12);
    delete pTest;
    pTest = nullptr;
    delete pTest; // safe

    // Task 25
    short* pShrt = new short(5);
    delete pShrt;
//    delete pShrt;

    // Task 26
    long jumper = 12238743;
//    delete jumper;              // delete can only be used with the heap
//    long* ptrTolong = &jumper;
//    delete ptrTolong;
    Complex cmplx;
//    delete cmplx;

    // Task 27
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        tmpPCmplx = new Complex; // create a new Complex object on the heap
        tmpPCmplx->real = ndx;   // set real and img to be the
        tmpPCmplx->img  = ndx;   // value of the current ndx
        complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
    }
// display the objects using the pointers stored in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        cout << complV[ ndx ]->real << endl;
        cout << complV[ ndx ]->img  << endl;
    }
// release the heap space pointed at by the pointers in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        delete complV[ndx];
    }
// clear the vector
    complV.clear();

    // Task 28
    vector<Colour*> colours;
    string inputName;
    unsigned inputR, inputG, inputB;

// fill vector with Colours from the file
// this could be from an actual file but here we are using the keyboard instead of a file
// (so we don't have to create an actual file)
// Do you remember the keystroke combination to indicate "end of file" at the keyboard?
// somehow the while's test has to fail - from keyboard input
    while (cin >> inputName >> inputR >> inputG >> inputB) {
        colours.push_back(new Colour(inputName, inputR, inputG, inputB));
    }

// display all the Colours in the vector:
    for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
        colours[ndx]->display();
        cout << endl;
    }

    // Task 30
    // write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane");

// now model these two becoming roommates
    joeBob.movesInWith(billyJane);

// did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
}
