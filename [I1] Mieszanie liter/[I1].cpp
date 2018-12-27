#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cstdio>
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

vector < Word > getTestLine(char str[]);
vector < vector < Word > > getDictionaryLine(char s[]);

int main() {

    char str[10000];
    gets(str);
    while(gets(str)) {

        // create dictionary
        vector < vector < Word > > dictionary = getDictionaryLine(str);

        // test output
        /*for(int i = 0; i < dictionary.size(); i++) {
            for(int j = 0; j < dictionary[i].size(); j++) {
                cout << dictionary[i][j] << " ";
            }
        }
        cout << endl;*/

        // read words to recode
        gets(str);
        vector < Word > words = getTestLine(str);

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

vector < Word > getTestLine(char str[]) {

    stringstream textStream(str);
    string temp;
    vector < Word > test;

    while(textStream >> temp) {
        Word w(temp);
        test.push_back(w);
    }

    return test;
}

vector < vector < Word > > getDictionaryLine(char s[]) {

    stringstream textStream(s);
    string temp;
    vector < vector < Word > > dic;
    for(int i = 0; i <= 200; i++) {
        vector < Word > w;
        dic.push_back(w);
    }

    while(textStream >> temp) {
        Word w(temp);
        bool belong = false;
        for(int i = 0; i < dic[temp.size()-1].size(); i++) {
            if(w == dic[temp.size()-1][i]) {
                belong = true;
                break;
            }
        }
        if(!belong) {
            dic[temp.size()-1].push_back(w);
        }
    }

    return dic;
}
