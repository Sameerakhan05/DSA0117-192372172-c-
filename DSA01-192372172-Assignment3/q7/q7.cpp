
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Real-only constructor
    Complex(double r) {
        real = r;
        imag = 0;
    }

    // Real and imaginary constructor
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    // Addition
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication
    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Division
    Complex operator/(const Complex& c) const {
        double denominator = c.real * c.real + c.imag * c.imag;

        if (denominator == 0) {
            throw invalid_argument("Division by zero complex number!");
        }

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    // Equality with tolerance
    bool operator==(const Complex& c) const {
        const double EPS = 1e-9;

        return fabs(real - c.real) < EPS &&
               fabs(imag - c.imag) < EPS;
    }

    // Output stream operator
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0) {
            out << " + " << c.imag << "i";
        } else {
            out << " - " << -c.imag << "i";
        }

        return out;
    }
};

int main() {
    try {
        Complex c1(4, 3);
        Complex c2(2, 1);

        cout << "First Complex Number: " << c1 << endl;
        cout << "Second Complex Number: " << c2 << endl;

        cout << "Addition: " << c1 + c2 << endl;
        cout << "Subtraction: " << c1 - c2 << endl;
        cout << "Multiplication: " << c1 * c2 << endl;
        cout << "Division: " << c1 / c2 << endl;

        cout << boolalpha;
        cout << "Are they equal? " << (c1 == c2) << endl;

        // Division by zero test
        Complex zero(0, 0);
        cout << "Testing division by zero:" << endl;
        cout << c1 / zero << endl;
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}

