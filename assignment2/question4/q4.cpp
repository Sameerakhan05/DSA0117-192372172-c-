
#include <iostream>
using namespace std;

class SavingsAccount {
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;

    void addTransaction(double amount) {
        if (count < 10) {
            transactions[count] = amount;
            count++;
        } else {
            for (int i = 0; i < 9; i++) {
                transactions[i] = transactions[i + 1];
            }
            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(int acc, double initial) {
        accountNumber = acc;
        balance = initial;
        count = 0;
    }

    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement();
};

void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        addTransaction(amount);
        cout << "Deposited: Rs " << amount << endl;
    }
}

void SavingsAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        addTransaction(-amount);
        cout << "Withdrawn: Rs " << amount << endl;
    } else {
        cout << "Insufficient balance or invalid amount\n";
    }
}

void SavingsAccount::miniStatement() {
    cout << "\nAccount Number: " << accountNumber << endl;
    cout << "Balance: Rs " << balance << endl;
    cout << "Last Transactions:\n";

    for (int i = 0; i < count; i++) {
        cout << transactions[i] << endl;
    }
}

int main() {
    SavingsAccount account(12345, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);

    account.miniStatement();

    return 0;
}

