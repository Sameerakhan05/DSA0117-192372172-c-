
#include <iostream>
using namespace std;

int& highestMark(int marks[], int size) {
    int highest = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[highest]) {
            highest = i;
        }
    }

    return marks[highest];
}

const int& getMark(const int marks[], int index) {
    return marks[index];
}

int getCopy(const int marks[], int index) {
    return marks[index];
}

int main() {
    int marks[5] = {75, 88, 92, 81, 69};

    cout << "Original highest mark: "
         << highestMark(marks, 5) << endl;

    highestMark(marks, 5) += 2;

    cout << "After moderation: "
         << highestMark(marks, 5) << endl;

    cout << "Const reference value: "
         << getMark(marks, 0) << endl;

    cout << "Copied value: "
         << getCopy(marks, 1) << endl;

    return 0;
}

