// Given an integer. Calculate the sum of digits of that number.

#include <iostream>

int sumOfDigits(int number) {
    int result = 0;
    while (number != 0) {
        result += number % 10;
        number /= 10;
    }
    return result;
}

int main() {
    std::cout << "Enter the number: ";
    int number;
    std::cin >> number;
    std::cout << "The sum of digits of the number is " << sumOfDigits(number) << std::endl;
    return 0;
}