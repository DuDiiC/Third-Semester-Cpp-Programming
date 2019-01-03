#include "Complex.hpp"
#include "Rational.hpp"

Complex::Complex() {
    this->realPart = 0;
    this->imaginaryPart = 0;
}

Complex::Complex(Rational r1, Rational r2) {
    this->realPart = r1;
    this->imaginaryPart = r2;
}

Complex::Complex(const Complex &c) {
    this->realPart = c.realPart;
    this->imaginaryPart = c.imaginaryPart;
}

Rational Complex::getRealPart() const {
    return this->realPart;
}

Rational Complex::getImaginaryPart() const {
    return this->imaginaryPart;
}

void Complex::setRealPart(Rational re) {
    this->realPart = re;
}

void Complex::setImaginaryPart(Rational im) {
    this->imaginaryPart = im;
}

Complex Complex::operator+(const Complex &c) const {

    Rational re, im;

    re = this->realPart + c.realPart;
    im = this->imaginaryPart + c.imaginaryPart;

    Complex c2(re, im);
    return c2;
}

Complex& Complex::operator+=(const Complex &c) {
    *this = (*this)+c;
    return *this;
}


Complex Complex::operator-(const Complex &c) const {

    Rational re, im;

    re = this->realPart - c.realPart;
    im = this->imaginaryPart - c.imaginaryPart;

    Complex c2(re, im);
    return c2;
}

Complex& Complex::operator-=(const Complex &c) {
    *this = (*this)-c;
    return *this;
}

Complex Complex::operator*(const Complex &c) const {

    Rational re, im;
    Rational re1, re2, im1, im2;

    re1 = this->realPart*c.realPart;
    re2 = this->imaginaryPart*c.imaginaryPart;
    re = re1-re2;

    im1 = this->realPart*c.imaginaryPart;
    im2 = this->imaginaryPart*c.realPart;
    im = im1+im2;

    Complex c2(re, im);
    return c2;
}

Complex& Complex::operator*=(const Complex &c) {
    *this = (*this)*c;
    return *this;
}

Complex Complex::operator/(const Complex &c) const {

    Rational re, im;
    Rational re1, re2, reUp, re3, re4, reDown,
             im1, im2, imUp, im3, im4, imDown;

    re1 = this->realPart*c.realPart;
    re2 = this->imaginaryPart*c.imaginaryPart;
    re3 = c.realPart*c.realPart;
    re4 = c.imaginaryPart*c.imaginaryPart;
    reUp = re1+re2;
    reDown = re3+re4;
    re = reUp/reDown;

    im1 = this->imaginaryPart*c.realPart;
    im2 = this->realPart*c.imaginaryPart;
    im3 = c.realPart*c.realPart;
    im4 = c.imaginaryPart*c.imaginaryPart;
    imUp = im1-im2;
    imDown = im3+im4;
    im = imUp/imDown;

    Complex c2(re, im);
    return c2;
}

Complex& Complex::operator/=(const Complex &c) {
    *this = (*this)/c;
    return *this;
}

Complex Complex::conjugate() {

    Rational im(this->imaginaryPart), minusOne(-1);
    Complex c(this->realPart, im*minusOne);
    return c;
}

double Complex::module() {

    Rational mod1 = this->realPart*this->realPart,
             mod2 = this->imaginaryPart*this->imaginaryPart;

    Rational mod3 = mod1+mod2;

    double  numerator = sqrt(mod3.getNumerator()),
            denominator = sqrt(mod3.getDenominator()),
            mod = numerator/denominator;

    return mod;
}

bool operator==(const Complex &c1, const Complex &c2) {
    return ((c1.realPart == c2.realPart) && (c1.imaginaryPart == c2.imaginaryPart));
}

ostream& operator<<(ostream &output, const Complex &c) {

    Rational digitOne(1), minusOneDigit(-1);

    if(c.realPart == 0 && c.imaginaryPart == 0){
        output << "0";
    } else {
        if(!(c.realPart == 0) && c.imaginaryPart == 0) {
            output << c.realPart;
        } else if(c.realPart == 0 && !(c.imaginaryPart == 0)) {
            if(c.imaginaryPart == digitOne) {
                output << "i";
            } else if(c.imaginaryPart == minusOneDigit) {
                output << "-i";
            } else {
                output << c.imaginaryPart << "i";
            }
        } else {
            if(c.imaginaryPart > 0) {
                if(c.imaginaryPart == digitOne) {
                    output << c.realPart << "+i";
                } else {
                    output << c.realPart << "+" << c.imaginaryPart << "i";
                }
            } else {
                if(c.imaginaryPart == minusOneDigit) {
                    output << c.realPart << "-i";
                } else {
                    output << c.realPart << c.imaginaryPart << "i";
                }
            }
        }
    }

    return output;
}

istream& operator>>(istream &input, Complex &c) {

    string complexNumber;
    input >> complexNumber;

    int iPosition = complexNumber.find('i');

    if(iPosition != string::npos) {

        int plusPosition = complexNumber.find('+'),
            firstMinusPosition = complexNumber.find('-'),
            secondMinusPosition = complexNumber.find('-', firstMinusPosition+1);

        if(plusPosition != string::npos) { // format x+yi or -x+yi

            string  reS = complexNumber.substr(0, plusPosition),
                    imS = complexNumber.substr(plusPosition+1, complexNumber.size()-1);
            Rational re(reS), im(imS);
            c.realPart = re;
            c.imaginaryPart = im;

        } else if(firstMinusPosition != string::npos) { // format -x-yi or x-yi or -yi

            if(secondMinusPosition != string::npos) { // format -x-yi

                string  reS = complexNumber.substr(0, secondMinusPosition),
                        imS = complexNumber.substr(secondMinusPosition, complexNumber.size()-1);
                Rational re(reS), im(imS);
                c.realPart = re;
                c.imaginaryPart = im;

            } else { // format x-yi or -yi

                if(firstMinusPosition == 0) { // format only -yi

                    string imS = complexNumber.substr(0, complexNumber.size()-1);
                    Rational im(imS);
                    c.imaginaryPart = im;

                } else { // format x-yi

                    string  reS = complexNumber.substr(0, firstMinusPosition),
                            imS = complexNumber.substr(firstMinusPosition, complexNumber.size()-1);
                    Rational re(reS), im(imS);
                    c.realPart = re;
                    c.imaginaryPart = im;
                }
            }
        } else { // format bi

            string imS = complexNumber.substr(0, complexNumber.size()-1);
            Rational im(imS);
            c.imaginaryPart = im;
        }

    } else { // format only x or -x

        Rational re(complexNumber);
        c.realPart = re;
    }

    return input;
}
