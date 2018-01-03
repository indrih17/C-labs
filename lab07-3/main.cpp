/**
    Given an array of N integer elements.
    Find the maximal element.
    Calculate the sum of even elements.
    Display the negative elements in reverse order.
*/

#include <iostream>
#include <math.h>

int maxElement(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int sumOfEvenElements(int* arr, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        if (!(arr[i] & 1)) {
            result += arr[i];
        }
    }
    return result;
}

std::string negativeElementsInReverseOrder(int* arr, int size) {
    std::string result = "";
    for (int i = size-1; i > -1; i--) {
        if (arr[i] < 0) {
            result += std::to_string(arr[i]) + " ";
        }
    }
    if (result == "") {
        result = "the array contains no negative elements";
    }
    return result;
}


//*******************MAIN FUNCTION**************************

int main() {
    // start of array creation
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size < 1) {
        std::cerr << "The size of the array is less than 1." << std::endl;
        std::cerr << "The array will not be created." << std::endl;
        return -1;
    }

    int arr[size];

    for (int i = 0; i < size; i++) {
        std::cout << "Enter the " << i+1 << "th element: ";
        std::cin >> arr[i];
    }
    // end of array creation

    std::cout << "Maximal element - " << maxElement(arr, size) << std::endl;

    std::cout << "The sum of even elements - " << sumOfEvenElements(arr, size) << std::endl;

    std::string tmp = negativeElementsInReverseOrder(arr, size);
    std::cout << "The negative elements in reverse order: " << tmp << std::endl;
    return 0;
}