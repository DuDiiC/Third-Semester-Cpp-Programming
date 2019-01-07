#ifndef HEADERS_HPP
#define HEADERS_HPP
#include "headers.hpp"
#endif // HEADERS_HPP

#ifndef RATIONAL_HPP
#define RATIONAL_HPP


class Rational {

public:
    // constructor
    Rational();
    Rational(long long, long long = 1);
    Rational(string);
    Rational(const Rational&);

    // getters
    long long getNumerator() const;
    long long getDenominator() const;

    // setters
    void setNumerator(long long);
    void setDenominator(long long);

    // overloading arithmetic operators
    Rational operator+(const Rational&) const;
    Rational& operator+=(const Rational&);
    Rational operator-(const Rational&) const;
    Rational& operator-=(const Rational&);
    Rational operator*(const Rational&) const;
    Rational& operator*=(const Rational&);
    Rational operator/(const Rational&) const;
    Rational& operator/=(const Rational&);

    // exponentation
    Rational exp(long long);

    // overloading relational operators
    friend bool operator==(const Rational &r1, const Rational &r2);
    friend bool operator!=(const Rational &r1, const Rational &r2);
    friend bool operator<(const Rational &r1, const Rational &r2);
    friend bool operator>(const Rational &r1, const Rational &r2);
    friend bool operator<=(const Rational &r1, const Rational &r2);
    friend bool operator>=(const Rational &r1, const Rational &r2);

    // overliading operators << and >>
    friend ostream& operator<<(ostream &output, const Rational &r);
    friend istream& operator>>(istream &input, Rational &r);

    // continued fraction
    //static vector < long long > createContinuedFraction(Rational r);
    //static void printContinuedFraction(vector < long long > fracTab);

    void saveAsIrreducible();

private:
    long long numerator;
    long long denominator;

    static long long gcd(long long, long long); // NWD
    static long long lcm(long long, long long); // NWW
};

#endif // RATIONAL_HPP
