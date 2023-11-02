/*
Implement a class Complex which represents the Complex Number data type. Implement 
the following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.4. Overloaded << and >> to 
print and read Complex Numbers.
*/


#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructor with default values
    Complex(double real = 0, double imaginary = 0) : real(real), imaginary(imaginary) {}

    // Overloaded operator+ to add two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overloaded operator* to multiply two complex numbers
    Complex operator*(const Complex& other) const {
        return Complex((real * other.real) - (imaginary * other.imaginary), (real * other.imaginary) + (imaginary * other.real));
    }

    // Overloaded operator<< to print complex numbers
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        os << complex.real;
        if (complex.imaginary >= 0) {
            os << " + " << complex.imaginary << "i";
        } else {
            os << " - " << -complex.imaginary << "i";
        }
        return os;
    }

    // Overloaded operator>> to read complex numbers
    friend std::istream& operator>>(std::istream& is, Complex& complex) {
        std::cout << "Enter real part: ";
        is >> complex.real;
        std::cout << "Enter imaginary part: ";
        is >> complex.imaginary;
        return is;
    }
};

int main() {
    Complex a, b, result;
    
    std::cout << "Enter the first complex number:" << std::endl;
    std::cin >> a;

    std::cout << "Enter the second complex number:" << std::endl;
    std::cin >> b;

    result = a + b;
    std::cout << "Sum: " << result << std::endl;

    result = a * b;
    std::cout << "Product: " << result << std::endl;

    return 0;
}
