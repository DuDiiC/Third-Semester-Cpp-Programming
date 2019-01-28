#include <iostream>
using namespace std;

int main() {

    int correct;
    int correctsNumber;
    int temp;

    while(cin >> correct) {

        correctsNumber = 0;

        for(int i = 0; i < 5; i++) {
            cin >> temp;
            if(temp == correct) {
                correctsNumber++;
            }
        }

        cout << correctsNumber << cout;

    }

    return 0;
}
