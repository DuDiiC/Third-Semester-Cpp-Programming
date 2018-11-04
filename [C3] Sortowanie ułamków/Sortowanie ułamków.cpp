#include <algorithm>
#include "Rational.cpp" //in other place


int main() {

    Rational frac;
    vector<Rational> fracs;
    while(cin >> frac) {
        fracs.push_back(frac);
    }

    sort(fracs.begin(), fracs.end());

    for(int i = 0; i < fracs.size(); i++) {
        cout << fracs[i] << " ";
    }
    cout << endl;

    return 0;
}
