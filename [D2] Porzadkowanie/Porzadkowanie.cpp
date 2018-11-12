#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool goodPermutation(vector < char >, vector < pair < char, char > >);

int main() {

    string line, lineWithRules;

    while(getline(cin, line)) {

        vector < char > letters;
        vector < pair < char, char > > rules;
        int letterInAlphabet, numberOfRules;

        for(int i = 0; i < line.size(); i += 2) {
            letters.push_back(line[i]);
        }

        letterInAlphabet = letters.size();
        sort(letters.begin(), letters.end());

        getline(cin, lineWithRules);

        for(int i = 0; i < lineWithRules.size(); i += 4) {
            rules.push_back(make_pair(lineWithRules[i], lineWithRules[i+2]));
        }

        numberOfRules = rules.size();

        do {
            if(goodPermutation(letters, rules)) {
                for(int i = 0; i < letters.size(); i++) {
                    cout << letters[i];
                }
                cout << endl;
            }
        } while(next_permutation(letters.begin(), letters.end()));

        cout << endl;
    }

    return 0;
}

bool goodPermutation(vector < char > l, vector < pair < char, char > > r) {
    return true;
}
