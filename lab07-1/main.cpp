/**
    Given the length of circumference.
    Calculate the area of a circle bounded by this circle.
*/

#include <iostream>
#include <math.h>

int main() {
    float length;
    std::cout << "Enter the length of the circumference: ";
    std::cin >> length;

    float radius = length / (2 * M_PI);
    float area = M_PI * pow(radius, 2);
    std::cout << area << std::endl;
    return 0;
}