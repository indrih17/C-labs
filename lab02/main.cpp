// Calculate y=|x-cos(x)|

#include <iostream>
#include "math.h"

int main() {
    int x;
    std::cout << "Enter the value of x: ";
    std::cin >> x;

    double result = abs(x - cos(x));

    std::cout << "Result: " << result << std::endl;
    return 0;
}