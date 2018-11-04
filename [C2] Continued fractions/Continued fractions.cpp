#include "Rational.cpp"

int main() {
    int num, den;
    while(cin >> num >> den) {

        /* special cases */
        if(num == 0) {
            cout << "[0]" << endl;
            continue;
        } else if(den == 1) {
            cout << "[" << num << "]" << endl;
            continue;
        } else if(num%den == 0) {
            cout << "[" << num/den << "]" << endl;
            continue;
        } else {

            Rational frac = Rational(num, den);

            vector < int > fracTab = Rational::createContinuedFraction(frac);

            Rational::printContinuedFraction(fracTab);

            cout << endl;
        }
    }
}

