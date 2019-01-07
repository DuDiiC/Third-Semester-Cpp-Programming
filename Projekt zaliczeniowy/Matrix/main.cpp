#include "headers.hpp"
#include "Matrix.hpp"
#include "SquareMatrix.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "Zp.hpp"

int main() {

    /// CREATE MATRIX FOR PRESENTATION
    SquareMatrix<int, 3> intMatrix1, intMatrix2; // dodawanie, wyznacznik
    Matrix<double, 2, 4> doubleMatrix1, doubleMatrix2; // odejmowanie, transponowanie (nie dziala wyznacznik, prawdopodobnie ta sama metoda co dla zespolonych zadziala)
    Matrix<Z<4>, 2, 3> zpMatrix1;
    Matrix<Z<4>, 3, 1> zpMatrix2; // mnozenie, operacje na wierszach
    SquareMatrix<Rational, 3> rationalMatrix1, rationalMatrix2; // wyznacznik, operacje na kolumnach
    SquareMatrix<Complex, 3> complexMatrix1, complexMatrix2; // wyznacznik, mnozenie przez liczbe

    /// GIVE THE MATRICES
    cout << "Wczytaj dwie macierze 3x3 przechowujace liczby calkowite" << endl;
    cin >> intMatrix1 >> intMatrix2;
    cout << "wczytalem" << endl;
    cout << "----------------------------" << endl;
    cout << "Wczytaj dwie macierze 2x4 przechowujace liczby zmiennoprzecinkowe" << endl;
    cin >> doubleMatrix1 >> doubleMatrix2;
    cout << "wczytalem" << endl;
    cout << "----------------------------" << endl;
    cout << "Wczytaj dwie macierze: jedna 2x3, druga 3x1 przechowujace liczby w ciele Z4" << endl;
    cin >> zpMatrix1 >> zpMatrix2;
    cout << "wczytalem" << endl;
    cout << "----------------------------" << endl;
    cout << "Wczytaj dwie macierze 3x3 przechowujace liczby rzeczywiste" << endl;
    cin >> rationalMatrix1 >> rationalMatrix2;
    cout << "wczytalem" << endl;
    cout << "----------------------------" << endl;
    cout << "Wczytaj dwie macierze 3x3 przechowujace liczby zespolone" << endl;
    cin >> complexMatrix1 >> complexMatrix2;
    cout << "wczytalem" << endl;
    cout << "----------------------------" << endl;

    /// PRESENTATION FOR INT
    cout << "Dodawanie macierzy liczb calkowitych" << endl;
    cout << intMatrix1+intMatrix2 << endl;
    cout << "Wyznacznik pierwszej macierzy to: " << intMatrix1.determinant() << endl;
    cout << "----------------------------" << endl;

    /// PRESENTATION FOR DOUBLE
    cout << "Odejmowanie macierzy liczb zmiennoprzecinkowych" << endl;
    cout << doubleMatrix1-doubleMatrix2 << endl;
    cout << "Macierz transponowana dla pierwszej macierzy" << endl;
    cout << doubleMatrix1.transpose() << endl;
    cout << "----------------------------" << endl;

    /// PRESENTATION FOR Zp
    cout << "Mnozenie macierzy w ciele Z4" << endl;
    cout << zpMatrix1*zpMatrix2 << endl;

    return 0;
}
