
#include <iostream>
using namespace std;

int main() {
    long long journeys[] = {20000, 500000, 3000000};
    long long farePaise = 3600;

    cout << "METRO PERFORMANCE ANALYSIS\n";
    cout << "Assumed fare per journey: Rs 36.00\n\n";

    for (int i = 0; i < 3; i++) {
        long long totalPaise = journeys[i] * farePaise;
        double totalDouble = journeys[i] * 36.0;

        cout << "Journeys: " << journeys[i] << endl;
        cout << "Integer paise total: "
             << totalPaise << " paise\n";
        cout << "Total amount: Rs "
             << totalPaise / 100 << endl;
        cout << "Double total: Rs "
             << totalDouble << endl;
        cout << "-------------------------\n";
    }

    cout << "Maximum 32-bit signed integer: 2147483647\n";
    cout << "3,000,000 journeys exceed 32-bit paise capacity.\n";

    return 0;
}

