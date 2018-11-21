#include<iostream>

using namespace std;

template <int p> class Z{
    int x;
public:
    Z<p> () {}

    Z<p> (int y){
        x = (y%p < 0) ? y%p + p : y%p;
    }

    Z<p> operator+ (Z<p> a){
            return Z(a.x+x);
    }

    friend ostream & operator<< (ostream &wyjscie, const Z<p> &s){
        wyjscie << s.x;
        return wyjscie;
    }
};

int main(){
    Z<5> a(3);
    a = Z<5>(-3);
    cout << a;

    return 0;
}
