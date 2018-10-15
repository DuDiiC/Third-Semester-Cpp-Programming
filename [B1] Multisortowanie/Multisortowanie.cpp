#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Czworka {
public:
    int pierwsza, druga, trzecia, czwarta, numer;
    static int ilosc;

    Czworka(int a, int b, int c, int d) {
        pierwsza = a;
        druga = b;
        trzecia = c;
        czwarta = d;
        ilosc++;
        numer = ilosc;
    }
};

bool sortowanie_pierwsze(Czworka i, Czworka j) {
    return i.pierwsza < j.pierwsza;
}

bool sortowanie_drugie(Czworka i, Czworka j) {
    return i.druga < j.druga;
}

bool sortowanie_trzecie(Czworka i, Czworka j) {
    return i.trzecia < j.trzecia;
}

bool sortowanie_czwarte(Czworka i, Czworka j) {
    return i.czwarta < j.czwarta;
}

bool sortowanie_numerow(Czworka i, Czworka j) {
    return i.numer < j.numer;
}

int Czworka::ilosc = 0;

int main() {

    int N, pierwsza, druga, trzecia, czwarta;

    cin >> N;
    vector < Czworka > czworki;

    for(int i = 0; i < N; i++) {
        cin >> pierwsza >> druga >> trzecia >> czwarta;

        Czworka robocza(pierwsza, druga, trzecia, czwarta);

        czworki.push_back(robocza);
    }

    sort(czworki.begin(), czworki.end(), sortowanie_pierwsze);
    for(int i = 0; i < N; i++) {
        cout << czworki[i].numer << " ";
    }
    cout << endl;

    sort(czworki.begin(), czworki.end(), sortowanie_numerow);

    sort(czworki.begin(), czworki.end(), sortowanie_drugie);
    for(int i = 0; i < N; i++) {
        cout << czworki[i].numer << " ";
    }
    cout << endl;

    sort(czworki.begin(), czworki.end(), sortowanie_numerow);


    sort(czworki.begin(), czworki.end(), sortowanie_trzecie);
    for(int i = 0; i < N; i++) {
        cout << czworki[i].numer << " ";
    }
    cout << endl;

    sort(czworki.begin(), czworki.end(), sortowanie_numerow);

    sort(czworki.begin(), czworki.end(), sortowanie_czwarte);
    for(int i = 0; i < N; i++) {
        cout << czworki[i].numer << " ";
    }
    cout << endl;


    return 0;
}
