#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
public:
    int R;
    int C;
    vector < vector < T > > matrix;

    Matrix(int rows, int columns) {
        C = columns;
        R = rows;
    }

    Matrix(int rows, int columns, vector < vector < T > > table) {
        C = columns;
        R = rows;
        for(int i = 0; i < rows; i++) {
            vector < T > matrixRow;
            for(int j = 0; j < columns; j++) {
                matrixRow.push_back(table[i][j]);
            }
            matrix.push_back(matrixRow);
        }
    }

    void swapRow(int first, int second) {
        swap(matrix[first-1], matrix[second-1]);
    }

    void swapCol(int first, int second) {
        for(int i = 0; i < matrix.size(); i++) {
            swap(matrix[i][first-1], matrix[i][second-1]);
        }
    }

    void inc() {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] += 1;
            }
        }
    }

    void dec() {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] -= 1;
            }
        }
    }

    Matrix transpose() {
        Matrix < T > newMatrix(C, R);
        for(int i = 0; i < C; i++) {
            vector < T > rows;
            for(int j = 0; j < R; j++) {
                rows.push_back(matrix[j][i]);
                //newMatrix.matrix[i][j] = matrix[j][i];
            }
            newMatrix.matrix.push_back(rows);
        }
        return newMatrix;
    }

    void addRowXToY(int x, int y) {
        for(int i = 0; i < C; i++) {
            matrix[y-1][i] += matrix[x-1][i];
        }
    }

    void addColXToY(int x, int y) {
        for(int i = 0; i < R; i++) {
            matrix[i][y-1] += matrix[i][x-1];
        }
    }

    void multiplyRowXByY(int x, T y) {
        for(int i = 0; i < C; i++) {
            matrix[x-1][i] *= y;
        }
    }

    void multiplyColXByY(int x, T y) {
        for(int i = 0; i < R; i++) {
            matrix[i][x-1] *= y;
        }
    }

    void subtractRowXFromY(int x, int y) {
        for(int i = 0; i < this->R; i++) {
            this->matrix[y-1][i] -= this->matrix[x-1][i];
        }
    }

    void addRowXFromY(int x, int y) {
        for(int i = 0; i < this->R; i++) {
            this->matrix[y-1][i] += this->matrix[x-1][i];
        }
    }

    T gcd(T first, T second) {
        if(first == 0 || second == 0) return 0;
        while(second != 0) {
            T temp = first%second;
            first = second;
            second = temp;
        }

        return (first > 0) ? first : -first;
    }

    T lcm(T first, T second) {
        if(gcd(first, second) == 0) return 0;
        return (first*second)/gcd(first, second);
    }

    T gcdRow(int row) {
        int firstNonZero = -1, secondNonZero = -1;

        for(int i = 0; i < R; i++) {
            if(matrix[row-1][i] != 0) {
                firstNonZero = i;
                break;
            }
        }

        if(firstNonZero != -1 && firstNonZero != R-1) {
            for(int i = firstNonZero+1; i < R; i++) {
                if(matrix[row-1][i] != 0) {
                    secondNonZero = i;
                    break;
                }
            }
        } else {
            return 1;
        }

        int GCD;
        if(secondNonZero != -1) {
            GCD = gcd(matrix[row-1][firstNonZero], matrix[row-1][secondNonZero]);
        } else {
            return 1;
        }

        if(secondNonZero != R-1) {
            for(int i = secondNonZero+1; i < R; i++) {
                if(matrix[row-1][i] != 0) {
                    GCD = gcd(matrix[row-1][i], GCD);
                }
            }
        }

        return GCD;
    }



    void printMatrix() {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

template <typename T >
class SquareMatrix: public Matrix < T > {
public:
    SquareMatrix(int N) : Matrix<T>::Matrix( N, N ) { }

    SquareMatrix(int N, vector < vector < T > > table) {
        this->R = N;
        this->C = N;
        for(int i = 0; i < N; i++) {
            vector < T > matrixRow;
            for(int j = 0; j < N; j++) {
                matrixRow.push_back(table[i][j]);
            }
            this->matrix.push_back(matrixRow);
        }
    }

    T determinant() {
        T determinantValue(1);

        for(int i = 0; i < this->C-1; i++) {

            this->onlyPositive(i, determinantValue);

            int max1, max2;
            this->giveMax(max1, max2, i);

            if(this->matrix[max1][i] == 0 && this->matrix[max2][i] == 0) return 0;

            while(this->matrix[max2][i] != 0) {
                this->subtractRowXFromY(max2+1, max1+1);
                //this->printMatrix();
                this->giveMax(max1, max2, i);
            }

            // przesunac max1 na gore
            if(max1 != i) {
                this->swapRow(i+1, max1+1);
                determinantValue *= -1;
            }
        }

        for(int i = 0; i < this->R; i++) {
            determinantValue *= this->matrix[i][i];
        }

        return determinantValue;
    }

    void onlyPositive(int column, T &det) {
        for(int i = 0; i < this->C; i++) {
            if(this->matrix[i][column] < 0) {
                this->multiplyRowXByY(i+1, -1);
                det *= -1;
            }
        }
    }

    void giveMax(int &max1, int &max2, int column) {

        max1 = column;
        for(int i = column; i < this->C; i++) {
            if(this->matrix[i][column] > this->matrix[max1][column]) {
                max1 = i;
            }
        }

        if(max1 != column) max2 = column;
        else max2 = column+1;
        for(int i = column; i < this->C; i++) {
            if(max1 != i) {
                if(this->matrix[i][column] > this->matrix[max2][column]) {
                    max2 = i;
                }
            }
        }
    }

};


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
