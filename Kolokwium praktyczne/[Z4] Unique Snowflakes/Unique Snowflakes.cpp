#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {

    int iloscTestow;
    cin >> iloscTestow;
    while(iloscTestow--) {

        int maxPudelka = 0;
        int iloscPlatkow;
        cin >> iloscPlatkow;

        vector < int > platki;
        for(int i = 0; i < iloscPlatkow; i++) {
            int temp;
            cin >> temp;
            platki.push_back(temp);
        }

        int indexP = 0, indexK = 0;
        set < int > ciagUnikalnych;

        while(indexK < iloscPlatkow) {
            /// dopoki sie nie powtarza wrzucaj kolejne
            while(indexK < iloscPlatkow &&
                  !ciagUnikalnych.count(platki[indexK])) {
                ciagUnikalnych.insert(platki[indexK]);
                indexK++;
            }

            /// teraz sprawdz czy nie jest dluzszy niz wczesniej
            if(indexK - indexP > maxPudelka) {
                maxPudelka = indexK - indexP;
            }

            /// usunac ze zbioru unikalnych pierwszy nieunikalny
            ciagUnikalnych.erase(platki[indexP]);
            indexP++;

        }

        cout << maxPudelka << endl;

    }

    return 0;
}
