/**
 * Haoran Chen
 * rec 09
 */

#include <iostream>
#include <vector>

using namespace std;


// numbers except 0 is true
// operator bool, part of the name bool()

int gcd(int x, int y);

class Rational {
    friend ostream& operator<<(ostream&, const Rational&);

    friend istream& operator>>(istream&, Rational&);

    // == Implement
    friend bool operator==(const Rational& lhs, const Rational& rhs);

    // < Implement
    friend bool operator<(const Rational& lhs, const Rational& rhs);

public:
    Rational(int num = 0, int denom=1);

    // += Implement as a member function
    Rational& operator+=(const Rational&);

    // ++ pre
    Rational& operator++();

    // ++ post
    Rational operator++(int);

    //conversion operator, 0 is false, all else is true
    explicit operator bool () const;

private:
    int numerator;
    int denominator;

    void normalize();
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational& operator--(Rational& rhs);
Rational operator--(Rational& rhs, int dummy);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);



int main() {
    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    const Rational one = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;	// Implement as member
    cout << "a = " << a << endl;

    // Implement + as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;

    // How does this manage to work?
    // It does NOT require writing another == operator.
    cout << "1 == one: " << boolalpha << (1 == one) << endl;

    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;

    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
//    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing?
    //cout << "a-- -- = " << (a-- --) << endl;
    cout << "a = " << a << endl;


    // Should report that 1 is true
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    }

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    }

    cout << "Comparisons\n";
    Rational twoFifths(2, 5);
    Rational threeHalves(3, 2);
    Rational minusFive(-5);
    cout << twoFifths << " < " << threeHalves << " : "
         << (twoFifths < threeHalves) << endl;
    cout << twoFifths << " <= " << 1 << " : " << (twoFifths <= 1) << endl;
    cout << threeHalves << " < " << twoFifths << " : "
         << (threeHalves < twoFifths) << endl;
    cout << threeHalves << " > " << threeHalves << " : "
         << (threeHalves > threeHalves) << endl;
    cout << threeHalves << " >= " << threeHalves << " : "
         << (threeHalves >= threeHalves) << endl;
    cout << minusFive << " >= " << threeHalves << " : "
         << (minusFive >= threeHalves) << endl;
}



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

