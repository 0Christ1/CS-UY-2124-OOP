/**
 * hw08: Polynomial
 * Haoran Chen
 * Polynomial header: prototypes and class fields
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

namespace poly {

    class Polynomial {
        /// Node structure
        struct Node;

        /// output operator
        friend std::ostream &operator<<(std::ostream &, const Polynomial &);

        /// equality operator
        friend bool operator==(const Polynomial &, const Polynomial &);

    public:
        /// default constructor
        Polynomial();

        /// non-default constructor
        Polynomial(const std::vector<int> &);

        /// destructor
        ~Polynomial();

        /// copy constructor
        Polynomial(const Polynomial &);

        /// assignment operator
        Polynomial &operator=(const Polynomial &);

        /// += operator
        Polynomial &operator+=(const Polynomial &);

        /// evaluate method
        int evaluate(int) const;

        /// cleanup method
        void cleanup();

    private:
        Node *header;
        size_t k;
    };

    /// != operator
    bool operator!=(const Polynomial&, const Polynomial&);

    /// + operator
    Polynomial operator+(const Polynomial&, const Polynomial&);

    void doNothing(Polynomial);
}
#endif //POLYNOMIAL_H
