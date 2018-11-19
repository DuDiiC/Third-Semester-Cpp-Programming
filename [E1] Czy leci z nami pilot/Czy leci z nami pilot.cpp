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

int fuelConsumption(vector < vector < int > > rows, int miles) {
    vector < vector < int > > rowsSum(rows.size(), vector < int > (miles, 1000));
    rowsSum[0][0] = 30 - rows[0][0];

    for(int i = 1; i < miles; i++) {
        for(int j = 0; j < rows.size(); j++) {
            int up, constant, down;

            if(j + 1 < rows.size()) up = rowsSum[j+1][i-1] - rows[j+1][i] + 20;
            else up = 1000;

            constant = rowsSum[j][i-1] - rows[j][i] + 30;

            if(j-1 >= 0) down = rowsSum[j-1][i-1] - rows[j-1][i] + 60;
            else down = 1000;

            rowsSum[j][i] = min(up, min(constant, down));
        }
    }
    return rowsSum[0][miles-1];
}
