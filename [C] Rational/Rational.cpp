#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;


class Rational {

public:
    // constructor
	Rational();
	Rational(int numerator, int denominator = 1);
	Rational(const Rational &r);

	// getters
	inline int getNumerator();
	inline int getDenominator();

	// setters
	inline void setNumerator(int n);
	inline void setDenominator(int d);

	// overloading arithmetic operators
	Rational operator+(Rational &r);
	Rational operator-(Rational &r);
	Rational operator*(Rational &r);
	Rational operator/(Rational &r);

    // exponentation
	Rational exp(int exponent);

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
	static vector < int > createContinuedFraction(Rational r);
	static void printContinuedFraction(vector < int > fracTab);

private:
	int numerator;
	int denominator;

	static int gcd(int x, int y); // NWD
	static int lcm(int x, int y); // NWW
	void saveAsIrreducible();
};


Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    this->saveAsIrreducible();
}

Rational::Rational(const Rational &r) {
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	this->saveAsIrreducible();
}

inline int Rational::getNumerator() {
    return this->numerator;
}

inline int Rational::getDenominator() {
    return this->denominator;
}

inline void Rational::setNumerator(int n) {
    this->numerator = n;
}

inline void Rational::setDenominator(int d) {
    this->denominator = d;
}

Rational Rational::operator+(Rational &r) {
    int x, y, z;
    x = gcd(this->denominator, r.denominator);
    y = (this->numerator*(r.denominator/x)) + (r.numerator*(this->denominator/x));
    z = gcd(x, y);

    Rational r2 = Rational(y/z, (this->denominator/x)*(r.denominator/z));
    r2.saveAsIrreducible();
    return r2;
}

Rational Rational::operator-(Rational &r) {
    int x, y, z;
    x = gcd(this->denominator, r.denominator);
    y = (this->numerator*(r.denominator/x)) - (r.numerator*(this->denominator/x));
    z = gcd(x, y);

    Rational r2 = Rational(y/z, (this->denominator/x)*(r.denominator/z));
    r2.saveAsIrreducible();
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

Rational Rational::exp(int exponent) {
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
    double x, y;
    x = (double)(r1.numerator)/(double)(r1.denominator);
    y = (double)(r2.numerator)/(double)(r2.denominator);
    return (x < y);
}
bool operator>(const Rational &r1, const Rational &r2) {
    double x, y;
    x = (double)(r1.numerator)/(double)(r1.denominator);
    y = (double)(r2.numerator)/(double)(r2.denominator);
    return (x > y);
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

	if(r.denominator!=1)
		output << "|" << r.denominator;

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

vector < int > Rational::createContinuedFraction(Rational r) {
    vector <int> fracTab;
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

void Rational::printContinuedFraction(vector < int > fracTab) {
    cout << "[" << fracTab[0] << ";";
    for(int i = 1; i < fracTab.size(); i++) {
        cout << fracTab[i];
        if(i != fracTab.size()-1) cout << ",";
    }
    cout << "]";
}


int Rational::gcd(int x, int y) {
	while(y!=0) {
		int r = x%y;
		x = y;
		y = r;
	}

	return x;
}

void Rational::saveAsIrreducible() {
    int greatestCommonDivisor = gcd(numerator, denominator);
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
    int exponent;
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
    vector<int> continuedFraction = Rational::createContinuedFraction(frac1);
    cout << "Ulamek lancuchowy utworzony z " << frac1 << " to: ";
    Rational::printContinuedFraction(continuedFraction);
    cout << endl;


	return 0;
}
