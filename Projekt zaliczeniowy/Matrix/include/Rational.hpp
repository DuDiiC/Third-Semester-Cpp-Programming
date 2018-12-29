#ifndef HEADERS_HPP
#define HEADERS_HPP
#include "headers.hpp"
#endif // HEADERS_HPP

#ifndef RATIONAL_HPP
#define RATIONAL_HPP


class Rational
{
public:
    // constructor
	Rational();
	Rational(long long numerator, long long denominator = 1);
	Rational(const Rational &r);

	// getters
	inline long long getNumerator();
	inline long long getDenominator();

	// setters
	inline void setNumerator(long long n);
	inline void setDenominator(long long d);

	// overloading arithmetic operators
	Rational operator+(Rational &r);
	Rational operator-(Rational &r);
	Rational operator*(Rational &r);
	Rational operator/(Rational &r);

    // exponentation
	Rational exp(long long exponent);

	// overloading relational operators
	friend bool operator==(const Rational &r1, const Rational &r2);
	friend bool operator<(const Rational &r1, const Rational &r2);
	friend bool operator>(const Rational &r1, const Rational &r2);
	friend bool operator<=(const Rational &r1, const Rational &r2);
	friend bool operator>=(const Rational &r1, const Rational &r2);

	// overliading operators << and >>
	friend ostream& operator<<(ostream &output, const Rational &r);
	friend istream& operator>>(istream &input, Rational &r);

	void saveAsIrreducible();

private:
	long long numerator;
	long long denominator;

	static long long gcd(long long x, long long y); // NWD
	static long long lcm(long long x, long long y); // NWW

};

#endif // RATIONAL_HPP
