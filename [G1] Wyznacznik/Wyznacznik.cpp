#include <iostream>
#include <vector>

using namespace std;

int main() {

    int mSize;
    cin >> mSize;
    while(mSize) {
        SquareMatrix < long long > m(mSize);
        for(int i = 0; i < mSize; i++) {
            vector < long long > row;
            for(int j = 0; j < mSize; j++) {
                long long temp;
                cin >> temp;
                row.push_back(temp);
            }
            m.matrix.push_back(row);

        }

        cout << m.determinant() << endl;

        cin >> mSize;
    }

    cout << "*" << endl;

    return 0;
}
