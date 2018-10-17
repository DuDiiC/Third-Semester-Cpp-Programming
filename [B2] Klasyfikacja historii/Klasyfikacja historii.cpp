#include <iostream>

using namespace std;

int main() {

    int length;
    cin >> length;
    int input[length], tabForCase[length];
    int chronologicalInput[length], chronologicalTabForCase[length];

    for(int i = 0; i < length; i++) {
        cin >> input[i];
    }

    for(int i = 0; i < length; i++) {
        chronologicalInput[input[i]-1] = i+1;
    }

    while(cin >> tabForCase[0]) {
        for(int i = 1; i < length; i++) {
            cin >> tabForCase[i];
        }

        for(int i = 0; i < length; i++) {
            chronologicalTabForCase[tabForCase[i]-1] = i+1;
        }

        int dynamicTab[length+1][length+1];
        for(int i = 0; i <= length; i++) {
            dynamicTab[i][0] = 0;
            dynamicTab[0][i] = 0;
        }

        for(int i = 1; i <= length; i++) {
            for(int j = 1; j <= length; j++) {
                if(chronologicalInput[i-1] == chronologicalTabForCase[j-1]) {
                    dynamicTab[i][j] = dynamicTab[i-1][j-1]+1;
                } else {
                    dynamicTab[i][j] = max(dynamicTab[i-1][j], dynamicTab[i][j-1]);
                }
            }
        }

        cout << dynamicTab[length][length] << endl;

    }

    return 0;
}

/* TIP: Longest Common Subsequence */
