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

    T determinant(); // dziala int, Rational, Zp
    // constructors
    SquareMatrix();
    SquareMatrix(Matrix<T, N, N>);

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

    T determinantValue(1);

    for(int i = 0; i < N-1; i++) {

        this->onlyPositive(i, determinantValue);

        int max1, max2;
        this->giveMax(max1, max2, i);

        if(this->matrix[max1][i] == 0 && this->matrix[max2][i] == 0)
            return 0;

        while(this->matrix[max2][i] != 0) {
            this->subtractRowXFromY(max2+1, max1+1);
            this->giveMax(max1, max2, i);
        }

        // przesunac max1 na gore // ?
        if(max1 != i) {
            this->swapRow(i+1, max1+1);
            determinantValue *= -1;
        }
    }

    for(int i = 0; i < N; i++) {
        determinantValue *= this->matrix[i][i];
    }

    return determinantValue;
}

template <typename T, unsigned int N>
void SquareMatrix<T, N>::onlyPositive(int column, T &det) {
    for(int i = 0; i < N; i++) {
        if(this->matrix[i][column] < 0) {
            this->multiplyRowXByY(i+1, -1);
            det *= -1;
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
