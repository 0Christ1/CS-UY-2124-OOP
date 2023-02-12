// Doubly linked list
//  Test code

#include <cstdlib>
#include <iostream>
using namespace std;

class List {
    struct Node {
        Node(int in_data = 0, Node* next = nullptr, Node* prior = nullptr)
                : data(in_data), next(next), prior(nullptr){}
        int data;
        Node* next;
        Node* prior;
    };

    friend ostream& operator<<(ostream& os, const List& rhs){
        for (const Node* p = rhs.header->next; p!=rhs.trailer; p = p->next) {
            os << p->data << ' ';
        }
        return os;
    }
public:
    class iterator{
        friend bool operator==(const iterator& lhs, const iterator& rhs) {
            return lhs.where == rhs.where;
        }

        friend List;

    public:
        explicit iterator(Node* ptr) : where(ptr) {}

        iterator& operator++() {
            where = where->next;
            return *this;
        }

        iterator& operator--() {
            where = where->prior;
            return *this;
        }

        int& operator*() const {
            return where->data;
        }

    private:
        Node* where;
    };

    List(): the_size(0), header(new Node()), trailer(new Node()){
        header->next = trailer;
        trailer->prior = header;
    }

    List(const List& rhs): List() { // constructor delegation
        for(Node* p = rhs.header->next; p!=rhs.trailer; p=p->next){
            push_back(p->data);
        }
    }

    ~List() {
        clear();
        delete header;
        delete trailer;
    }

    List& operator=(const List& rhs) {
        if (this != &rhs) {
            clear();
            for(Node* p = rhs.header->next; p!=rhs.trailer; p=p->next){
                push_back(p->data);
            }
        }
        return *this;
    }



    void push_back(int data) {
        Node* node = new Node(data);
        trailer->prior->next = node;
        node->prior = trailer->prior;
        trailer->prior = node;
        node->next = trailer;
        the_size++;
    }

    void pop_back() {
        if (the_size != 0) {
            Node* removed = trailer->prior;
            Node* nl = trailer->prior->prior;
            nl->next = trailer;
            trailer->prior = nl;
            delete removed;
            the_size--;
        }
    }

    int front() const {
        if (the_size == 0) {
            cout << "";
        }
        return header->next->data;
    }


    int& front() {
        if (the_size == 0) {
            cout << "";
        }
        return header->next->data;
    }

    int back() const {
        if (the_size == 0) {
            cout << "";
        }
        return trailer->prior->data;
    }

    int& back() {
        if (the_size == 0) {
            cout << "";
        }
        return trailer->prior->data;
    }

    size_t size() const {
        return the_size;
    }

    void push_front(int data) {
        Node* node = new Node(data);
        Node* f = header->next;
        header->next = node;
        node->prior = header;
        node->next = f;
        f->prior = node;
        the_size++;
    }

    void pop_front() {
        if (the_size != 0) {
            Node* removed = header->next;
            Node* nf = header->next->next;
            header->next = nf;
            nf->prior = header;
            delete removed;
            the_size--;
        }
    }

    void clear() {
        while (header->next != trailer) {
            header = header->next;
            delete header->prior;
        }
        header->next = trailer;
        trailer->prior = header;
        the_size = 0;
    }

    int operator[](size_t i) const {
        Node* node = header->next;
        if (i < the_size) {
            while (i != 0) {
                node = node->next;
                i--;
            }
        }
        return node->data;
    }

    int& operator[](size_t i) {
        Node* node = header->next;
        if (i < the_size) {
            while (i != 0) {
                node = node->next;
                i--;
            }
        }
        return node->data;
    }

    iterator begin() {
        return iterator(header->next);
    }

    iterator end() {
        return iterator(trailer);
    }

    iterator insert(const iterator& it, int i) {
        Node* bef = it.where->prior;
        Node* aft = it.where;
        Node* add = new Node(i);
        add->prior = bef;
        bef->next = add;
        add->next = aft;
        aft->prior = add;
        the_size++;
        return iterator(add);
    }

    iterator erase(const iterator& it) {
        Node* bef = it.where->prior;
        Node* aft = it.where->next;
        bef->next = aft;
        aft->prior = bef;
        delete it.where;
        the_size--;
        return iterator(aft);
    }

private:
    Node* header;
    Node* trailer;
    size_t the_size;
};

bool operator !=(const List::iterator& lhs, const List::iterator& rhs) {
    return !(lhs == rhs);
}

// Task 1
void printListInfo(const List& myList) {
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList){
    theList.front() = 17;
    theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}    

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    
    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    printListInfo(myList);
    cout << "===================\n";

    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
         << "the data in the third item in the list\n"
         << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);


    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";

    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
}
