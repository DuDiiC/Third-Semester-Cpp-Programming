#ifndef HEADERS_HPP
#define HEADERS_HPP
#include "headers.hpp"
#endif // HEADERS_HPP

#ifndef ZP_H
#define ZP_H

template <unsigned int p>
class Z {

public:
    Z<p>();
    Z<p>(unsigned int);

    int getX() const;

    void setX(int);

    Z<p> operator+(const Z<p>&) const;
    Z<p>& operator+=(const Z<p>&);
    Z<p> operator-(const Z<p>&) const;
    Z<p>& operator-=(const Z<p>&);
    Z<p> operator*(const Z<p>&) const;
    Z<p>& operator*=(const Z<p>&);
    Z<p> operator/(const Z<p>&) const;
    Z<p>& operator/=(const Z<p>&);

    bool operator==(const Z<p>&) const;
    bool operator!=(const Z<p>&) const;
    bool operator<=(const Z<p>&) const;
    bool operator<(const Z<p>&) const;
    bool operator>=(const Z<p>&) const;
    bool operator>(const Z<p>&) const;

    Z<p> inverseElement();

    template <class Zp>
    friend ostream& operator<<(ostream &output, const Z<p>&);
    template <class Zp>
    friend istream& operator>>(istream &input, Z<p>&);

private:
    int x;
};

template <unsigned int p>
Z<p>::Z() {
    this->x = 0;
}

template <unsigned int p>
Z<p>::Z(unsigned int y) {
    this->x = (y%p < 0) ? y%p + p : y%p;
}

template <unsigned int p>
int Z<p>::getX() const {
    return this->x;
}

template <unsigned int p>
Z<p> Z<p>::operator+(const Z<p> &a) const {
    return Z(this->x+a.x);
}

template <unsigned int p>
Z<p>& Z<p>::operator+=(const Z<p> &a) {
    *this = (*this)+a;
    return *this;
}

template <unsigned int p>
Z<p> Z<p>::operator-(const Z<p> &a) const {
    return Z(this->x-a.x);
}

template <unsigned int p>
Z<p>& Z<p>::operator-=(const Z<p> &a) {
    *this = (*this)-a;
    return *this;
}

template <unsigned int p>
Z<p> Z<p>::operator*(const Z<p> &a) const {
    return Z(this->x*a.x);
}

template <unsigned int p>
Z<p>& Z<p>::operator*=(const Z<p> &a) {
    *this = (*this)*a;
    return *this;
}

template <unsigned int p>
Z<p> Z<p>::operator/(const Z<p> &a) const {
    a = a.inverseElement();
    return Z(this->x*a.x);
}

template <unsigned int p>
Z<p>& Z<p>::operator/=(const Z<p> &a) {
    *this = (*this)/a;
    return *this;
}

template <unsigned int p>
bool Z<p>::operator==(const Z<p> &a) const {
    return (this->x == a.x);
}

template <unsigned int p>
bool Z<p>::operator!=(const Z<p> &a) const {
    return !((*this)==a);
}

template <unsigned int p>
bool Z<p>::operator<=(const Z<p> &a) const {
    return (this->x <= a.x);
}

template <unsigned int p>
bool Z<p>::operator<(const Z<p> &a) const {
    return (this->x < a.x);
}

template <unsigned int p>
bool Z<p>::operator>=(const Z<p> &a) const {
    return (this->x >= a.x);
}

template <unsigned int p>
bool Z<p>::operator>(const Z<p> &a) const {
    return (this->x > a.x);
}

template <unsigned int p>
Z<p> Z<p>::inverseElement() { //extended Euclid's algorithm

    int temp[5] = {1, x, 0, p, 0};
        while (temp[1]) {
            if(temp[1] < temp[3]) {
                swap(temp[0], temp[2]);
                swap(temp[1], temp[3]);
            }
            temp[4] = temp[1]/temp[3];
            temp[0] -= temp[4]*temp[2];
            temp[1] -= temp[4]*temp[3];
        }
        return Z<p>(temp[2]);
}

template <unsigned int p>
ostream& operator<<(ostream &output, const Z<p> &s) {
    output << s.getX(); // WHY WITH GETTER? IT IS FRIEND METHOD
    return output;
}

template <unsigned int p>
istream& operator>>(istream &input, Z<p> &s) {
    int y;
    input >> y;
    s = Z<p>(y);
    return input;
}

#endif // ZP_H
