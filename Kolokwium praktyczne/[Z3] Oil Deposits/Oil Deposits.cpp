#include <iostream>
#include <vector>
using namespace std;

bool sprawdzPole(int x, int y, vector < vector < char > > &tab) {

    if(tab[x][y] == '*') return false;

    else {

        tab[x][y] = '*';

        /// rekurencyjnie wszystkie pola obok, jesli sa w zakresie

        if(x-1 >= 0 && y-1 >= 0) sprawdzPole(x-1, y-1, tab);

        if(x-1 >= 0) sprawdzPole(x-1, y, tab);

        if(x-1 >= 0 && y+1 < tab[x].size()) sprawdzPole(x-1, y+1, tab);

        if(y+1 < tab[x].size()) sprawdzPole(x, y+1, tab);

        if (x+1 < tab.size() && y+1 < tab[x].size()) sprawdzPole(x+1, y+1, tab);

        if(x+1 < tab.size()) sprawdzPole(x+1, y, tab);

        if(x+1 < tab.size() && y-1 >= 0) sprawdzPole(x+1, y-1, tab);

        if(y-1 >= 0) sprawdzPole(x, y-1, tab);

        return true;
    }
}

int main() {

    int wiersze, kolumny;
    while(cin >> wiersze >> kolumny && (wiersze || kolumny)) {

        vector < vector < char > > pole;
        for(int i = 0; i < wiersze; i++) {
            vector < char > temp;
            pole.push_back(temp);
        }

        for(int i = 0; i < pole.size(); i++) {
            for(int j = 0; j < kolumny; j++) {
                char temp;
                cin >> temp;
                pole[i].push_back(temp);
            }
        }

        int iloscSkupisk = 0;
        for(int i = 0; i < pole.size(); i++) {
            for(int j = 0; j < pole[i].size(); j++) {
                if(sprawdzPole(i, j, pole)) {
                    iloscSkupisk++;
                }
            }
        }

        cout << iloscSkupisk << endl;
    }

    return 0;
}
