
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
    int hour;

    cout << "METRO INPUT VALIDATION" << endl;
    cout << "Enter travel hour (0-23): ";

    while (!(cin >> hour))
    {
        cout << "Invalid input! Enter a number: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (hour < 0 || hour > 23)
    {
        cout << "Invalid hour!" << endl;
        return 0;
    }

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    cout << "Travel hour: " << hour << endl;
    cout << "Peak hour: " << boolalpha << peak << endl;

    long long fare = 3600;

    cout << "Journey fare: Rs "
         << fare / 100 << "."
         << setw(2) << setfill('0')
         << fare % 100 << endl;

    return 0;
}

