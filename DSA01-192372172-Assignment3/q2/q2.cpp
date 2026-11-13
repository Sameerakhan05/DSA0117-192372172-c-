
#include <iostream>
#include <string>
using namespace std;

class MedicineList {
private:
    int count;
    string* medicines;

public:
    
    MedicineList(int n) {
        count = n;
        medicines = new string[count];

        for (int i = 0; i < count; i++) {
            medicines[i] = "Medicine " + to_string(i + 1);
        }
    }

    
    MedicineList(const MedicineList& other) {
        count = other.count;
        medicines = new string[count];

        for (int i = 0; i < count; i++) {
            medicines[i] = other.medicines[i];
        }
    }

    
    MedicineList& operator=(const MedicineList& other) {
        if (this != &other) {
            delete[] medicines;

            count = other.count;
            medicines = new string[count];

            for (int i = 0; i < count; i++) {
                medicines[i] = other.medicines[i];
            }
        }
        return *this;
    }

    void changeMedicine(int index, string name) {
        if (index >= 0 && index < count) {
            medicines[index] = name;
        }
    }

    void display() const {
        for (int i = 0; i < count; i++) {
            cout << medicines[i] << endl;
        }
    }

    
    ~MedicineList() {
        delete[] medicines;
    }
};

int main() {
    MedicineList list1(3);

    cout << "Original Medicine List:" << endl;
    list1.display();

    MedicineList list2 = list1;

    cout << "\nCopied Medicine List:" << endl;
    list2.display();

    list1.changeMedicine(0, "Paracetamol");

    cout << "\nAfter Changing Original List:" << endl;

    cout << "Original List:" << endl;
    list1.display();

    cout << "\nCopied List:" << endl;
    list2.display();

    return 0;
}

