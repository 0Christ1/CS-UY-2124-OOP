/**
 * Haoran Chen
 * rec 09
 */

#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

namespace CS2124 {

    int gcd(int x, int y);

    class Rational {
        friend std::ostream &operator<<(std::ostream &, const Rational &);

        friend std::istream &operator>>(std::istream &, Rational &);

        // == Implement
        friend bool operator==(const Rational &lhs, const Rational &rhs);

        // < Implement
        friend bool operator<(const Rational &lhs, const Rational &rhs);

    public:
        Rational(int num = 0, int denom = 1);

        // += Implement as a member function
        Rational &operator+=(const Rational &);

        // ++ pre
        Rational &operator++();

        // ++ post
        Rational operator++(int);

        //conversion operator, 0 is false, all else is true
        explicit operator bool() const;

    private:
        int numerator;
        int denominator;

        void normalize();
    };

    Rational operator+(const Rational &lhs, const Rational &rhs);

    Rational &operator--(Rational &rhs);

    Rational operator--(Rational &rhs, int dummy);

    bool operator!=(const Rational &lhs, const Rational &rhs);

    bool operator<=(const Rational &lhs, const Rational &rhs);

    bool operator>(const Rational &lhs, const Rational &rhs);

    bool operator>=(const Rational &lhs, const Rational &rhs);
}

#endif //RATIONAL_H
