#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;


class Rational {

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

	// continued fraction
	static vector < long long > createContinuedFraction(Rational r);
	static void printContinuedFraction(vector < long long > fracTab);

	void saveAsIrreducible();

private:
	long long numerator;
	long long denominator;

	static long long gcd(long long x, long long y); // NWD
	static long long lcm(long long x, long long y); // NWW

};


Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

Rational::Rational(long long numerator, long long denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    if(numerator != 0 && denominator != 0)
        this->saveAsIrreducible();
    else if (numerator == 0 && denominator == 0)
        this->denominator = 0;
}

Rational::Rational(const Rational &r) {
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	this->saveAsIrreducible();
}

inline long long Rational::getNumerator() {
    return this->numerator;
}

inline long long Rational::getDenominator() {
    return this->denominator;
}

inline void Rational::setNumerator(long long n) {
    this->numerator = n;
}

inline void Rational::setDenominator(long long d) {
    this->denominator = d;
}

Rational Rational::operator+(Rational &r) {
    long long x, y, z;
    x = gcd(this->denominator, r.denominator);
    y = (this->numerator*(r.denominator/x)) + (r.numerator*(this->denominator/x));
    z = gcd(x, y);

    Rational r2 = Rational(y/z, (this->denominator/x)*(r.denominator/z));
    return r2;
}

Rational Rational::operator-(Rational &r) {
    long long x, y, z;
    x = gcd(this->denominator, r.denominator);
    y = (this->numerator*(r.denominator/x)) - (r.numerator*(this->denominator/x));
    z = gcd(x, y);

    Rational r2 = Rational(y/z, (this->denominator/x)*(r.denominator/z));
    return r2;
}

Rational Rational::operator*(Rational &r) {
    Rational r2 = Rational((this->numerator*r.numerator), (this->denominator*r.denominator));
    return r2;
}

Rational Rational::operator/(Rational &r) {
    Rational r2 = Rational((this->numerator*r.denominator), (this->denominator*r.numerator));
    return r2;
}

Rational Rational::exp(long long exponent) {
    Rational r = Rational(this->numerator, this->denominator);
    for(int i = 1; i < exponent; i++) {
        r.numerator *= this->numerator;
        r.denominator *= this->denominator;
    }
    r.saveAsIrreducible();
    return r;
}

bool operator==(const Rational &r1, const Rational &r2) {
    return ((r1.numerator == r2.numerator) && (r1.denominator == r2.denominator));
}

bool operator<(const Rational &r1, const Rational &r2) {

    Rational r1c(r1), r2c(r2);
    long long LCM = Rational::lcm(r1.denominator, r2.denominator);
    r1c.numerator *= (LCM/r1.denominator);
    r1c.denominator *= (LCM/r1.denominator);
    r2c.numerator *= (LCM/r2.denominator);
    r2c.denominator *= (LCM/r2.denominator);
    return (r1c.numerator < r2c.numerator);
}
bool operator>(const Rational &r1, const Rational &r2) {

    Rational r1c(r1), r2c(r2);
    long long LCM = Rational::lcm(r1.denominator, r2.denominator);
    r1c.numerator *= (LCM/r1.denominator);
    r1c.denominator *= (LCM/r1.denominator);
    r2c.numerator *= (LCM/r2.denominator);
    r2c.denominator *= (LCM/r2.denominator);
    return (r1c.numerator > r2c.numerator);
}

bool operator<=(const Rational &r1, const Rational &r2) {
    if((r1 < r2) || (r1 == r2)) return true;
    else return false;
}

bool operator>=(const Rational &r1, const Rational &r2) {
    if((r1 > r2) || (r1 == r2)) return true;
    else return false;
}

ostream& operator<<(ostream &output, const Rational &r) {
	output << r.numerator;

	if((r.denominator!=1) && (r.numerator != 0)) {
		output << "|" << r.denominator;
	}

	return output;
}

istream& operator>>(istream &input, Rational &r) {

    string fraction;
    cin >> fraction;

    int linePosition = fraction.find('|');

    if(linePosition != string::npos) { /* numerator|denominator */
        string num, den;
        num = fraction.substr(0, linePosition);
        den = fraction.substr(linePosition+1, den.size()-1);
        r.numerator = strtol(num.c_str(), NULL, 10);
        r.denominator = strtol(den.c_str(), NULL, 10);
    } else { /* only numerator */
        r.numerator = strtol(fraction.c_str(), NULL, 10);
        r.denominator = 1;
    }

    r.saveAsIrreducible();

    return input;
}

vector < long long > Rational::createContinuedFraction(Rational r) {
    vector <long long> fracTab;
    Rational frac = Rational(r);
    if(frac.numerator >= frac.denominator) {
        fracTab.push_back(frac.numerator/frac.denominator);
    } else {
        fracTab.push_back(0);
    }

    do {
        frac.numerator %= frac.denominator;
        swap(frac.numerator, frac.denominator);
        fracTab.push_back(frac.numerator/frac.denominator);

        if(frac.numerator%frac.denominator == 0) break;
    } while(frac.denominator != 1);

    return fracTab;
}

void Rational::printContinuedFraction(vector < long long > fracTab) {
    cout << "[" << fracTab[0] << ";";
    for(int i = 1; i < fracTab.size(); i++) {
        cout << fracTab[i];
        if(i != fracTab.size()-1) cout << ",";
    }
    cout << "]";
}


long long Rational::gcd(long long x, long long y) {
	while(y!=0) {
		long long r = x%y;
		x = y;
		y = r;
	}

	return x;
}

long long Rational::lcm(long long x, long long y) {
    return (x*y)/gcd(x, y);
}

void Rational::saveAsIrreducible() {
    long long greatestCommonDivisor = gcd(numerator, denominator);
    numerator = numerator/greatestCommonDivisor;
    denominator = denominator/greatestCommonDivisor;
    if(numerator > 0 && denominator < 0) { /* for example for 3|-2, after arithmetic operations */
        numerator = -numerator;
        denominator = -denominator;
    }
}

int main(void) {

    Rational frac1, frac2;
    cout << "Wczytaj dwa ulamki: ";

    // wczytywanie i wypisywanie
    cin >> frac1 >> frac2;
    cout << "Wczytane ulamki to " << frac1 << " oraz " << frac2 << endl;

    // dzialania arytmetyczne
    cout << "Ich suma: " << frac1 << " + " << frac2 << " = " << frac1+frac2 << endl;
    cout << "Ich roznica: " << frac1 << " - " << frac2 << " = " << frac1-frac2 << endl;
    cout << "Ich iloczyn: " << frac1 << " * " << frac2 << " = " << frac1*frac2 << endl;
    cout << "Ich iloraz: " << frac1 << " / " << frac2 << " = " << frac1/frac2 << endl;

    // potegowanie
    long long exponent;
    cout << "Podaj wykladnik potegi do policzenia dla " << frac1 << ": ";
    cin >> exponent;
    cout << "(" << frac1 << ")^" << exponent << " = " << frac1.exp(exponent) << endl;

    // operatory relacji
    cout << "Czy " << frac1 << " jest rowny " << frac2 << "?: " << (frac1==frac2 ? "tak" : "nie") << endl;
    cout << "Czy " << frac1 << " jest wiekszy od " << frac2 << "?: " << (frac1>frac2 ? "tak" : "nie") << endl;
    cout << "Czy " << frac1 << " jest mniejszy od " << frac2 << "?: " << (frac1<frac2 ? "tak" : "nie") << endl;
    cout << "Czy " << frac1 << " jest wiekszy lub rowny od " << frac2 << "?: " << (frac1>=frac2 ? "tak" : "nie") << endl;
    cout << "Czy " << frac1 << " jest mniejszy lub rowny od " << frac2 << "?: " << (frac1<=frac2 ? "tak" : "nie") << endl;

    // ulamki lancuchowe
    vector<long long> continuedFraction = Rational::createContinuedFraction(frac1);
    cout << "Ulamek lancuchowy utworzony z " << frac1 << " to: ";
    Rational::printContinuedFraction(continuedFraction);
    cout << endl;


	return 0;
}
