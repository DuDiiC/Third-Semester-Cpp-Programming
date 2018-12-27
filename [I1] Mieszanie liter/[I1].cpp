#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Word {
public:
    string word;

    Word() {}
    Word(string w);

    friend bool operator==(const Word &w1, const Word &w2);
    friend ostream& operator<<(ostream &output, const Word &w);
    friend istream& operator>>(istream &input, Word &w);
};

int main() {

    string casesLine;
    getline(cin, casesLine);
    int cases = strtol(casesLine.c_str(), NULL, 10);

    while(cases--) {

        // read words to recode
        vector < Word > words;
        string testLine;
        getline(cin, testLine);
        for(int i = 0; i < testLine.size(); i++) {
            string oneWord = "";
            while(testLine[i] != ' ' && i < testLine.size()) {
                oneWord += testLine[i];
                i++;
            }
            bool belong = false;
            for(int j = 0; j < words.size(); j++) {
                if(oneWord == words[i]) belong = true;
            }
            if(!belong) words.push_back(oneWord);
        }

        // test output
        /*for(int i = 0; i < words.size(); i++) {
            cout << words[i] << " ";
        }
        cout << endl;*/

        // create dictionary
        vector < vector < Word > > dictionary;
        for(int i = 0; i <= 200; i++) {
            vector < Word > w;
            dictionary.push_back(w);
        }

        // read words into dictionary
        string dictionaryLine;
        getline(cin, dictionaryLine);
        for(int i = 0; i < dictionaryLine.size(); i++) {
            string oneWord = "";
            while(dictionaryLine[i] != ' ' && i < dictionaryLine.size()) {
                oneWord += dictionaryLine[i];
                i++;
            }
            dictionary[oneWord.size()].push_back(oneWord);
        }

        // test output
        /*for(int i = 0; i < dictionary.size(); i++) {
            for(int j = 0; j < dictionary[i].size(); j++) {
                cout << dictionary[i][j] << " ";
            }
        }
        cout << endl;*/

    }

    return 0;
}

bool operator==(const Word &w1, const Word &w2) {
    if(w1.word.size() == w2.word.size() &&
       w1.word[0] == w2.word[0] &&
       w1.word[w1.word.size()-1] == w2.word[w2.word.size()-1]) {
        return 1;
    }
    return 0;
}

ostream& operator<<(ostream &output, const Word &w) {
    output << w.word;
    return output;
}

istream& operator>>(istream &input, Word &w) {
    input >> w.word;
    return input;
}

Word::Word(string w) {
    this->word = w;
}
