#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int iloscTrunkow;
    int numerTestu = 1;

    while(cin >> iloscTrunkow) {

        /// wczytanie danych do mapy
        map < int, string > napoje;
        for(int i = 0; i < iloscTrunkow; i++) {
            cin >> napoje[i];
        }

        /// tworze graf
        vector < vector < int > > graf;
        for(int i = 0; i < iloscTrunkow; i++) {
            vector < int > temp;
            graf.push_back(temp);
        }

        int iloscPar;
        cin >> iloscPar;
        for(int i = 0; i < iloscPar; i++) {
            string napoj1, napoj2;
            cin >> napoj1 >> napoj2;

            /// tworze graf jako liste sasiadow - dla kazdego wierzcholka mam liste do niego WCHODZACYCH
            for(int j = 0; j < iloscTrunkow; j++) {
                if(napoje[j] == napoj2) {
                    for(int k = 0; k < iloscTrunkow; k++) {
                        if(napoje[k] == napoj1) {
                            /// nie wrzucac krawedzi po raz drugi
                            bool nieMa = true;
                            for(int m = 0; m < graf[j].size(); m++) {
                                if(graf[j][m] == k) {
                                    nieMa = false;
                                    break;
                                }
                            }
                            if(nieMa) graf[j].push_back(k);
                            break;
                        }
                    }
                    break;
                }
            }
        }

        /// komunikat
        cout << "Case #" << numerTestu++ << ": Dilbert should drink beverages in this order:";

        /// SORTOWANIE TOPOLOGICZNE GRAFU NA KOLEJCE
        queue < int > zeroweStopnie;
        bool juzOdwiedzone[iloscTrunkow];
        bool juzWKolejce[iloscTrunkow];
        for(int i = 0; i < iloscTrunkow; i++) {
            juzOdwiedzone[i] = false;
            juzWKolejce[i] = false;
        }

        /// wrzucam wszystkie zerowe na poczatek
        for(int i = 0; i < graf.size(); i++) {
            if(!graf[i].size()) {
                zeroweStopnie.push(i);
                juzWKolejce[i] = true;
                break;
            }
        }

        /// zaczynamy sortowanie
        while(!zeroweStopnie.empty()) {
            /// ustalam pozycje na pierwszy wierzcholek stopnia 0
            int badanyWierzcholek = zeroweStopnie.front();
            juzOdwiedzone[badanyWierzcholek] = true;
            /// wypisuje ten wierzcholek
            cout << " " << napoje[badanyWierzcholek];
            /// usuwam wszystkie powiazania z tym wierzcholkiem z innych wierzcholkow
            for(int i = 0; i < graf.size(); i++) {
                if(i != badanyWierzcholek) {
                    for(int j = 0; j < graf[i].size(); j++) {
                        if(graf[i][j] == badanyWierzcholek) {
                            vector < int >::iterator it = graf[i].begin()+j;
                            graf[i].erase(it);
                            break;
                        }
                    }
                }
            }
            /// usuwam badany wierzcholek z kolejki
            zeroweStopnie.pop();
            /// dodaje wszystkie wierzcholki zerowe po tych operacjach i przechodze do nastepnej iteracji
            for(int i = 0; i < graf.size(); i++) {
                if((juzOdwiedzone[i] == false) && (juzWKolejce[i] == false) && (graf[i].size() == 0)) {
                    zeroweStopnie.push(i);
                    juzWKolejce[i] = true;
                    break;
                }
            }
        }

        cout << "." << endl;


    }

    return 0;
}

