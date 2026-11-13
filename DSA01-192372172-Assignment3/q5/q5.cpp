
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Counter {
private:
    int value;

public:
    Counter(int v = 0) {
        value = v;
    }

    // Prefix increment
    Counter& operator++() {
        ++value;
        return *this;
    }

    // Postfix increment
    Counter operator++(int) {
        Counter old = *this;
        value++;
        return old;
    }

    bool operator==(const Counter& other) const {
        return value == other.value;
    }

    bool operator<(const Counter& other) const {
        return value < other.value;
    }

    int getValue() const {
        return value;
    }
};

class Playlist {
private:
    vector<string> songs;

public:
    Playlist(initializer_list<string> list) {
        songs = list;
    }

    // Non-const subscript operator
    string& operator[](int index) {
        if (index < 0 || index >= (int)songs.size()) {
            throw out_of_range("Invalid playlist index!");
        }
        return songs[index];
    }

    // Const subscript operator
    const string& operator[](int index) const {
        if (index < 0 || index >= (int)songs.size()) {
            throw out_of_range("Invalid playlist index!");
        }
        return songs[index];
    }

    int size() const {
        return (int)songs.size();
    }
};

int main() {
    Counter c(5);

    Counter old = c++;
    Counter current = ++c;

    cout << "Postfix old value: " << old.getValue() << endl;
    cout << "Current value: " << c.getValue() << endl;
    cout << "Prefix result: " << current.getValue() << endl;

    Playlist p = {"Song One", "Song Two", "Song Three"};

    cout << "\nPlaylist:" << endl;

    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << endl;
    }

    p[1] = "Updated Song";

    cout << "\nAfter Updating:" << endl;
    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << endl;
    }

    try {
        cout << p[5] << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}

