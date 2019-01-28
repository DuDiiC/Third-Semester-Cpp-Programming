#include <iostream>
#include <vector>
using namespace std;

int trueReligion(int x, vector < int > &v) {
    if(x != v[x]) {
        v[x] = trueReligion(v[x], v);
        return v[x];
    } else {
        return x;
    }
}

bool theSameReligion(int &x, int &y, vector < int > &v) {

    x = trueReligion(x, v);
    y = trueReligion(y, v);

    if(x != y) {
        v[x] = y;
        return false;
    } else return true;
}

int main() {

    int studentNumber, pairNumber;
    int testNumber = 1;
    while(cin >> studentNumber >> pairNumber && (studentNumber || pairNumber)) {

        int numberOfReligions = studentNumber;
        /// every student have a religion - studentNumber and religionNumber are the same (start from 1)
        vector < int > religions;
        for(int i = 0; i <= studentNumber; i++) {
            religions.push_back(i);
        }

        for(int i = 0; i < pairNumber; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;

            /// change, if religions are different
            if(!theSameReligion(temp1, temp2, religions)) {
                numberOfReligions--;
            }
        }

        cout << "Case " << testNumber++ << ": " << numberOfReligions << endl;
    }

    return 0;
}
