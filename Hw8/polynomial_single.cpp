/**
  hw08: Polynomial
  Goal: focus on Linked Lists,
        operator overloading,
        copy control，
        separate compilation
  Problem: implement a class Polynomial for storing
           and manipulating polynomial expressions
  Created by Haoran Chen on 12/2/22.
 */

#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
    /// Node structure
    struct Node;

    /// output operator
    friend ostream& operator<<(ostream&, const Polynomial&);

    /// equality operator
    friend bool operator==(const Polynomial&, const Polynomial&);

public:
    /// default constructor
    Polynomial();

    /// non-default constructor
    Polynomial(const vector<int>&);

    /// destructor
    ~Polynomial();

    /// copy constructor
    Polynomial(const Polynomial&);

    /// assignment operator
    Polynomial& operator=(const Polynomial&);
    /// += operator
    Polynomial& operator+=(const Polynomial&);

    /// evaluate method
    int evaluate(int) const;

    /// cleanup method
    void cleanup();

private:
    Node* header;
    size_t k;
};

/// != operator
bool operator!=(const Polynomial&, const Polynomial&);

/// + operator
Polynomial operator+(const Polynomial&, const Polynomial&);

void doNothing(Polynomial temp);

int main() {
    //test constructor
    Polynomial p1({17});                 // 17
    Polynomial p2({1, 2});               // x + 2
    Polynomial p3({-1, 5});              // -x + 5
    Polynomial p4({5, 4, 3, 2, 1});      // 5x^4 + 4x^3 + 3x^2 + 2x + 1
    Polynomial has_a_zero({4, 0, 1, 7}); // 4x^3 + x + 7

    // Polynomial temp(p4);
    // cout << "temp: " << temp << endl;

    //    cerr << "displaying polynomials\n";
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;
    cout << "has_a_zero: " << has_a_zero << endl;

    // Polynomial temp;
    // temp = p2 + p3;
    // cout << "temp: " << temp << endl;

    cout << "p2 + p3: " << (p2+p3) << endl;
    cout << "p2 + p4: " << (p2+p4) << endl;
    cout << "p4 + p2: " << (p4+p2) << endl;

    //test copy constructor - the statement below uses the copy constructor
    //to initialize poly3 with the same values as poly4
    Polynomial p5(p4);
    p5 += p3;
    cout << "Polynomial p5(p4);\n"
         << "p5 += p3;\n";

    cout << "p4: " << p4 << endl;
    cout << "p5: " << p5 << endl;


    cout << "Calling doNothing(p5)\n";
    doNothing(p5);
    cout << "p5: " << p5 << endl;

    //tests the assignment operator
    Polynomial p6;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;  // Causes bools true and false to be printed that way.
    cout << "(p4 == p6) is " << (p4 == p6) << endl;
    p6 = p4;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;
    cout << "(p4 == p6) is " << (p4 == p6) << endl;

    //test the evaluaton
    int x = 5;
    cout << "Evaluating p1 at " << x << " yields: " << p1.evaluate(5) << endl;
    cout << "Evaluating p2 at " << x << " yields: " << p2.evaluate(5) << endl;

    Polynomial p7({3, 2, 1});           // 3x^2 + 2x + 1
    cout << "p7: " << p7 << endl;
    cout << "Evaluating p7 at " << x << " yields: " << p7.evaluate(5) << endl;

    cout << boolalpha;
    cout << "(p1 == p2) is " << (p1 == p2) << endl;
    cout << "(p1 != p2) is " << (p1 != p2) << endl;

    /*=================================================================
    NEW TEST CODE - test if cleaning the leading 0s
    ===================================================================*/

    Polynomial p8({ 1, 1 });
    Polynomial p9({ -1, 1 });
    Polynomial p10({ 0, 0, 2 });
    //p8 + p9 tests if += does the cleanup()
    //p10 tests if constructor does the cleanup()
    cout << "((p8 + p9) == p10) is " << ((p8 + p9) == p10) << endl;


}

/// Node structure
struct Polynomial::Node{
    Node(int in_data = 0, Node* in_next = nullptr):
            data(in_data), next(in_next) {}
    int data;
    Node* next;
};

/// output operator
ostream& operator<<(ostream& os, const Polynomial& rhs) {
    const Polynomial::Node* p = rhs.header;
    if (rhs.k != 0) {
        // rhs.k + 1 is the length of rhs
        for (size_t i = 0; i < rhs.k + 1; ++i) {
            if (p->data != 0) {
                // print the + operand
                if (i != rhs.k) {
                    os << " + ";
                }
                // print the coefficient
                if (rhs.k - i == 0 || p->data != 1) {
                    os << p->data;
                }
                // print the x^1 or x^degree
                if (rhs.k - i > 1) {
                    os << "x^" << rhs.k - i;
                } else if (rhs.k - i == 1) {
                    os << 'x';
                }
            }
            p = p->next;
        }
    } else {
        os << rhs.header->data;
    }
    return os;
}

/// equality operator
bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
    if (lhs.k != rhs.k) return false;
    const Polynomial::Node* lhs_ptr = lhs.header;
    const Polynomial::Node* rhs_ptr = rhs.header;
    while(lhs_ptr){
        if (lhs_ptr->data != rhs_ptr->data) return false;
        lhs_ptr = lhs_ptr->next;
        rhs_ptr = rhs_ptr->next;
    }
    return true;
}

/// default constructor
Polynomial::Polynomial() {
    header = new Node();
    k = 0;
}

/// non-default constructor
Polynomial::Polynomial(const vector<int>& vec){
    if (vec.size() != 0){
        header = new Node(vec[0]);
        Node* ptr = header;
        for (size_t i = 1; i < vec.size(); ++i) {
            ptr->next = new Node(vec[i]);
            ptr = ptr->next;
        }
        k = vec.size()-1;
    } else {
        header = new Node();
        k = 0;
    }
    cleanup();
}

/// destructor
Polynomial::~Polynomial(){
    Node* ptr = header;
    while (ptr) {
        Node* deleted = ptr;
        ptr = ptr->next;
        delete deleted;
    }
}

/// copy constructor
Polynomial::Polynomial(const Polynomial& rhs):
        header(new Node(rhs.header->data)), k(rhs.k) {
    Node* ptr = header;
    for (const Node* p = rhs.header->next; p; p = p->next) {
        ptr->next = new Node(p->data);
        ptr = ptr->next;
    }
}

/// assignment operator
Polynomial& Polynomial::operator=(const Polynomial& rhs){
    if (this != &rhs) {
        Node* ptr = header;
        while (ptr) {
            Node* deleted = ptr;
            ptr = ptr->next;
            delete deleted;
        }
        k = rhs.k;
        header = new Node(rhs.header->data);
        Node* new_ptr = header;
        for (const Node* p = rhs.header->next; p; p = p->next) {
            new_ptr->next = new Node(p->data);
            new_ptr = new_ptr->next;
        }
    }
    return *this;
}

/// += operator
Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
    Node* p1 = header;
    const Node* p2 = rhs.header;
    size_t diff;
    if (k > rhs.k) {
        diff = k - rhs.k;
        while (diff > 0) {
            p1 = p1->next;
            --diff;
        }
    }else if ( k < rhs.k) {
        diff = rhs.k - k;
        for (size_t i = 0; i < diff; ++i) {
            header = new Node(0, header);
            p1 = header;
            ++k;
        }
    }
    for (Node* p = p1; p; p=p->next) {
        p->data += p2->data;
        p2 = p2->next;
    }
    cleanup();
    return *this;
}

/// evaluate method
int Polynomial::evaluate(int x) const{
    const Node* ptr = header;
    int ans = 0;
    for (size_t i = k+1; i > 0; --i) {
        size_t power = i-1;
        int power_res = 1;
        for (size_t j = 0; j < power; ++j){
            power_res *= x;
        }
        ans += power_res * ptr->data;
        ptr = ptr->next;
    }
    return ans;
}

/// cleanup method
void Polynomial::cleanup() {
    if (k == 0) return;
    while (header->next && header->data == 0){
        header = header->next;
        --k;
    }
}

/// != operator
bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
    return !(lhs == rhs);
}

/// + operator
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial res = lhs;
    res += rhs;
    return res;
}

void doNothing(Polynomial temp) {}


