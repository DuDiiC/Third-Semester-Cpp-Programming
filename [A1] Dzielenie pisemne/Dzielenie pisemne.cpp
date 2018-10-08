#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double A, B;
    cin >> A >> B;

    double iloczyn = A/B;

    cout << setw(14) << fixed << setprecision(3) << A/B << endl;

    cout << "----------" << endl;

    cout << setw(10) << hex << (int)A << ":" << oct << (int)B << endl;

    return 0;
}
