// Calculate the square root of (x5-x4+|x3|)

#include <iostream>
#include <math.h>

int main() {
    int* x = new int;
    std::cout << "Enter the value of х: ";
    std::cin >> *x;

    int result = pow(*x, 5) - pow(*x, 4) + abs(pow(*x, 3));
    std::cout << "The square root of x^5 - x^4 + |x^3| = " << sqrt(result) << std::endl;
    delete x;
    return 0;
}