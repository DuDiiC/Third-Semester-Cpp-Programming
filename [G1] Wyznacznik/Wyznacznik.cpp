#include <iostream>
#include <vector>

using namespace std;

int main() {

    int mSize;
    cin >> mSize;
    while(mSize) {
        SquareMatrix < int > m(mSize);
        for(int i = 0; i < mSize; i++) {
            vector < int > row;
            for(int j = 0; j < mSize; j++) {
                int temp;
                cin >> temp;
                row.push_back(temp);
            }
            m.matrix.push_back(row);

        }

        m.printMatrix();
        cout << endl;
        m.multiplyColXByY(1, 2);
        m2.printMatrix();
        cout << endl;

        cout << m.determinant() << endl;

        cin >> mSize;
    }

    cout << "*" << endl;

    return 0;
}
