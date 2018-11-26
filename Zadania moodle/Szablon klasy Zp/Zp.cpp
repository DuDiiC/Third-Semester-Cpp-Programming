#include<iostream>

using namespace std;

template <int p> class Z {
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
        a = elementOdwrotny();
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

    Z<p> elementOdwrotny() {
        int temp1 = 1, temp2 = x, temp3 = 0, temp4 = p, temp5;
        while (temp2) {
            if(temp2 < temp4) {
                swap(temp1, temp3);
                swap(temp2, temp4);
            }
            temp5 = temp2/temp4;
            temp1 -= temp5*temp3;
            temp2 -= temp5*temp4;
        }
        return Z<p>(temp3);
    }

    friend ostream & operator<< (ostream &output, const Z<p> &s) {
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

int main() {
    cout << "Obliczenia wykonywane dla Zp, gdzie p jest dla przykladu rowne 23" << endl;

    Z<23> a, b;
    cout << "Podaj pierwsza liczbe: ";
    cin >> a;
    cout << "Podaj druga liczbe: ";
    cin >> b;
    cout << a << " + " << b << " = " << a+b << endl;
    cout << a << " - " << b << " = " << a-b << endl;
    cout << a << " * " << b << " = " << a*b << endl;
    cout << a << " / " << b << " = " << a/b << endl;
    cout << "Element odwrotny do " << a << " w ciele Z23 to " << a.elementOdwrotny() << endl;
    cout << "Element odwrotny do " << b << " w ciele Z23 to " << b.elementOdwrotny() << endl;

    return 0;
}
