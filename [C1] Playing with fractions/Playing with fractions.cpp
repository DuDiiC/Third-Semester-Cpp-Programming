#include "Rational.cpp"

bool flag = true;

string cleaning(string operation);
Rational createFraction(string &operation, int &p);
Rational additionSubtraction(string &operation, int &p);
Rational multiplicationDivision(string &operation, int &p);

int main() {

    string operation;

    while(getline(cin, operation)) {

        int position = 0;
        flag = true;
        operation = cleaning(operation);

        Rational result = additionSubtraction(operation, position);

        if(result.getNumerator() != 0 && result.getDenominator() == 0)
            flag = false;

        // print result
        if(flag) {
            cout << result << endl;
        } else {
            cout << "INVALID" << endl;
        }
    }

    return 0;
}

string cleaning(string operation) {
    string afterCleaning;
    int p = 0;
    while(p < operation.size()) {
        if(isdigit(operation[p]) || operation[p] == '|'
            || operation[p] == '+' || operation[p] == '-'
            || operation[p] == '*' || operation[p] == '/'
            || operation[p] == '(' || operation[p] == ')') {
            afterCleaning += operation[p];
        }
        p++;
    }
    return afterCleaning;
}

Rational createFraction(string &operation, int &p) {

    Rational frac;

    if(operation[p] == '(') {
        p++;
        frac = additionSubtraction(operation, p);
        p++;
        return frac;
    }

    while(p < operation.size() && isdigit(operation[p])) {
        frac.setNumerator(frac.getNumerator()*10 + operation[p] - '0');
        p++;
    }

    if(p < operation.size() && operation[p] == '|') { // if denominator != 1
        p++;
        frac.setDenominator(0);
        while(p < operation.size() && isdigit(operation[p])) {
            frac.setDenominator(frac.getDenominator()*10+operation[p]-'0');
            p++;
        }
        if(frac.getNumerator() != 0 && frac.getDenominator() == 0) {
            flag = false;
            return frac;
        }
        if(frac.getDenominator() != 0) frac.saveAsIrreducible();

    } else {
        frac.setDenominator(1);
    }

    return frac;
}
Rational additionSubtraction(string &operation, int &p) {

    Rational frac1 = multiplicationDivision(operation, p); // recursive
    Rational frac2;

    while(p < operation.size() && flag) {
        if(operation[p] == '+') {
            p++;
            frac2 = multiplicationDivision(operation, p);

            if(flag == false || frac2.getDenominator() == 0) { // invalid
                flag = false;
                return frac1; //no matter what it return
            }

            frac1 = frac1+frac2;

        } else if(operation[p] == '-') {
            p++;
            frac2 = multiplicationDivision(operation, p);

            if(flag == false || frac2.getDenominator() == 0) { // invalid
                flag = false;
                return frac1;
            }

            frac1 = frac1-frac2;

        } else break;
    }

    return frac1;
}

Rational multiplicationDivision(string &operation, int &p) {

    Rational frac1 = createFraction(operation, p); // recursive
    Rational frac2;

    while(p < operation.size() && flag) {
        if(operation[p] == '*') {
            p++;
            frac2 = createFraction(operation, p);

            if(flag == false || frac2.getDenominator() == 0) { // invalid
                flag = false;
                return frac1;
            }

            frac1 = frac1*frac2;

        } else if(operation[p] == '/') {
            p++;
            frac2 = createFraction(operation, p);

            if(flag == false || frac2.getDenominator() == 0) { // invalid
                flag = false;
                return frac1;
            }

            frac1 = frac1/frac2;

        } else break;
    }

    return frac1;
}
