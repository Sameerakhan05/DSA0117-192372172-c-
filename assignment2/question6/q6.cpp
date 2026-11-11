
#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend inline int minutesBetween(
        const Time& a, const Time& b);

    friend inline bool earlier(
        const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;

    return abs(first - second);
}

inline bool earlier(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;

    return first < second;
}

int main() {
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << minutesBetween(departure, arrival)
         << " "
         << boolalpha
         << earlier(arrival, departure)
         << endl;

    Time morning(10, 30);
    Time afternoon(14, 15);

    cout << "Difference: "
         << minutesBetween(morning, afternoon)
         << " minutes" << endl;

    cout << "Same time difference: "
         << minutesBetween(morning, morning)
         << " minutes" << endl;

    return 0;
}

