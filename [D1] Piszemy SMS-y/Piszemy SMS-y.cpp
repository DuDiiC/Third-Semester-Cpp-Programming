#include <iostream>
#include <vector>

using namespace std;


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

};

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
        }

        cout.precision(2);
        cout << /* result << */ endl;
    }

    return 0;
}
