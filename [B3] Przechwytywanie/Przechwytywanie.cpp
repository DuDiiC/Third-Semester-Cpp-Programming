#include <iostream>
#include <vector>

using namespace std;

int main() {

    int cases = 1, dynamicTab[100000], value, maxHits;

    while (cin >> value) {

        if (value == -1) { return 0; }

        maxHits = 0;
        vector<int> values;

        values.push_back(value);
        while (cin >> value && value != -1) {
            values.push_back(value);
        }

        for (int i = values.size() - 1; i >= 0; i--) {
            dynamicTab[i] = 1;
            for (int j = values.size() - 1; j > i; j--) {
                if (values[j] <= values[i] && dynamicTab[i] <= dynamicTab[j]+1) {
                    dynamicTab[i] = dynamicTab[j]+1;
                }
            }
            if (dynamicTab[i] > maxHits) maxHits = dynamicTab[i];
        }

        if (cases != 1) { cout << endl; }

        cout << "Test #" << cases << ":" << endl;
        cout << "  maximum possible interceptions: " << maxHits << endl;

        cases++;
    }
}

/* TIP: Longest Increasing Subsequence */
