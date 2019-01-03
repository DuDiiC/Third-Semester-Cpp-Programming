#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#ifndef HEADERS_HPP
#define HEADERS_HPP
#include "headers.hpp"
#endif // HEADERS_HPP

#include "Rational.hpp"

class Complex {

public:
    // constructors
    Complex();
    Complex(Rational, Rational = 0);
    Complex(const Complex&);

    // getters / czemu nie dziala inline ???
    Rational getRealPart() const ;
    Rational getImaginaryPart() const;

    // setters
    void setRealPart(Rational);
    void setImaginaryPart(Rational);

    // overloading arithmetic operators
    Complex operator+(const Complex&) const;
    Complex& operator+=(const Complex&);
    Complex operator-(const Complex&) const;
    Complex& operator-=(const Complex&);
    Complex operator*(const Complex&) const;
    Complex& operator*=(const Complex&);
    Complex operator/(const Complex&) const;
    Complex& operator/=(const Complex&);

    Complex conjugate(); // sprzezenie
    double module();

    // overloading equals operator
    friend bool operator==(const Complex&, const Complex&);

    // overloading operators << and >>
    friend ostream& operator<<(ostream &output, const Complex &c);
    friend istream& operator>>(istream &input, Complex &c);

private:
    Rational realPart;
    Rational imaginaryPart;
};

#endif // COMPLEX_HPP
