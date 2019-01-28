#ifndef HEADERS_HPP
#define HEADERS_HPP
#include "headers.hpp"
#endif // HEADERS_HPP

#ifndef MATRIX_HPP
#define MATRIX_HPP

template <typename T, unsigned int R, unsigned int C>
class Matrix {

public:
    vector < vector < T > > matrix;

    //constructors
    Matrix();
    Matrix(vector < vector < T > >);

    // operations
    void swapRow(unsigned int, unsigned int);
    void swapCol(unsigned int, unsigned int);
    Matrix<T,C,R> transpose();
    void addRowXToY(unsigned int, unsigned int);
    void addRowXToY(unsigned int, unsigned int, T);
    void addColXToY(unsigned int, unsigned int);
    void addColXToY(unsigned int, unsigned int, T);
    void multiplyRowXByY(unsigned int, T);
    void multiplyColXByY(unsigned int, T);
    void subtractRowXFromY(unsigned int, unsigned int);
    void subtractColXFromY(unsigned int, unsigned int);
    Matrix<T,R,C> upperStepped();

    // overloading arithmetic operators
    Matrix<T, R, C> operator+(const Matrix<T, R, C>&) const;
    Matrix<T, R, C> operator+(const T&) const;
    Matrix<T, R, C>& operator+=(const Matrix<T, R, C>&);
    Matrix<T, R, C> operator-(const Matrix<T, R, C>&) const;
    Matrix<T, R, C> operator-(const T&) const;
    Matrix<T, R, C>& operator-=(const Matrix<T, R, C>&);
    template <unsigned int D>
    Matrix<T, R, D> operator*(const Matrix<T, C, D>&);
    Matrix<T, R, C> operator*(const T&) const;

    // overloading equals operator
    bool operator==(const Matrix<T, R, C>&);
    bool operator!=(const Matrix<T, R, C>&);

    // overloading operators << and >>
    template < class MATRIX >
    friend ostream& operator<<(ostream&, const Matrix<T, R, C>&);
    template < class MATRIX >
    friend istream& operator>>(istream&, Matrix<T, R, C>&);
};

template <typename T, unsigned int R, unsigned int C>
Matrix<T, R, C>::Matrix() {
    for(int i = 0; i < R; i++) {
        vector < T > row;
        this->matrix.push_back(row);
    }
}

template <typename T, unsigned int R, unsigned int C>
Matrix<T, R, C>::Matrix(vector < vector < T > > m) {
    for(int i = 0; i < R; i++) {
        vector < T > mRow;
        for(int j = 0; j < C; j++) {
            mRow.push_back(m[i][j]);
        }
        this->matrix.push_back(mRow);
    }
}

template <typename T, unsigned int R, unsigned int C>
void Matrix<T, R, C>::swapRow(unsigned int firstRow, unsigned int secondRow) {
    swap(this->matrix[firstRow-1], this->matrix[secondRow-1]);
}

template <typename T, unsigned int R, unsigned int C>
void Matrix<T, R, C>::swapCol(int unsigned firstCol, unsigned int secondCol) {
    for(int i = 0; i < this->matrix.size(); i++) {
        swap(this->matrix[i][firstCol-1], this->matrix[i][secondCol-1]);
    }
}

template <typename T, unsigned int R, unsigned int C>
Matrix<T, C, R> Matrix<T, R, C>::transpose() {

    vector < vector < T > > newVector;

    for(int i = 0; i < C; i++) {
        vector < T > row;
        for(int j = 0; j < R; j++) {
            row.push_back(this->matrix[j][i]);
        }
        newVector.push_back(row);
    }

    Matrix<T, C, R> newMatrix(newVector);

    return newMatrix;
}

template <typename T, unsigned int R, unsigned int C>
void Matrix<T, R, C>::addRowXToY(unsigned int x, unsigned int y) {
    for(int i = 0; i < C; i++) {
        this->matrix[y-1][i] += this->matrix[x-1][i];
    }
}

template <typename T, unsigned int R, unsigned int C>
void Matrix<T, R, C>::addRowXToY(unsigned int x, unsigned int y, T temp) {
    for(int i = 0; i < C; i++) {
        this->matrix[y-1][i] += temp*this->matrix[x-1][i];
    }
}

template <typename T, unsigned int R, unsigned int C>
void Matrix<T, R, C>::addColXToY(unsigned int x, unsigned int y) {
    for(int i = 0; i < R; i++) {
        this->matrix[i][y-1] += this->matrix[i][x-1];
    }
}

template <typename T, unsigned int R, unsigned int C>
void Matrix<T, R, C>::addColXToY(unsigned int x, unsigned int y, T temp) {
    for(int i = 0; i < R; i++) {
        this->matrix[i][y-1] += temp*this->matrix[i][x-1];
    }
}

template <typename T, unsigned int R, unsigned int C>
void Matrix<T, R, C>::subtractRowXFromY(unsigned int x, unsigned int y) {
    for(int i = 0; i < R; i++) {
        this->matrix[y-1][i] -= this->matrix[x-1][i];
    }
}

template <typename T, unsigned int R, unsigned int C>
void Matrix<T, R, C>::subtractColXFromY(unsigned int x, unsigned int y) {
    for(int i = 0; i < C; i++) {
        this->matrix[i][y-1] -= this->matrix[i][x-1];
    }
}

template <typename T, unsigned int R, unsigned int C>
void Matrix<T, R, C>::multiplyRowXByY(unsigned int x, T y) {
    for(int i = 0; i < C; i++) {
        this->matrix[x-1][i] *= y;
    }
}

template <typename T, unsigned int R, unsigned int C>
void Matrix<T, R, C>::multiplyColXByY(unsigned int x, T y) {
    for(int i = 0; i < R; i++) {
        this->matrix[i][x-1] *= y;
    }
}

template <typename T, unsigned int R, unsigned int C>
Matrix<T, R, C> Matrix<T, R, C>::upperStepped() {

    Matrix<T, R, C> newMatrix = *this;
    T one(1), minusOne(-1), zero(0);

    int j = 0;
    for(int i = 0; i < R; i++) {
        int k = i;
        while(k < R && j < C && newMatrix.matrix[k][j] == zero) {
            k++;
            if(k == R) {
                k = i;
                j++;
            }
        }
        if(j != C) {
            if(k != i) {
                newMatrix.swapRow(i+1, k+1);
            }
            if(newMatrix.matrix[i][j] != one) {
                newMatrix.multiplyRowXByY(i+1, one/(newMatrix.matrix[i][j]));
            }
            for(k = i+1; k < R; k++) {
                newMatrix.addRowXToY(i+1, k+1, newMatrix.matrix[k][j]*minusOne);
            }
        } else {
            i = R;
        }
        j++;
    }

    return newMatrix;
}

template <typename T, unsigned int R, unsigned int C>
Matrix<T, R, C> Matrix<T, R, C>::operator+(const Matrix<T, R, C> &M) const {

    Matrix<T, R, C> newMatrix;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            newMatrix.matrix[i].push_back(this->matrix[i][j]+M.matrix[i][j]);
        }
    }

    return newMatrix;
}

template <typename T, unsigned int R, unsigned int C>
Matrix<T, R, C> Matrix<T, R, C>::operator+(const T &temp) const {

    Matrix<T, R, C> newMatrix;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            newMatrix.matrix[i].push_back(this->matrix[i][j]+temp);
        }
    }

    return newMatrix;
}

template <typename T, unsigned int R, unsigned int C>
Matrix<T, R, C>& Matrix<T, R, C>::operator+=(const Matrix<T, R, C> &M) {
    *this = (*this)+M;
    return *this;
}

template <typename T, unsigned int R, unsigned int C>
Matrix<T, R, C> Matrix<T, R, C>::operator-(const Matrix<T, R, C> &M) const {

    Matrix<T, R, C> newMatrix;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            newMatrix.matrix[i].push_back(this->matrix[i][j] - M.matrix[i][j]);
        }
    }

    return newMatrix;
}

template <typename T, unsigned int R, unsigned int C>
Matrix<T, R, C> Matrix<T, R, C>::operator-(const T &temp) const {

    Matrix<T, R, C> newMatrix;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            newMatrix.matrix[i].push_back(this->matrix[i][j]-temp);
        }
    }

    return newMatrix;
}

template <typename T, unsigned int R, unsigned int C>
Matrix<T, R, C>& Matrix<T, R, C>::operator-=(const Matrix<T, R, C> &M) {
    *this = (*this)-M;
    return *this;
}

template <typename T, unsigned int R, unsigned int C>
template <unsigned int D>
Matrix<T, R, D> Matrix<T, R, C>::operator*(const Matrix<T, C, D> &M) {
    Matrix<T, R, D> newMatrix;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < D; j++) {
            T temp(0);
            for(int k = 0; k < C; k++) {
                temp = temp+(this->matrix[i][k]*M.matrix[k][j]);
            }
            newMatrix.matrix[i].push_back(temp);
        }
    }
    return newMatrix;
}

template <typename T, unsigned int R, unsigned int C>
Matrix<T, R, C> Matrix<T, R, C>::operator*(const T &temp) const {

    Matrix<T, R, C> newMatrix;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            newMatrix.matrix[i].push_back(this->matrix[i][j]*temp);
        }
    }

    return newMatrix;
}

template <typename T, unsigned int R, unsigned int C>
bool Matrix<T, R, C>::operator==(const Matrix<T, R, C> &M) {
    bool equality = true;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(!(this->matrix[i][j] == M.matrix[i][j])) equality = false;
        }
    }
    return equality;
}

template <typename T, unsigned int R, unsigned int C>
bool Matrix<T, R, C>::operator!=(const Matrix<T, R, C> &M) {
    return !((*this) == M);
}

template <typename T, unsigned int R, unsigned int C>
ostream& operator<<(ostream &output, const Matrix<T, R, C> &M) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            output << M.matrix[i][j] << "\t";
        }
        output << endl;
    }

    return output;
}

template <typename T, unsigned int R, unsigned int C>
istream& operator>>(istream &input, Matrix<T, R, C> &M) {

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            T temp;
            input >> temp;
            M.matrix[i].push_back(temp);

        }
    }

    return input;
}

#endif // MATRIX_HPP
