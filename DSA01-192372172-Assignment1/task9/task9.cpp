
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const long long MIN_BALANCE = 5000;

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

bool getFare(int zone, int hour, long long &fare) {
    if (hour < 0 || hour > 23)
        return false;

    long long base;

    switch (zone) {
        case 1: base = 1000; break;
        case 2: base = 2000; break;
        case 3: base = 3000; break;
        default: return false;
    }

    fare = base;

    if (isPeak(hour))
        fare += base * 20 / 100;

    return true;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance >= fare &&
           balance - fare >= MIN_BALANCE;
}

void printMoney(long long paise) {
    cout << "Rs " << paise / 100 << "."
         << setw(2) << setfill('0') << paise % 100
         << setfill(' ');
}

int main() {
    long long balance = 10000;
    long long fare;

    int zones[] = {1, 2, 3, 1, 2};
    int hours[] = {7, 8, 10, 17, 20};

    cout << "METRO SMART CARD SYSTEM\n";

    for (int i = 0; i < 5; i++) {
        cout << "\nJourney " << i + 1 << ": ";

        if (!getFare(zones[i], hours[i], fare)) {
            cout << "Invalid journey\n";
            continue;
        }

        cout << "Fare = ";
        printMoney(fare);

        if (canTravel(balance, fare)) {
            balance -= fare;
            cout << " | Allowed";
        } else {
            cout << " | Denied";
        }

        cout << " | Balance = ";
        printMoney(balance);
        cout << endl;
    }

    cout << "\nInvalid zone test: ";
    if (!getFare(99, 10, fare))
        cout << "Rejected\n";

    cout << "Negative recharge test: ";
    long long recharge = -500;

    if (recharge < 0)
        cout << "Rejected\n";

    cout << "Invalid hour test: ";
    if (25 < 0 || 25 > 23)
        cout << "Rejected\n";

    int inputHour;
    cout << "Enter hour to test letter input: ";

    if (!(cin >> inputHour)) {
        cout << "Rejected invalid input\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}

