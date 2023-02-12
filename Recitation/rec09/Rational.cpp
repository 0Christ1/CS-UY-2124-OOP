#include "Rational.h"
#include <iostream>

using namespace std;

namespace CS2124{
    ostream& operator<<(ostream& os, const Rational& rhs) {
        if (rhs.denominator == 1) {
            os << rhs.numerator;
        } else {
            os << rhs.numerator << '/' << rhs.denominator;
        }
        return os;
    }

    istream& operator>>(istream& is, Rational& rhs) {
        char slash;
        is >> rhs.numerator >> slash >>  rhs.denominator;
        rhs.normalize();
        return is;
    }

    bool operator==(const Rational& lhs, const Rational& rhs){
        return lhs.numerator==rhs.numerator && lhs.denominator == rhs.denominator;
    }

    bool operator<(const Rational& lhs, const Rational& rhs){
        return lhs.numerator*rhs.denominator < rhs.numerator*lhs.denominator;
    }

    Rational::Rational(int num, int denom): numerator(num), denominator(denom) {normalize();}

    Rational& Rational::operator+=(const Rational& rhs) {
        if (denominator == rhs.denominator) {
            numerator += rhs.numerator;
        } else {
            numerator = numerator*(rhs.denominator) + (rhs.numerator)*denominator;
            denominator = denominator*(rhs.denominator);
        }
        normalize();
        return *this;
    }

    void Rational::normalize() {      // keep denominator positive and minimal
        if (!denominator) {
            cout << "denominator cannot be 0." << endl;
        }
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        int ratio = gcd(abs(numerator), abs(denominator));
        if (ratio > 1) {
            numerator/= ratio;
            denominator/= ratio;
        }
    }

    Rational& Rational::operator++(){
        numerator += denominator;
        return *this;
    }

    Rational Rational::operator++(int val) {
        Rational original(*this);
        numerator += denominator;
        return original;
    }

    Rational::operator bool () const {
        return numerator != 0;
    }

// + Implement
    Rational operator+(const Rational& lhs, const Rational& rhs) {
        Rational result = lhs;
        result += rhs;
        return result;
    }

// pre -- Implement
    Rational& operator--(Rational& rhs) {
        rhs += -1;
        return rhs;
    }

// post -- Implement
    Rational operator--(Rational& rhs, int dummy) {
        Rational original(rhs);
        rhs += -1;
        return original;
    }

    int gcd(int x, int y) {
        while (y) {
            int z = y;
            y = x%y;
            x = z;
        }
        return x;
    }

// != Implement
    bool operator!=(const Rational& lhs, const Rational& rhs){
        return !(lhs == rhs);
    }

// <= Implement
    bool operator<=(const Rational& lhs, const Rational& rhs){
        return lhs==rhs || lhs<rhs;
    }

// > Implement
    bool operator>(const Rational& lhs, const Rational& rhs){
        return rhs < lhs;
    }

// >= Implement
    bool operator>=(const Rational& lhs, const Rational& rhs){
        return lhs == rhs || lhs > rhs;
    }
}
