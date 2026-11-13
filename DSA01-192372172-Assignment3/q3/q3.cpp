
#include <iostream>
using namespace std;

class SeatMap {
private:
    int rows;
    int cols;
    int** seats;

public:
    
    SeatMap(int r, int c) {
        rows = r;
        cols = c;

        seats = new int*[rows];

        for (int i = 0; i < rows; i++) {
            seats[i] = new int[cols];

            for (int j = 0; j < cols; j++) {
                seats[i][j] = 0;
            }
        }
    }

    void bookSeat(int r, int c) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            if (seats[r][c] == 0) {
                seats[r][c] = 1;
                cout << "Seat booked successfully!" << endl;
            } else {
                cout << "Seat already booked!" << endl;
            }
        } else {
            cout << "Invalid seat position!" << endl;
        }
    }

    void cancelSeat(int r, int c) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            seats[r][c] = 0;
            cout << "Booking cancelled!" << endl;
        } else {
            cout << "Invalid seat position!" << endl;
        }
    }

    void display() const {
        cout << "\nSeat Map (0 = Available, 1 = Booked):\n";

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
    }

    
    ~SeatMap() {
        for (int i = 0; i < rows; i++) {
            delete[] seats[i];
        }

        delete[] seats;

        cout << "Seat map memory released!" << endl;
    }
};

int main() {
    SeatMap theatre(3, 4);

    theatre.display();

    theatre.bookSeat(0, 1);
    theatre.bookSeat(1, 2);

    theatre.display();

    theatre.cancelSeat(0, 1);

    theatre.display();

    return 0;
}

