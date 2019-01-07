#include <iostream>
using namespace std;

char klawiszeTab[10][5] = {" ", ".,?\"", "abc", "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main() {

    int liczbaTestow;
    cin >> liczbaTestow;

    while(liczbaTestow--) {
        int liczbaZnakow;
        cin >> liczbaZnakow;

        int numerKlawisza[liczbaZnakow];
        for(int i = 0; i < liczbaZnakow; i++) {
            cin >> numerKlawisza[i];
        }

        int literaNaKlawiszu[liczbaZnakow];
        for(int i = 0; i < liczbaZnakow; i++) {
            cin >> literaNaKlawiszu[i];
        }

        for(int i = 0; i < liczbaZnakow; i++) {
            cout << klawiszeTab[numerKlawisza[i]][literaNaKlawiszu[i]-1];
        }
        cout << endl;
    }

    return 0;
}
