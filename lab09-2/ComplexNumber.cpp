#include <iostream>
#include "ComplexNumber.h"

ComplexNumber createComplexNumber() {
    ComplexNumber number;
    std::cout << "\nCreating a new complex number.\n";
    std::cout << "Enter the real part: ";
    std::cin >> number.realPart;
    std::cout << "Enter the imaginary part: ";
    std::cin >> number.imaginaryPart;

    return number;
}

void print(ComplexNumber number) {
    std::cout << "(" << number.realPart << ", " << number.imaginaryPart << ")";
}

ComplexNumber multiplication(ComplexNumber first, ComplexNumber second) {
    ComplexNumber result;
    result.realPart = first.realPart*first.imaginaryPart - second.realPart*second.imaginaryPart;
    result.imaginaryPart = first.realPart*second.imaginaryPart + first.imaginaryPart*second.realPart;
    return result;  
}
