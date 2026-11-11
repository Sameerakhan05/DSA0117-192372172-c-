
#include <iostream>
using namespace std;


double charge(double weight,
              bool express = false,
              bool insured = false) {
    double amount = weight * 50;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    return amount;
}


double charge(int grams) {
    return grams * 0.05;
}


int main() {
    cout << "Courier Charge Calculator\n";

    cout << "Call 1: " << charge(2) << endl;
    cout << "Call 2: " << charge(2.0) << endl;
    cout << "Call 3: " << charge(2.0f) << endl;
    cout << "Call 4: " << charge(2.0, true) << endl;
    cout << "Call 5: " << charge(2.0, false, true) << endl;
    cout << "Call 6: " << charge(2.0, true, true) << endl;

    return 0;
}

