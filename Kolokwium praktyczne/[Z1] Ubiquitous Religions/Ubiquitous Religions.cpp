#include <iostream>
#include <vector>
using namespace std;

int prawdziwaReligia(int x, vector < int > &v) {

    /// jesli religia nie zgadza sie z indeksem, to byla juz wczesniej zmieniana, wiec trzeba szukac dalej
    if(x != v[x]) {
        v[x] = prawdziwaReligia(v[x], v);
        return v[x];
    } else {
        return x;
    }

}

bool taSamaReligia(int &x, int &y, vector < int > &v) {

    x = prawdziwaReligia(x, v);
    y = prawdziwaReligia(y, v);

    if(x != y) {
        v[x] = y;
        return false;
    } else return true;
}

int main() {

    int liczbaStudentow, liczbaPar;
    int numerTestu = 1;
    while(cin >> liczbaStudentow >> liczbaPar && (liczbaStudentow || liczbaPar)) {

        int liczbaReligii = liczbaStudentow;
        /// kazdy student ma religie o swoim numerze ( zaczynam od 1 )
        vector < int > religie;
        for(int i = 0; i <= liczbaStudentow; i++) {
            religie.push_back(i);
        }

        for(int i = 0; i < liczbaPar; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;

            /// jak jeszcze niezapisane jako ta sama religia to zmieniam
            if(!taSamaReligia(temp1, temp2, religie)) {
                liczbaReligii--;
            }
        }

        cout << "Case " << numerTestu++ << ": " << liczbaReligii << endl;
    }

    return 0;
}
