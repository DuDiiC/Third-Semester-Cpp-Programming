#ifndef HEADERS_HPP
#define HEADERS_HPP
#include "headers.hpp"
#endif // HEADERS_HPP

#ifndef MATRIX_HPP
#define MATRIX_HPP

template <typename T, int R, int C>
class Matrix {

public:
    vector < vector < T > > matrix;

    //constructors
    Matrix(){}; // change
    Matrix(vector < vector < T > >);

    // operations
    void swapRow(int, int);
    void swapCol(int, int);
    void inc();
    void dec();
    Matrix<T,C,R> transpose(); // change with constructor
    void addRowXToY(int, int);
    void addColXToY(int, int);
    void multiplyRowXByY(int, T);
    void multiplyColXByY(int, T);
    void subtractRowXFromY(int, int);

    // overloading arithmetic operators

    // overloading == operator

    // overloading operators << and >>
    template < class MATRIX > // why it works ???
    friend ostream& operator<<(ostream&, const Matrix<T, R, C>&);
    template < class MATRIX > // ???
    friend istream& operator>>(istream&, Matrix<T, R, C>&); // change with constructor

};

template <typename T, int R, int C>
Matrix<T, R, C>::Matrix(vector < vector < T > > m) {
    for(int i = 0; i < R; i++) {
        vector < T > mRow;
        for(int j = 0; j < C; j++) {
            mRow.push_back(m[i][j]);
        }
        this->matrix.push_back(mRow);
    }
}

template <typename T, int R, int C>
void Matrix<T, R, C>::swapRow(int firstRow, int secondRow) {
    swap(this->matrix[firstRow-1], this->matrix[secondRow-1]);
}

template <typename T, int R, int C>
void Matrix<T, R, C>::swapCol(int firstCol, int secondCol) {
    for(int i = 0; i < this->matrix.size(); i++) {
        swap(this->matrix[i][firstCol-1], this->matrix[i][secondCol-1]);
    }
}

template <typename T, int R, int C>
void Matrix<T, R, C>::inc() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            this->matrix[i][j] += 1; // ADD FOR OTHERS CLASSES
        }
    }
}

template <typename T, int R, int C>
void Matrix<T, R, C>::dec() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            matrix[i][j] -= 1; // ADD FOR OTHERS CLASSES
        }
    }
}

template <typename T, int R, int C>
Matrix<T, C, R> Matrix<T, R, C>::transpose() {
    Matrix<T, C, R> newMatrix;
    for(int i = 0; i < C; i++) {
        vector < T > row;
        for(int j = 0; j < R; j++) {
            row.push_back(this->matrix[j][i]);
        }
        newMatrix.matrix.push_back(row);
    }

    return newMatrix;
}

template <typename T, int R, int C>
void Matrix<T, R, C>::addRowXToY(int x, int y) {
    for(int i = 0; i < C; i++) {
        this->matrix[y-1][i] += this->matrix[x-1][i];
    }
}

template <typename T, int R, int C>
void Matrix<T, R, C>::addColXToY(int x, int y) {
    for(int i = 0; i < R; i++) {
        this->matrix[i][y-1] += this->matrix[i][x-1];
    }
}

template <typename T, int R, int C>
void Matrix<T, R, C>::subtractRowXFromY(int x, int y) {
    for(int i = 0; i < R; i++) {
        this->matrix[y-1][i] -= this->matrix[x-1][i];
    }
}

template <typename T, int R, int C>
void Matrix<T, R, C>::multiplyRowXByY(int x, T y) {
    for(int i = 0; i < C; i++) {
        this->matrix[x-1][i] *= y;
    }
}

template <typename T, int R, int C>
void Matrix<T, R, C>::multiplyColXByY(int x, T y) {
    for(int i = 0; i < R; i++) {
        this->matrix[i][x-1] *= y;
    }
}



template <typename T, int R, int C>
ostream& operator<<(ostream &output, const Matrix<T, R, C> &M) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            output << M.matrix[i][j] << " ";
        }
        output << endl;
    }

    return output;
}

template <typename T, int R, int C>
istream& operator>>(istream &input, Matrix<T, R, C> &M) {
    for(int i = 0; i < R; i++) {
        vector < T > row;
        for(int j = 0; j < C; j++) {
            T temp;
            input >> temp;
            row.push_back(temp);
        }
        M.matrix.push_back(row);
    }

    return input;
}


#endif // MATRIX_HPP
