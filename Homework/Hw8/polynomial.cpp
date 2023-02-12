/**
 * hw08: Polynomial
 * Haoran Chen
 * Polynomial cpp: class member and func definitions
 */

#include <iostream>
#include <vector>
#include "polynomial.h"
using namespace std;

namespace poly {

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
}