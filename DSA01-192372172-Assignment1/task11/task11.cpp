
#include <iostream>
using namespace std;

const long long MIN_BALANCE = 5000;

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long initialBalance) {
        balance = initialBalance;
    }

    bool canTravel(long long fare) {
        return fare >= 0 &&
               balance >= fare &&
               balance - fare >= MIN_BALANCE;
    }

    void deduct(long long fare) {
        if (canTravel(fare)) {
            balance -= fare;
            cout << "Journey Allowed\n";
        } else {
            cout << "Journey Denied\n";
        }
    }

    void showBalance() {
        cout << "Remaining Balance: Rs "
             << balance / 100 << "."
             << (balance % 100 < 10 ? "0" : "")
             << balance % 100 << endl;
    }
};

int main() {
    cout << "FINAL METRO SMART CARD DESIGN\n";

    SmartCard card(10000);

    cout << "\nInitial Balance: Rs 100.00\n";

    card.deduct(2400);
    card.showBalance();

    card.deduct(3000);
    card.showBalance();

    card.deduct(2000);
    card.showBalance();

    return 0;
}

