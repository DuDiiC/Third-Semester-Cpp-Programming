#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool ROOT = true;

class Trie {

public:
    vector < Trie > root;
    bool isEnd;
    char letter;

    Trie(char letter, bool isEnd = false) {
        this->letter = letter;
        this->isEnd = isEnd;
    }

    int isInBranch(char letter, vector <Trie> &newRoot) {
        for(int i = 0; i < newRoot.size(); i++) {
            if(newRoot[i].letter == letter) {
                return i;
            }
        }
        return -1;
    }

    void addChild(string word, vector < Trie > &newRoot) {
        int position = isInBranch(word[0], newRoot);
        if(position == -1) {
            if(word.size() == 1) {
                Trie newTrie(word[0], true);
                newRoot.push_back(newTrie);
                return;
            } else {
                Trie newTrie(word[0]);
                newRoot.push_back(newTrie);
                addChild(word.erase(0, 1), newRoot[newRoot.size()-1].root);
            }
        } else {
            if(word.size() == 1) {
                newRoot[position].isEnd = true;
                return;
            }
            addChild(word.erase(0, 1), newRoot[position].root);
        }
    }

    friend int howMuchSteps(Trie &t, string w, int temp);
};

int howMuchSteps(Trie &t, string w, int temp) {
    if(ROOT) { // poczatek
        ROOT = false;
        if(w.size() == 1) { // slowo jednoliterowe - w tym momencie nie ma znaczenia czy rozgalezienie jest czy nie, i tak trzeba te pierwsza litere wpisac
            temp++;
            return temp;
        } else { // slowo dluzsze niz jedna litera
            if(t.root.size() > 1) { // wiecej niz jeden lisc
                int position = t.isInBranch(w[0], t.root);
                temp++;
                return howMuchSteps(t.root[position], w.erase(0,1), temp);
            } else { // jeden lisc tylko
                temp++;
                return howMuchSteps(t.root[0], w.erase(0,1), temp);
            }
        }
    } else { // nie poczatek
        if(w.size() == 1) { // slowo jednoliterowe
            if(t.root.size() > 1 || t.isEnd == true) { // mamy rozgalezienie, albo koniec jakiegos slowa
                temp++;
                return temp;
            } else { // nic z tych rzeczy :-)
                return temp;
            }
        } else { // slowo dluzsze niz jedna litera
            if(t.root.size() > 1) { // mamy rozgalezienie
                int position = t.isInBranch(w[0], t.root);
                temp++;
                return howMuchSteps(t.root[position], w.erase(0,1), temp);
            } else if(t.isEnd == true) { // nie mamy rozgalezienia, ale za to jest koniec jakiegos slowa
                temp++;
                return howMuchSteps(t.root[0], w.erase(0,1), temp);
            } else { // nic z tych rzeczy :-)
                return howMuchSteps(t.root[0], w.erase(0,1), temp);
            }
        }
    }
}

int main() {

    int numberOfWords;
    string word;

    while(cin >> numberOfWords) {

        // create Trie and root
        Trie T(NULL);
        vector <string> words;

        for(int i = 0; i < numberOfWords; i++) {
            cin >> word;
            // add word to Trie
            words.push_back(word);
            T.addChild(word, T.root);
            ROOT = true;
        }

        int sum = 0;
        for(int i = 0; i < words.size(); i++) {
            sum += howMuchSteps(T, words[i], 0);
            cout << howMuchSteps(T, words[i], 0) << endl;
        }

        double result = (double)sum/(double)words.size();

        cout.precision(2);
        cout << fixed;
        cout <<  result <<  endl;
    }

    return 0;
}
