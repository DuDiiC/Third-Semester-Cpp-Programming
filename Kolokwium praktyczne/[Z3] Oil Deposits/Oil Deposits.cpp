#include <iostream>
#include <vector>
using namespace std;

bool checkField(int x, int y, vector < vector < char > > &tab) {

    if(tab[x][y] == '*') return false;

    else {

        tab[x][y] = '*';

        /// rekurencyjnie wszystkie pola obok, jesli sa w zakresie

        if(x-1 >= 0 && y-1 >= 0) checkField(x-1, y-1, tab);

        if(x-1 >= 0) checkField(x-1, y, tab);

        if(x-1 >= 0 && y+1 < tab[x].size()) checkField(x-1, y+1, tab);

        if(y+1 < tab[x].size()) checkField(x, y+1, tab);

        if (x+1 < tab.size() && y+1 < tab[x].size()) checkField(x+1, y+1, tab);

        if(x+1 < tab.size()) checkField(x+1, y, tab);

        if(x+1 < tab.size() && y-1 >= 0) checkField(x+1, y-1, tab);

        if(y-1 >= 0) checkField(x, y-1, tab);

        return true;
    }
}

int main() {

    int rows, columns;
    while(cin >> rows >> columns && (rows || columns)) {

        vector < vector < char > > field;
        for(int i = 0; i < rows; i++) {
            vector < char > temp;
            field.push_back(temp);
        }

        for(int i = 0; i < field.size(); i++) {
            for(int j = 0; j < columns; j++) {
                char temp;
                cin >> temp;
                field[i].push_back(temp);
            }
        }

        int aggregationNumber = 0;
        for(int i = 0; i < field.size(); i++) {
            for(int j = 0; j < field[i].size(); j++) {
                if(checkField(i, j, field)) {
                    aggregationNumber++;
                }
            }
        }

        cout << aggregationNumber << endl;
    }

    return 0;
}
