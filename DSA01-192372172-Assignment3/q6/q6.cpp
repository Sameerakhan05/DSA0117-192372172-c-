
#include <iostream>
#include <cstring>
using namespace std;

class Text {
private:
    char* data;

public:
    // Constructor
    Text(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Deep copy constructor
    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy assignment operator
    Text& operator=(const Text& other) {
        if (this != &other) {
            char* newData = new char[strlen(other.data) + 1];
            strcpy(newData, other.data);

            delete[] data;
            data = newData;
        }
        return *this;
    }

    // Concatenation operator
    Text operator+(const Text& other) const {
        int length = strlen(data) + strlen(other.data);
        char* temp = new char[length + 1];

        strcpy(temp, data);
        strcat(temp, other.data);

        Text result(temp);
        delete[] temp;

        return result;
    }

    // Equality operator
    bool operator==(const Text& other) const {
        return strcmp(data, other.data) == 0;
    }

    // Inequality operator
    bool operator!=(const Text& other) const {
        return !(*this == other);
    }

    // Output stream operator
    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }
};

int main() {
    Text t1("Hello ");
    Text t2("World");

    Text t3 = t1 + t2;

    cout << "First Text: " << t1 << endl;
    cout << "Second Text: " << t2 << endl;
    cout << "Combined Text: " << t3 << endl;

    Text t4("Hello ");

    cout << boolalpha;
    cout << "t1 == t4: " << (t1 == t4) << endl;
    cout << "t1 != t2: " << (t1 != t2) << endl;

    t4 = t2;

    cout << "After Assignment: " << t4 << endl;

    // Self-assignment test
    t4 = t4;
    cout << "After Self Assignment: " << t4 << endl;

    return 0;
}

