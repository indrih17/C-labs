#include <iostream>
#include "math.h"

double someFunction(double a, double b, double c, int x) {
    if (x < 5 && c != 0)
        return (-a) * pow(x, 2.0) - b;
    else if (x > 5 && c == 0)
        return (x - a) / x;
    else
        return (-x) / c;
}

int main() {
    double a, b, c; 
    int x;
    std::cout << "Enter the value of the first variable: "; std::cin >> a;
    std::cout << "Enter the value of the second variable: "; std::cin >> b;
    std::cout << "Enter the value of the third variable: "; std::cin >> c;
    std::cout << "Enter the value of the fourth variable: "; std::cin >> x;
    std::cout << "Result: " << someFunction(a, b, c, x) << std::endl;

    return 0;
}
