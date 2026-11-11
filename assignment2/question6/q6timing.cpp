
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

inline int inlineAdd(int a, int b) {
    return a + b;
}

int normalAdd(int a, int b) {
    return a + b;
}

int main() {
    volatile long long result = 0;
    const int N = 10000000;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
        result += inlineAdd(i, 2);

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
        result += normalAdd(i, 2);

    auto end2 = high_resolution_clock::now();

    cout << "Inline time: "
         << duration_cast<milliseconds>(end1-start1).count()
         << " ms" << endl;

    cout << "Normal time: "
         << duration_cast<milliseconds>(end2-start2).count()
         << " ms" << endl;

    cout << "Result: " << result << endl;

    return 0;
}

