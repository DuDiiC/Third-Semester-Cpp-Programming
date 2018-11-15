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
