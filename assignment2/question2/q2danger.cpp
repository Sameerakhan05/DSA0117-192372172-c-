
#include <iostream>
using namespace std;

int& dangerousFunction() {
    int value = 50;
    return value;
}

int main() {
    cout << "Returning reference to local variable is unsafe."
         << endl;
    return 0;
}

