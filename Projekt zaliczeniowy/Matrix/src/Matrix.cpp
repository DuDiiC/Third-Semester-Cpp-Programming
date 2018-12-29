//#include "Matrix.hpp"
/*
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
    for(int i = 0; i < this->matrix.size(); i++) {
        for(int j = 0; j < this->matrix[i].size(); i++) {
            this->matrix[i][j] += 1; // DOPISAC OBSLUGE TEGO DLA INNYCH
        }
    }
}

template <typename T, int R, int C>
void Matrix<T, R, C>::dec() {
    for(int i = 0; i < this->matrix.size(); i++) {
        for(int j = 0; j < this->matrix[i].size(); i++) {
            matrix[i][j] -= 1; // DOPISAC OBSLUGE TEGO DLA INNYCH
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
*/
