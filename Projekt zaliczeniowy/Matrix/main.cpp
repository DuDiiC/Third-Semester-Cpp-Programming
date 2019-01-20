#include "headers.hpp"
#include "Matrix.hpp"
#include "SquareMatrix.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "Zp.hpp"

void introdutionMenu(int&, int&);

template <typename T, unsigned int R, unsigned int C>
void menuForMatrix(Matrix<T, R, C> m);

template <typename T, unsigned int R, unsigned int C>
void choiceOperationForMatrix(int, Matrix<T, R, C> &);

template <typename T, unsigned int N>
void choiceOperationForSquareMatrix(int, SquareMatrix<T, N> &);

int main() {

    int mType = 0, mClass = 0, mOperation = 1;
    introdutionMenu(mType, mClass);

    if(mType == 1) {
        switch(mClass) {

        case 1: {
            Matrix<int, 3, 4> mInt;
            cout << "Wczytaj macierz 3x4 typu int: " << endl;
            cin >> mInt;
            while(mOperation) {
                menuForMatrix(mInt);
                cout << "Twoj wybor: ";
                cin >> mOperation;
                choiceOperationForMatrix(mOperation, mInt);
            }
            break;
        }

        case 2: {
            Matrix<double, 3, 4> mDouble;
            cout << "Wczytaj macierz 3x4 typu double: " << endl;
            cin >> mDouble;
            while(mOperation) {
                menuForMatrix(mDouble);
                cout << "Twoj wybor: ";
                cin >> mOperation;
                choiceOperationForMatrix(mOperation, mDouble);
            }
            break;
        }

        case 3: {
            Matrix<Z<4>, 3, 4> mZ4;
            cout << "Wczytaj macierz 3x4 typu Z<4> " << endl;
            cin >> mZ4;
            while(mOperation) {
                menuForMatrix(mZ4);
                cout << "Twoj wybor: ";
                cin >> mOperation;
                choiceOperationForMatrix(mOperation, mZ4);
            }
            break;
        }

        case 4: {
            Matrix<Rational, 3, 4> mRational;
            cout << "Wczytaj macierz 3x4 typu Rational " << endl;
            cin >> mRational;
            while(mOperation) {
                menuForMatrix(mRational);
                cout << "Twoj wybor: ";
                cin >> mOperation;
                choiceOperationForMatrix(mOperation, mRational);
            }
            break;
        }

        case 5: {
            Matrix<Complex, 3, 4> mComplex;
            cout << "Wczytaj macierz 3x4 typu Complex " << endl;
            cin >> mComplex;
            while(mOperation) {
                menuForMatrix(mComplex);
                cout << "Twoj wybor: ";
                cin >> mOperation;
                choiceOperationForMatrix(mOperation, mComplex);
            }
            break;
        }
        }
    } else if(mType == 2) {
        switch(mClass) {

        case 1: {
            SquareMatrix<int, 3> smInt;
            cout << "Wczytaj macierz 3x3 typu int: " << endl;
            cin >> smInt;
            while(mOperation) {
                menuForMatrix(smInt);
                cout << "17. Oblicz wyznacznik" << endl;
                cout << "18. Wyznacz macierz odwrotna." << endl;
                cout << "Twoj wybor: ";
                cin >> mOperation;
                choiceOperationForSquareMatrix(mOperation, smInt);
            }
            break;
        }

        case 2: {
            SquareMatrix<double, 3> smDouble;
            cout << "Wczytaj macierz 3x3 typu double: " << endl;
            cin >> smDouble;
            while(mOperation) {
                menuForMatrix(smDouble);
                cout << "17. Oblicz wyznacznik" << endl;
                cout << "18. Wyznacz macierz odwrotna." << endl;
                cout << "Twoj wybor: ";
                cin >> mOperation;
                choiceOperationForSquareMatrix(mOperation, smDouble);
            }
            break;
        }

        case 3: {
            SquareMatrix<Z<4>, 3> smZ4;
            cout << "Wczytaj macierz 3x3 typu Z<4>: " << endl;
            cin >> smZ4;
            while(mOperation) {
                menuForMatrix(smZ4);
                cout << "17. Oblicz wyznacznik" << endl;
                cout << "18. Wyznacz macierz odwrotna." << endl;
                cout << "Twoj wybor: ";
                cin >> mOperation;
                choiceOperationForSquareMatrix(mOperation, smZ4);
            }
            break;
        }

        case 4: {
            SquareMatrix<Rational, 3> smRational;
            cout << "Wczytaj macierz 3x3 typu Rational: " << endl;
            cin >> smRational;
            while(mOperation) {
                menuForMatrix(smRational);
                cout << "17. Oblicz wyznacznik" << endl;
                 cout << "18. Wyznacz macierz odwrotna." << endl;
                cout << "Twoj wybor: ";
                cin >> mOperation;
                choiceOperationForSquareMatrix(mOperation, smRational);
            }
            break;
        }

        case 5: {
            SquareMatrix<Complex, 3> smComplex;
            cout << "Wczytaj macierz 3x3 typu Complex: " << endl;
            cin >> smComplex;
            while(mOperation) {
                menuForMatrix(smComplex);
                cout << "17. Oblicz wyznacznik." << endl;
                cout << "18. Wyznacz macierz odwrotna." << endl;
                cout << "Twoj wybor: ";
                cin >> mOperation;
                choiceOperationForSquareMatrix(mOperation, smComplex);
            }
            break;
        }
        }
    } else if(mType == 3) {
        exit(0);
    }
    return 0;
}

void introdutionMenu(int &matrixType, int &matrixClass) {

    cout << "PROGRAM PREZENTUJACY DZIALANIE KLASY MACIERZY" << endl << endl;
    cout << "---------------------------------------" << endl << endl;

    cout << "Wybierz na jakiej macierzy chcesz pracowac:" << endl;
    cout << "1. Macierz prostokatna o wymiarze 3x4." << endl;
    cout << "2. Macierz kwadratowa o wymiarze 3x3." << endl;
    cout << "3. Opusc program." << endl;
    cout << "Twoj wybor: ";
    cin >> matrixType;
    cout << endl;

    cout << "---------------------------------------" << endl << endl;
    cout << "Wybierz, na jakiego typu macierzy chcesz pracowac:" << endl;
    cout << " 1. int" << endl;
    cout << " 2. double" << endl;
    cout << " 3. Z<4>" << endl;
    cout << " 4. Liczby rzeczywiste w formacie x|y" << endl;
    cout << " 5. Liczby zespolone w formacie x+yi" << endl;
    cout << "Twoj wybor: ";
    cin >> matrixClass;
    cout << endl;

    cout << "---------------------------------------" << endl << endl;
}

template <typename T, unsigned int R, unsigned int C>
void menuForMatrix(Matrix<T, R, C> m) {
    cout << endl;
    cout << "---------------------------------------" << endl << endl;
    cout << "Aktualna macierz: " << endl;
    cout << m << endl << endl;
    cout << "---------------------------------------" << endl << endl;
    cout << " 0. Zakoncz." << endl;
    cout << " 1. Zamien dwa wiersze." << endl;
    cout << " 2. Zamien dwie kolumny." << endl;
    cout << " 3. Podaj macierz transponowana." << endl;
    cout << " 4. Dodaj do siebie dwa wiersze." << endl;
    cout << " 5. Dodaj do siebie dwie kolumny." << endl;
    cout << " 6. Pomnoz wiersz przez liczbe." << endl;
    cout << " 7. Pomnoz kolumne przez liczbe." << endl;
    cout << " 8. Odejmij jeden wiersz od drugiego." << endl;
    cout << " 9. Odejmij jedna kolumne od drugiej." << endl;
    cout << "10. Dodawanie macierzy." << endl;
    cout << "11. Dodaj liczbe do kazdej komorki macierzy." << endl;
    cout << "12. Odejmowanie macierzy." << endl;
    cout << "13. Odejmij liczbe od kazdej komorki macierzy." << endl;
    cout << "14. Mnozenie macierzy. " << endl;
    cout << "15. Porownanie ze soba dwoch macierzy." << endl;
    cout << "16. Wyznacz macierz gorno-schodkowa." << endl;
}

template <typename T, unsigned int R, unsigned int C>
void choiceOperationForMatrix(int option, Matrix<T, R, C> &m) {
    cout << endl;
    cout << "---------------------------------------" << endl << endl;
    if(option == 1) {
        int firstRow, secondRow;
        cout << "Ktore dwa wiersze chcesz zamienic?" << endl;
        cin >> firstRow >> secondRow;
        m.swapRow(firstRow, secondRow);
        cout << m << endl;
    } else if(option == 2) {
        int firstColumn, secondColumn;
        cout << "Ktore dwa wiersze chcesz zamienic?" << endl;
        cin >> firstColumn >> secondColumn;
        m.swapCol(firstColumn, secondColumn);
        cout << m << endl;
    } else if(option == 3) {
        cout << "Macierz transponowana do wczytanej:" << endl;
        cout << m.transpose() << endl;
    } else if(option == 4) {
        int firstRow, secondRow;
        char ch;
        cout << "Ktory wiersz do ktorego chcesz dodac? ";
        cin >> firstRow >> secondRow;
        cout << "Czy dodawany wiersz ma byc pomnozony? (y/n): ";
        cin >> ch;
        if(ch == 'y') {
            T temp;
            cout << "Przez jaka liczbe (musi byc zgodna z typem macierzy): ";
            cin >> temp;
            m.addRowXToY(firstRow, secondRow, temp);
            cout << m << endl;
        } else if(ch == 'n') {
            m.addRowXToY(firstRow, secondRow);
            cout << m << endl;
        }
    } else if(option == 5) {
        int firstColumn, secondColumn;
        char ch;
        cout << "Ktora kolumne chcesz dodac do ktorej? ";
        cin >> firstColumn >> secondColumn;
        cout << "Czy dodawana kolumna ma byc pomnozona? (y/n): ";
        cin >> ch;
        if(ch == 'y') {
            T temp;
            cout << "Przez jaka liczbe (musi byc zgodna z typem macierzy): ";
            cin >> temp;
            m.addColXToY(firstColumn, secondColumn, temp);
            cout << m << endl;
        } else if(ch == 'n') {
            m.addColXToY(firstColumn, secondColumn);
            cout << m << endl;
        }
    } else if(option == 6) {
        int row;
        T temp;
        cout << "Ktory wiersz: ";
        cin >> row;
        cout << "Jaka liczbe (musi byc zgodna z typem macierzy): ";
        cin >> temp;
        m.multiplyRowXByY(row, temp);
        cout << m << endl;
    } else if(option == 7) {
        int column;
        T temp;
        cout << "Ktora kolumna: ";
        cin >> column;
        cout << "Jaka liczbe (musi byc zgoda z typem macierzy): ";
        cin >> temp;
        m.multiplyColXByY(column, temp);
        cout << m << endl;
    } else if(option == 8) {
        int firstRow, secondRow;
        cout << "Ktory wiersz od ktorego? ";
        cin >> firstRow >> secondRow;
        m.subtractRowXFromY(firstRow, secondRow);
        cout << m << endl;
    } else if(option == 9) {
        int firstColumn, secondColumn;
        cout << "Ktora kolumna od ktorej? ";
        cin >> firstColumn >> secondColumn;
        m.subtractColXFromY(firstColumn, secondColumn);
        cout << m << endl;
    } else if(option == 10) {
        Matrix<T, R, C> newMatrix;
        cout << "Podaj druga macierz (o tych samych wymiarach i typie danych co pierwsza):" << endl;
        cin >> newMatrix;
        cout << "Wynik dodawania:" << endl;
        cout << m+newMatrix << endl;
    } else if(option == 11) {
        T temp;
        cout << "Podaj liczbe (musi byc zgodna z typem macierzy): ";
        cin >> temp;
        cout << "Wynik dodawania:" << endl;
        m = m+temp;
        cout << m << endl;
    } else if(option == 12) {
        Matrix<T, R, C> newMatrix;
        cout << "Podaj druga macierz (o tych samych wymiarach i typie danych co pierwsza):" << endl;
        cin >> newMatrix;
        cout << "Wynik odejmowania:" << endl;
        cout << m-newMatrix << endl;
    } else if(option == 13) {
        T temp;
        cout << "Podaj liczbe (musi byc zgodna z typem macierzy): ";
        cin >> temp;
        cout << "Wynik odejmowania:" << endl;
        m = m-temp;
        cout << m << endl;
    } else if(option == 14) {
        Matrix<T, C, 3> newMatrix;
        cout << "Podaj druga macierz (o wymiarach " << C << "x3 i typie danych takim co pierwsza):" << endl;
        cin >> newMatrix;
        cout << "Wynik mnozenia:" << endl;
        cout << m*newMatrix << endl;
    } else if(option == 15) {
        Matrix<T, R, C> newMatrix;
        cout << "Podaj druga macierz (o tych samych wymiarach i typie danych co pierwsza):" << endl;
        cin >> newMatrix;
        if(m == newMatrix) {
            cout << "Sa to te same macierze." << endl;
        } else {
            cout << "Sa to dwie inne macierze." << endl;
        }
    } else if(option == 16) {
        cout << "Macierz gorno-schodkowa:" << endl;
        cout << m.upperStepped() << endl;
    }
}

template <typename T, unsigned int N>
void choiceOperationForSquareMatrix(int option, SquareMatrix<T, N> &sm) {
    cout << endl;
    cout << "---------------------------------------" << endl << endl;
    if(option == 1) {
        int firstRow, secondRow;
        cout << "Ktore dwa wiersze chcesz zamienic?" << endl;
        cin >> firstRow >> secondRow;
        sm.swapRow(firstRow, secondRow);
        cout << sm << endl;
    } else if(option == 2) {
        int firstColumn, secondColumn;
        cout << "Ktore dwa wiersze chcesz zamienic?" << endl;
        cin >> firstColumn >> secondColumn;
        sm.swapCol(firstColumn, secondColumn);
        cout << sm << endl;
    } else if(option == 3) {
        cout << "Macierz transponowana do wczytanej:" << endl;
        cout << sm.transpose() << endl;
    } else if(option == 4) {
        int firstRow, secondRow;
        char ch;
        cout << "Ktory wiersz do ktorego chcesz dodac? ";
        cin >> firstRow >> secondRow;
        cout << "Czy dodawany wiersz ma byc pomnozony? (y/n): ";
        cin >> ch;
        if(ch == 'y') {
            T temp;
            cout << "Przez jaka liczbe (musi byc zgodna z typem macierzy): ";
            cin >> temp;
            sm.addRowXToY(firstRow, secondRow, temp);
            cout << sm << endl;
        } else if(ch == 'n') {
            sm.addRowXToY(firstRow, secondRow);
            cout << sm << endl;
        }
    } else if(option == 5) {
        int firstColumn, secondColumn;
        char ch;
        cout << "Ktora kolumne chcesz dodac do ktorej? ";
        cin >> firstColumn >> secondColumn;
        cout << "Czy dodawana kolumna ma byc pomnozona? (y/n): ";
        cin >> ch;
        if(ch == 'y') {
            T temp;
            cout << "Przez jaka liczbe (musi byc zgodna z typem macierzy): ";
            cin >> temp;
            sm.addColXToY(firstColumn, secondColumn, temp);
            cout << sm << endl;
        } else if(ch == 'n') {
            sm.addColXToY(firstColumn, secondColumn);
            cout << sm << endl;
        }
    } else if(option == 6) {
        int row;
        T temp;
        cout << "Ktory wiersz: ";
        cin >> row;
        cout << "Jaka liczbe (musi byc zgodna z typem macierzy): ";
        cin >> temp;
        sm.multiplyRowXByY(row, temp);
        cout << sm << endl;
    } else if(option == 7) {
        int column;
        T temp;
        cout << "Ktora kolumna: ";
        cin >> column;
        cout << "Jaka liczbe (musi byc zgoda z typem macierzy): ";
        cin >> temp;
        sm.multiplyColXByY(column, temp);
        cout << sm << endl;
    } else if(option == 8) {
        int firstRow, secondRow;
        cout << "Ktory wiersz od ktorego? ";
        cin >> firstRow >> secondRow;
        sm.subtractRowXFromY(firstRow, secondRow);
        cout << sm << endl;
    } else if(option == 9) {
        int firstColumn, secondColumn;
        cout << "Ktora kolumna od ktorej? ";
        cin >> firstColumn >> secondColumn;
        sm.subtractColXFromY(firstColumn, secondColumn);
        cout << sm << endl;
    } else if(option == 10) {
        SquareMatrix<T, N> newMatrix;
        cout << "Podaj druga macierz (o tych samych wymiarach i typie danych co pierwsza):" << endl;
        cin >> newMatrix;
        cout << "Wynik dodawania:" << endl;
        cout << sm+newMatrix << endl;
    } else if(option == 11) {
        T temp;
        cout << "Podaj liczbe (musi byc zgodna z typem macierzy): ";
        cin >> temp;
        cout << "Wynik dodawania:" << endl;
        sm = sm+temp;
        cout << sm << endl;
    } else if(option == 12) {
        SquareMatrix<T, N> newMatrix;
        cout << "Podaj druga macierz (o tych samych wymiarach i typie danych co pierwsza):" << endl;
        cin >> newMatrix;
        cout << "Wynik odejmowania:" << endl;
        cout << sm-newMatrix << endl;
    } else if(option == 13) {
        T temp;
        cout << "Podaj liczbe (musi byc zgodna z typem macierzy): ";
        cin >> temp;
        cout << "Wynik odejmowania:" << endl;
        sm = sm+temp;
        cout << sm << endl;
    } else if(option == 14) {
        SquareMatrix<T, N> newMatrix;
        cout << "Podaj druga macierz (o tych samych wymiarach i typie danych co pierwsza):" << endl;
        cin >> newMatrix;
        cout << "Wynik mnozenia:" << endl;
        cout << sm*newMatrix << endl;
    } else if(option == 15) {
        SquareMatrix<T, N> newMatrix;
        cout << "Podaj druga macierz (o tych samych wymiarach i typie danych co pierwsza):" << endl;
        cin >> newMatrix;
        if(sm == newMatrix) {
            cout << "Sa to te same macierze." << endl;
        } else {
            cout << "Sa to dwie inne macierze." << endl;
        }
    } else if(option == 16) {
        cout << "Macierz gorno-schodkowa:" << endl;
        cout << sm.upperStepped() << endl;
    } else if(option == 17) {
        cout << "Wyznacznik macierzy wynosi: " << sm.determinant() << endl;
    } else if(option == 18) { /// POPRAWIC
        cout << "Macierz odwrotna do podanej: " << endl;
        if(sm.determinant() == T(0)) {
            cout << "Nie mozna wyznaczyc macierzy odwrotnej do macierzy, ktorej wyznacznik jest rowny 0." << endl;
        } else {
            cout << sm.algebraicComplement().transpose() * (T(1)/sm.determinant()) << endl;
        }
    }
}
