
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Money {
private:
    long long paise;

public:
    Money(long long p = 0) {
        paise = p;
    }

    // Addition operator
    Money operator+(const Money& other) const {
        return Money(paise + other.paise);
    }

    // Subtraction operator
    Money operator-(const Money& other) const {
        return Money(paise - other.paise);
    }

    // Addition assignment operator
    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }

    // Equality operator
    bool operator==(const Money& other) const {
        return paise == other.paise;
    }

    // Less-than operator
    bool operator<(const Money& other) const {
        return paise < other.paise;
    }

    // Output stream operator
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long amount = m.paise;
        if (amount < 0) {
            out << "-";
            amount = -amount;
        }

        out << "Rs " << amount / 100 << "."
            << setw(2) << setfill('0') << amount % 100;
        return out;
    }

    // Input stream operator: input amount in rupees
    friend istream& operator>>(istream& in, Money& m) {
        long double rupees;
        in >> rupees;
        m.paise = static_cast<long long>(round(rupees * 100));
        return in;
    }
};

int main() {
    Money m1(12500);
    Money m2(7500);

    Money total = m1 + m2;
    Money difference = m1 - m2;

    cout << "First Amount: " << m1 << endl;
    cout << "Second Amount: " << m2 << endl;
    cout << "Total Amount: " << total << endl;
    cout << "Difference: " << difference << endl;

    m1 += m2;
    cout << "After += : " << m1 << endl;

    cout << boolalpha;
    cout << "Are amounts equal? " << (m1 == m2) << endl;
    cout << "Is second amount smaller? " << (m2 < m1) << endl;

    Money entered;
    cout << "Enter an amount in rupees: ";
    cin >> entered;
    cout << "Entered Amount: " << entered << endl;

    return 0;
}

