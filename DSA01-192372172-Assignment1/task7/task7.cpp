
#include <iostream>
using namespace std;

// PROCEDURAL APPROACH
long long balance = 10000;
const long long MIN_BALANCE = 5000;

bool proceduralCanTravel(long long fare)
{
    return balance - fare >= MIN_BALANCE;
}

void proceduralDeduct(long long fare)
{
    if (proceduralCanTravel(fare))
    {
        balance -= fare;
        cout << "Journey Allowed";
    }
    else
    {
        cout << "Journey Denied";
    }

    cout << " | Balance: Rs " << balance / 100 << endl;
}

// OBJECT-ORIENTED APPROACH
class SmartCard
{
private:
    long long balance;

public:
    SmartCard(long long b)
    {
        balance = b;
    }

    bool canTravel(long long fare)
    {
        return fare >= 0 &&
               balance >= fare &&
               balance - fare >= MIN_BALANCE;
    }

    void deduct(long long fare)
    {
        if (canTravel(fare))
        {
            balance -= fare;
            cout << "Journey Allowed";
        }
        else
        {
            cout << "Journey Denied";
        }

        cout << " | Balance: Rs " << balance / 100 << endl;
    }
};

int main()
{
    cout << "PROCEDURAL APPROACH" << endl;
    proceduralDeduct(3000);
    proceduralDeduct(6000);

    cout << "\nOBJECT ORIENTED APPROACH" << endl;

    SmartCard card(10000);

    card.deduct(3000);
    card.deduct(6000);

    return 0;
}

