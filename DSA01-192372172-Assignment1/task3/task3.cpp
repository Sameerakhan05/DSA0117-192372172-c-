
#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    cout << "METRO DATA TYPE ANALYSIS" << endl;

    cout << "\nDATA TYPE SIZES" << endl;
    cout << "Size of bool: " << sizeof(bool) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;

    cout << "\nINTEGER LIMITS" << endl;
    cout << "INT MIN: " << INT_MIN << endl;
    cout << "INT MAX: " << INT_MAX << endl;

    int a = 10;
    double b = 2.5;
    double result = a + b;

    cout << "\nTYPE COMPATIBILITY" << endl;
    cout << "10 + 2.5 = " << result << endl;

    cout << "\nMONEY PRECISION COMPARISON" << endl;

    double rupees = 0.0;
    long long paise = 0;

    for (int i = 0; i < 10; i++)
    {
        rupees += 0.1;
        paise += 10;
    }

    cout << setprecision(17);
    cout << "Double total: " << rupees << " rupees" << endl;
    cout << "Integer total: " << paise << " paise" << endl;
    cout << "Integer total in rupees: "
         << paise / 100.0 << endl;

    return 0;
}

