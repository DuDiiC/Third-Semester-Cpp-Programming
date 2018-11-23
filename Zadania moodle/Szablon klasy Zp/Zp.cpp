#include<iostream>

using namespace std;

template <int p> class Z{
    int x;
public:
    Z<p> () {}

    Z<p> (int y) {
        x = (y%p < 0) ? y%p + p : y%p;
    }

    Z<p> operator+ (Z<p> a) {
        return Z(a.x+x);
    }

    Z<p> operator- (Z<p> a) {
        return Z(x-a.x);
    }

    Z<p> operator* (Z<p> a) {
        return Z(a.x*x);
    }

    Z<p> operator/ (Z<p> a) {
        a = odwrotny(a);
        return Z(x*a.x);
    }

    bool operator== (Z<p> a) {
        return x == a.x;
    }

    bool operator<= (Z<p> a) {
        return x <= a.x;
    }

    bool operator< (Z<p> a) {
        return x < a.x;
    }

    bool operator>= (Z<p> a) {
        return x >= a.x;
    }

    bool operator> (Z<p> a) {
        return x > a.x;
    }

    Z<p> elementOdwrotny(Z<p>) {

    }

    friend ostream & operator<< (ostream &output, const Z<p> &s){
        output << s.x;
        return output;
    }

    friend istream & operator>> (istream &input, Z<p> &s) {
        int y;
        input >> y;
        s = Z<p>(y);
        return input;
    }
};

int main(){
    Z<5> a(3);
    a = Z<5>(-3);
    cout << a;

    return 0;
}
