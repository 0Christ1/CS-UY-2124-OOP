#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned in_numberOfPages) : numberOfPages(in_numberOfPages){}

//    virtual void displayNumPages() const {cout << numberOfPages;}

    virtual void displayNumPages() const = 0;

//    friend ostream& operator<<(ostream& os, const PrintedMaterial& rhs) {
//        os << rhs.numberOfPages << endl;
//        return os;
//    }

private:
    unsigned numberOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numberOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned in_numberOfPages): PrintedMaterial(in_numberOfPages){}

    // virtual - NOTE even without writing "virtual"
    // again, this overriden method IS virtual
    // viruality cannot be removed once installed
    // Also note that the = 0 has is not there
    void displayNumPages() const {
        cout << "Hi, I'm a Magazine object stored\n"
             << "(but I can't know that I am being\n"
             << "stored (by pointer) in a vector of\n"
             << "PrintedMaterial pointers!\n";
        PrintedMaterial::displayNumPages();
        cout << "(and I'm very glossy!\n";
    }
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned in_numberOfPages): PrintedMaterial(in_numberOfPages){}
private:

};

class TextBook : public Book {
public:
    TextBook(unsigned in_numberOfPages, unsigned in_numberOfIndexPages)
        : Book(in_numberOfPages), numOfIndexPages(in_numberOfIndexPages){}

//    void displayNumPages() const {
//        cout << "Pages: ";
//        PrintedMaterial::displayNumPages();
//        cout << "\nIndex pages";
//        cout << numOfIndexPages;
//    }
    void displayNumPages() const {
        cout << "\nThis is a textbook.\n";
        cout << "It is a very boring textbook.\n";
        cout << "Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Index pages: ";
        cout << numOfIndexPages << endl;
    }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
//    using Book::Book;
    Novel(unsigned in_numberOfPages): Book(in_numberOfPages){}

    void displayNumPages() const {
        cout << "\nThis is the story of a very\n"
             << " interesting programmer's quest\n"
             << "  to understand inheritance.\n"
             << "   The journey is just beginning\n"
             << "    and already the journeyman\n"
             << "      hacker, no - not a hacker! -\n"
             << "         a programmer who reads, and\n"
             << "             studies and understands code\n"
             << "                 Hackers steal and don't even\n"
             << "                      try to understand what they stole\n"
             << "                           before using it.\n"
             << "\n       ...But I digress.\n"
             << "\nThis novel is quite long, there\n"
             << "being this number of pages:\n"
             << "=====================================\n"
             << "                 ";
        PrintedMaterial::displayNumPages();
        cout << "=====================================\n"
             << "Whew!\n"
             << " but there is an exciting\n"
             << "  programming adventure on every\n"
             << "   single one of them!\n"
             << "    And now, let's let the quest continue..."
             << endl << endl << endl;
    }
private:
};

// note that here, reference to PrintedMaterial is the parameter type
// so now we can use the dot member operator (the .)  if use the ->
// operator, that's not going to work (try it!)
void displayNumberOfPages (const PrintedMaterial& rhs) {
    rhs.displayNumPages();
}

// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";

//    cout << "\nA PrintedMaterial material object!\n";
//    PrintedMaterial pm(2345);
//    pm.displayNumPages();

//    cout << "\nA PrintedMaterial variable containing a TextBook value\n";
//    pm = text; // like putting a Textbook into a PrintedMaterial
//    pm.displayNumPages();

//    cout << "\nTry using pointer to base type\n";
//    PrintedMaterial* pmPtr;
//    pmPtr = &text;
//    pmPtr->displayNumPages();

//    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//    cout << "\nNow with the virtual mechanism involved\n";
//    // should work now that the virtual mechanism is being invoked
//    PrintedMaterial* pmPtr;
//    pmPtr = &text;
//    pmPtr->displayNumPages();

//     print some stuff by calling a generic function
//    cout << "\nUse a generic functino for printing\n";
//    displayNumberOfPages(mag);
//    displayNumberOfPages(novel);
//    displayNumberOfPages(text);

//    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//    cout << "Now with the virtual mechanism involved\n";
//    PrintedMaterial* pmPtr;
//    pmPtr = &text; // like putting t into a vector but
    // we are actually putting the address of t
    // into a vector pointers of pointers to
    // PrintedMaterials. We'll "say" we are putting
    // t into the vector
    // (that is, pointers to the Base class)
//    pmPtr->displayNumPages();
    // Storing generic objects in a vector
    cout << "\n\nNow we'll use a container. Yea!!!\n\n";
    vector<PrintedMaterial*> vec;
    vec.push_back(&text);
    vec.push_back(&novel);
    vec.push_back(&mag);
    for (size_t i = 0; i < vec.size(); ++i) {
        vec[i]->displayNumPages();
        cout << endl;
    }
    cout << "===========\n";
    for (PrintedMaterial* ptr: vec) {
        ptr->displayNumPages();
        cout << endl;
    }
}