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

    return 0;
}

