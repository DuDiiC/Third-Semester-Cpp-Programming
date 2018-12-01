#include <iostream>
using namespace std;

template <typename X, typename Y> void swap1(X &x, Y &y) {
    X temp = x;
    x = y;
    y = temp;
}

template <typename X, typename Y> void swap2(X &x, Y &y) {
    x -= y;
    y += x;
    x = y - x;
}

int main() {

    int a = 4;
    float b = 5;

    cout << a << " " << b << endl;
    swap1(a, b);
    cout << a << " " << b << endl;
    swap2(a, b);
    cout << a << " " << b << endl;
}
