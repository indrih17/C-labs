#include <iostream>
#include "ComplexNumber.h"

int main() {
    ComplexNumber first = createComplexNumber();
    ComplexNumber second = createComplexNumber();

    ComplexNumber third = multiplication(first, second);
    print(first);
    std::cout << " * ";
    print(second);
    std::cout << " = ";
    print(third);
    
    std::cout << std::endl;
    return 0;
}