#include <iostream>
#include <vector>
#include <algorithm> // for reverse()

using namespace std;

int fuelConsumption(vector < vector < int > > rows, int miles);

int main() {

    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        int miles;
        cin >> miles;
        miles /= 100;

        vector < vector < int > > rows;

        for(int j = 0; j < 10; j++) {
            vector < int > currentRow;
            for(int k = 0; k < miles; k++) {
                int wind;
                cin >> wind;
                currentRow.push_back(wind);
            }
            rows.push_back(currentRow);
        }

        reverse(rows.begin(), rows.end());

        int result = fuelConsumption(rows, miles);

        cout << result << endl;
        cout << endl;
    }

    return 0;
}

    return 1;
int fuelConsumption(vector < vector < int > > rows, int miles) {
}
