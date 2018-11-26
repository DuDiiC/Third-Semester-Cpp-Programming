#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
    int N;
    vector < vector < T > > matrix;

public:
    Matrix(T mSize) {
        N = mSize;
        vector < vector < T > > m;
        for(int i = 0; i < mSize; i++) {
            vector < T > mR;
            m.push_back(mR);
        }
        matrix = m;
    }

    Matrix(T mSize, vector < vector < T > > table) {
        N = mSize;
        for(int i = 0; i < mSize; i++) {
            vector < T > matrixRow;
            for(int j = 0; j < mSize; j++) {
                matrixRow.push_back(table[i][j]);
            }
            matrix.push_back(matrixRow);
        }
    }

    Matrix swapRow(int first, int second) {
        Matrix < T > newMatrix(N);
        newMatrix.matrix = matrix;
        for(int i = 0; i < matrix.size(); i++) {
            swap(newMatrix.matrix[first-1][i], newMatrix.matrix[second-1][i]);
        }
        return newMatrix;
    }

    Matrix swapCol(int first, int second) {
        Matrix < T > newMatrix(N);
        newMatrix.matrix = matrix;
        for(int i = 0; i < matrix.size(); i++) {
            swap(newMatrix.matrix[i][first-1], newMatrix.matrix[i][second-1]);
        }
        return newMatrix;
    }

    Matrix inc() {
        Matrix < T > newMatrix(N);
        newMatrix.matrix = matrix;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                newMatrix.matrix[i][j] = (matrix[i][j]+1)%10;
            }
        }
        return newMatrix;
    }

    Matrix dec() {
        Matrix < T > newMatrix(N);
        newMatrix.matrix = matrix;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] != 0) {
                    newMatrix.matrix[i][j] = (matrix[i][j]-1)%10;
                } else {
                    newMatrix.matrix[i][j] = 9;
                }
            }
        }
        return newMatrix;
    }

    Matrix transpose() {
        Matrix < T > newMatrix(N);
        newMatrix.matrix = matrix;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                newMatrix.matrix[i][j] = matrix[j][i];
            }
        }
        return newMatrix;
    }

    void printMatrix() {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }
};


int main() {
    int cases;
    cin >> cases;
    for(int z = 1; z <= cases; z++) {
        int matrixSize;
        cin >> matrixSize;
        vector < vector < int > > tableForMatrix;
        // input matrix
        for(int i = 0; i < matrixSize; i++) {
            string row;
            cin >> row;
            vector < int > matrixRow;
            for(int j = 0; j < matrixSize; j++) {
                matrixRow.push_back(row[j] - '0');
            }
            tableForMatrix.push_back(matrixRow);
        }

        Matrix < int > simpleMatrix(matrixSize, tableForMatrix);

        int numberOfOperations;
        cin >> numberOfOperations;
        while(numberOfOperations--) {
            string operation;
            cin >> operation;
            if(operation == "row") {
                int first, second;
                cin >> first >> second;
                simpleMatrix = simpleMatrix.swapRow(first, second);
            } else if(operation == "col") {
                int first, second;
                cin >> first >> second;
                simpleMatrix = simpleMatrix.swapCol(first, second);
            } else if(operation == "inc") {
                simpleMatrix = simpleMatrix.inc();
            } else if(operation == "dec") {
                simpleMatrix = simpleMatrix.dec();
            } else if(operation == "transpose") {
                simpleMatrix = simpleMatrix.transpose();
            }
        }
        cout << "Case #" << z << endl;
        simpleMatrix.printMatrix();
        cout << endl;

    }
    return 0;
}
