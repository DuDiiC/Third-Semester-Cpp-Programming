#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {

    int cases;
    cin >> cases;
    while(cases--) {

        int result = 0;
        int snowflakesNumber;
        cin >> snowflakesNumber;

        vector < int > snowflakes;
        for(int i = 0; i < snowflakesNumber; i++) {
            int temp;
            cin >> temp;
            snowflakes.push_back(temp);
        }

        int startIndex = 0, endIntex = 0;
        set < int > uniqueSnowflakes;

        while(endIntex < snowflakesNumber) {
            /// dopoki sie nie powtarza wrzucaj kolejne
            while(endIntex < snowflakesNumber &&
                  !uniqueSnowflakes.count(snowflakes[endIntex])) {
                uniqueSnowflakes.insert(snowflakes[endIntex]);
                endIntex++;
            }

            /// teraz sprawdz czy nie jest dluzszy niz wczesniej
            if(endIntex - startIndex > result) {
                result = endIntex - startIndex;
            }

            /// usunac ze zbioru unikalnych pierwszy nieunikalny
            uniqueSnowflakes.erase(snowflakes[startIndex]);
            startIndex++;

        }

        cout << result << endl;

    }

    return 0;
}
