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

    friend ostream & operator<< (ostream &output, const Z<p> &s){
        output << s.x;
        return output;
    }
    }
};

int main(){
    Z<5> a(3);
    a = Z<5>(-3);
    cout << a;

    return 0;
}
