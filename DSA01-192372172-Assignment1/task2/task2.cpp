
#include <iostream>
using namespace std;


constexpr int INNER_FARE = 1000;
constexpr int MIDDLE_FARE = 2000;
constexpr int OUTER_FARE = 3000;

constexpr int PEAK_SURCHARGE = 20;
constexpr int MIN_BALANCE = 5000;


enum class Zone
{
    Inner,
    Middle,
    Outer
};

int main()
{
    cout << "METRO FARE DETAILS" << endl;

    cout << "Inner Zone Fare: Rs "
         << INNER_FARE / 100 << endl;

    cout << "Middle Zone Fare: Rs "
         << MIDDLE_FARE / 100 << endl;

    cout << "Outer Zone Fare: Rs "
         << OUTER_FARE / 100 << endl;

    cout << "Peak Surcharge: "
         << PEAK_SURCHARGE << "%" << endl;

    cout << "Minimum Balance: Rs "
         << MIN_BALANCE / 100 << endl;

    Zone selectedZone = Zone::Outer;

    cout << "Selected Zone: Outer" << endl;

    return 0;
}

