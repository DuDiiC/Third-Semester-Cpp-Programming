#include <iostream>
using namespace std;

char keys[10][5] = {" ", ".,?\"", "abc", "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main() {

    int cases;
    cin >> cases;

    while(cases--) {
        int charNumber;
        cin >> charNumber;

        int keyNumber[charNumber];
        for(int i = 0; i < charNumber; i++) {
            cin >> keyNumber[i];
        }

        int letterOnKey[charNumber];
        for(int i = 0; i < charNumber; i++) {
            cin >> letterOnKey[i];
        }

        for(int i = 0; i < charNumber; i++) {
            cout << keys[keyNumber[i]][letterOnKey[i]-1];
        }
        cout << endl;
    }

    return 0;
}
