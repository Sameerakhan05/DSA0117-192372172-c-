
#include <iostream>
using namespace std;

const long long MIN_BALANCE = 5000;

enum class Zone {
    Inner = 1,
    Middle,
    Outer,
    Airport
};

class MonthlyPass {
private:
    int zone1, zone2;

public:
    MonthlyPass(int a, int b) {
        zone1 = a;
        zone2 = b;
    }

    bool isValid(int zone) {
        return zone == zone1 || zone == zone2;
    }
};

long long calculateFare(int zone, int hour, bool weekend) {
    long long base;

    switch (zone) {
        case 1: base = 1000; break;
        case 2: base = 2000; break;
        case 3: base = 3000; break;
        case 4: base = 6000; break;
        default: return -1;
    }

    if (weekend) {
        base = base - (base * 10 / 100);
    }
    else if ((hour >= 8 && hour < 10) ||
             (hour >= 17 && hour < 20)) {
        base = base + (base * 20 / 100);
    }

    return base;
}

void showMoney(long long amount) {
    cout << "Rs " << amount / 100 << ".";
    if (amount % 100 < 10) cout << "0";
    cout << amount % 100;
}

int main() {
    long long balance = 20000;
    MonthlyPass pass(1, 2);

    int zones[] = {1, 3, 4, 3};
    int hours[] = {9, 9, 12, 12};
    bool weekends[] = {false, true, true, false};

    cout << "ADVANCED METRO FARE SYSTEM\n";

    for (int i = 0; i < 4; i++) {
        int zone = zones[i];
        long long fare;

        cout << "\nJourney " << i + 1 << endl;

        if (pass.isValid(zone)) {
            fare = 0;
            cout << "Monthly Pass Applied\n";
        }
        else {
            fare = calculateFare(zone, hours[i], weekends[i]);

            if (fare < 0) {
                cout << "Invalid Zone\n";
                continue;
            }
        }

        cout << "Fare: ";
        showMoney(fare);

        if (fare >= 0 && balance - fare >= MIN_BALANCE) {
            balance -= fare;
            cout << "\nJourney Allowed\n";
        }
        else {
            cout << "\nJourney Denied\n";
        }

        cout << "Balance: ";
        showMoney(balance);
        cout << endl;
    }

    return 0;
}

