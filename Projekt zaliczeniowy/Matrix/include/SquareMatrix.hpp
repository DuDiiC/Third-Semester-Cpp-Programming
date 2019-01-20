#ifndef HEADERS_HPP
#define HEADERS_HPP
#include "headers.hpp"
#endif // HEADERS_HPP

#ifndef SQUARE_MATRIX_HPP
#define SQUARE_MATRIX_HPP
#include "Matrix.hpp"
#include "Complex.hpp"

template <typename T, unsigned int N>
class SquareMatrix : public Matrix <T, N, N> {

public:

    // constructors
    SquareMatrix();
    SquareMatrix(Matrix<T, N, N>);

    // operations
    T determinant();
    SquareMatrix<T, N> algebraicComplement(); // dopelnienie algebraiczne
    SquareMatrix<T, N> inverseMatrix(); // macierz odwrotna

private:
    void onlyPositive(int, T&);
    void giveMax(int&, int&, int);
};

template <typename T, unsigned int N>
SquareMatrix<T, N>::SquareMatrix() {
    for(int i = 0; i < N; i++) {
        vector < T > row;
        this->matrix.push_back(row);
    }
}

template <typename T, unsigned int N>
SquareMatrix<T, N>::SquareMatrix(Matrix<T, N, N> m) {
    for(int i = 0; i < N; i++) {
        vector < T > row;
        for(int j = 0; j < N; j++) {
            row.push_back(m.matrix[i][j]);
        }
        this->matrix.push_back(row);
    }
}

template <typename T, unsigned int N>
T SquareMatrix<T, N>::determinant() {

    if(N == 2) {
        return (this->matrix[0][0]*this->matrix[1][1]) - (this->matrix[1][0]*this->matrix[0][1]);
    } else if(N == 3) {
        T determinantValue(0);
        for(int i = 0; i < 3; i++) {
            determinantValue += this->matrix[i%3][0]*this->matrix[(i+1)%3][1]*this->matrix[(i+2)%3][2];
        }
        for(int i = 0; i < 3; i++) {
            determinantValue -= this->matrix[i%3][2]*this->matrix[(i+1)%3][1]*this->matrix[(i+2)%3][0];
        }
        return determinantValue;
    }

    SquareMatrix<T, N> newMatrix = *this;
    T determinantValue(1);

    for(int i = 0; i < N-1; i++) {

        this->onlyPositive(i, determinantValue);

        int max1, max2;
        newMatrix.giveMax(max1, max2, i);

        if(newMatrix.matrix[max1][i] == T(0) && newMatrix.matrix[max2][i] == T(0))
            return T(0);

        while(newMatrix.matrix[max2][i] != T(0)) {
            newMatrix.subtractRowXFromY(max2+1, max1+1);
            newMatrix.giveMax(max1, max2, i);
        }

        // przesunac max1 na gore // ?
        if(max1 != i) {
            newMatrix.swapRow(i+1, max1+1);
            determinantValue *= T(-1);
        }
    }

    for(int i = 0; i < N; i++) {
        determinantValue *= newMatrix.matrix[i][i];
    }

    return determinantValue;
}


template <typename T, unsigned int N>
SquareMatrix<T, N> SquareMatrix<T, N>::algebraicComplement() {

    SquareMatrix<T, N> newMatrix;
    T minusOne(-1);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            SquareMatrix<T, N-1> newSmallMatrix;
            int temp = 0;
            for(int k = 0; k < N; k++) {
                if(k != i) {
                    for(int m = 0; m < N; m++) {
                        if(m != j) {
                            newSmallMatrix.matrix[temp].push_back(this->matrix[k][m]);
                        }
                    }
                    temp++;
                }
            }

            if((i+j)%2) {
                newMatrix.matrix[i].push_back(minusOne*newSmallMatrix.determinant());
            } else {
                newMatrix.matrix[i].push_back(newSmallMatrix.determinant());
            }
        }
    }

    return newMatrix;
}

template <typename T, unsigned int N>
SquareMatrix<T, N> SquareMatrix<T, N>::inverseMatrix() {
    SquareMatrix<T, N> newMatrix = *(this);
    newMatrix = newMatrix.algebraicComplement();
    newMatrix = newMatrix.transpose();
    newMatrix = newMatrix * (T(1)/this->determinant());
    return newMatrix;
}

template <typename T, unsigned int N>
void SquareMatrix<T, N>::onlyPositive(int column, T &det) {
    for(int i = 0; i < N; i++) {
        if(this->matrix[i][column] < T(0)) {
            this->multiplyRowXByY(i+1, T(-1));
            det *= T(-1);
        }
    }
}

template <typename T, unsigned int N>
void SquareMatrix<T, N>::giveMax(int &max1, int &max2, int column) {

    max1 = column;
    for(int i = column; i < N; i++) {
        if(this->matrix[i][column] > this->matrix[max1][column]) {
            max1 = i;
        }
    }

    if(max1 != column)
        max2 = column;
    else
        max2 = column+1;
    for(int i = column; i < N; i++) {
        if(max1 != i) {
            if(this->matrix[i][column] > this->matrix[max2][column]) {
                max2 = i;
            }
        }
    }
}
#endif // SQUARE_MATRIX_HPP
