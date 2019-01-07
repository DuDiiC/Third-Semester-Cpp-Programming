#include <iostream>
using namespace std;

int main() {

    int poprawna;
    int ilePoprawnych;
    int temp;

    while(cin >> poprawna) {

        ilePoprawnych = 0;

        for(int i = 0; i < 5; i++) {
            cin >> temp;
            if(temp == poprawna) {
                ilePoprawnych++;
            }
        }

        cout << ilePoprawnych << cout;

    }

    return 0;
}
