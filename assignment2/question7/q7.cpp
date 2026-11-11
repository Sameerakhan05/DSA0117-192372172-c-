
#include <iostream>
using namespace std;

const int SIZE = 10;
const int N = 1000;

// Original shifting approach
class ShiftingBuffer {
    int data[SIZE];
    int count;
    long long operations;

public:
    ShiftingBuffer() {
        count = 0;
        operations = 0;
    }

    void add(int value) {
        if (count < SIZE) {
            data[count] = value;
            count++;
            operations++;
        } else {
            for (int i = 0; i < SIZE - 1; i++) {
                data[i] = data[i + 1];
                operations++;
            }

            data[SIZE - 1] = value;
            operations++;
        }
    }

    void display() {
        for (int i = 0; i < count; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    long long getOperations() {
        return operations;
    }
};

// Redesigned circular buffer
class CircularBuffer {
    int data[SIZE];
    int start;
    int count;
    long long operations;

public:
    CircularBuffer() {
        start = 0;
        count = 0;
        operations = 0;
    }

    void add(int value) {
        int position = (start + count) % SIZE;

        if (count == SIZE) {
            position = start;
            start = (start + 1) % SIZE;
        } else {
            count++;
        }

        data[position] = value;
        operations++;
    }

    void display() {
        for (int i = 0; i < count; i++) {
            cout << data[(start + i) % SIZE] << " ";
        }
        cout << endl;
    }

    long long getOperations() {
        return operations;
    }
};

int main() {
    ShiftingBuffer oldBuffer;
    CircularBuffer newBuffer;

    for (int i = 1; i <= N; i++) {
        oldBuffer.add(i);
        newBuffer.add(i);
    }

    cout << "ORIGINAL SHIFTING BUFFER\n";
    cout << "Latest transactions: ";
    oldBuffer.display();

    cout << "Array assignments: "
         << oldBuffer.getOperations() << endl;

    cout << "\nREDESIGNED CIRCULAR BUFFER\n";
    cout << "Latest transactions: ";
    newBuffer.display();

    cout << "Array assignments: "
         << newBuffer.getOperations() << endl;

    return 0;
}

