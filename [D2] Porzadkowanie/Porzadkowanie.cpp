#include <iostream>
#include <vector>
#include <utility>
using namespace std;

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

        getline(cin, lineWithRules);

        for(int i = 0; i < lineWithRules.size(); i += 4) {
            rules.push_back(make_pair(lineWithRules[i], lineWithRules[i+2]));
        }

        numberOfRules = rules.size();

        cout << endl;
    }

    return 0;
}
