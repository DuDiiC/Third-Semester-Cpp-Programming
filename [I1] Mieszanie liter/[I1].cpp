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
            Word w(oneWord);
            bool belong = false;
            for(int j = 0; j < dictionary[w.word.size()-1].size(); j++) {
                if(w == dictionary[w.word.size()-1][j]) {
                    belong = true;
                }
            }
            if(!belong)
                dictionary[oneWord.size()-1].push_back(w);
        }

        // test output
        /*for(int i = 0; i < dictionary.size(); i++) {
            for(int j = 0; j < dictionary[i].size(); j++) {
                cout << dictionary[i][j] << " ";
            }
        }
        cout << endl;*/

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
            Word w(oneWord);
            words.push_back(w);
        }

        // test output
        /*for(int i = 0; i < words.size(); i++) {
            cout << words[i] << " ";
        }
        cout << endl;*/

        // output
        for(int i = 0; i < words.size(); i++) {
            bool belong = false;
            for(int j = 0; j < dictionary[words[i].word.size()-1].size(); j++) {
                if(words[i] == dictionary[words[i].word.size()-1][j]) {
                    belong = true;
                    cout << dictionary[words[i].word.size()-1][j] << " ";
                    break;
                }
            }
            if(!belong) cout << words[i] << " ";
        }
        cout << endl;

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
