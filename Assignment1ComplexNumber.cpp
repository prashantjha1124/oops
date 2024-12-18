#include <iostream>
using namespace std;

class Complex {
public:
    int real;
    int imaginary;

    // Default constructor
    Complex() : real(0), imaginary(0) {
        cout << "Default constructor value: " << real << " + " << imaginary << "i" << endl;
    }

    // Parameterized constructor
    Complex(int r, int i) : real(r), imaginary(i) {}

    // Overloading the + operator
    Complex operator+(const Complex& b) const {
        return Complex(real + b.real, imaginary + b.imaginary);
    }

    // Overloading the * operator
    Complex operator*(const Complex& b) const {
        return Complex((real * b.real) - (imaginary * b.imaginary), (real * b.imaginary) + (imaginary * b.real));
    }

    // Friend function for overloading << operator
    friend ostream& operator<<(ostream& output, const Complex& m);

    // Friend function for overloading >> operator
    friend istream& operator>>(istream& input, Complex& m);
};

// Overloading the << operator
ostream& operator<<(ostream& output, const Complex& m) {
    output << m.real << " + " << m.imaginary << "i";
    return output;
}

// Overloading the >> operator
istream& operator>>(istream& input, Complex& m) {
    input >> m.real >> m.imaginary;
    return input;
}

int main() {
    Complex a;
    cout << "\nEnter first complex number (real and imaginary parts): ";
    cin >> a;

    Complex b;
    cout << "\nEnter second complex number (real and imaginary parts): ";
    cin >> b;

    cout << "\nFirst complex number: " << a << endl;
    cout << "\nSecond complex number: " << b << endl;

    Complex c = a + b;
    cout << "\nAddition result: " << c << endl;

    Complex d = a * b;
    cout << "\nMultiplication result: " << d << endl;

    return 0;
}
