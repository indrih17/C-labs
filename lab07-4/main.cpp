/**
    Given an array of N integer random elements.
    Find the maximal element.
    Calculate the arithmetic mean of odd elements of the array.
    Display the negative elements.
*/

#include <iostream>
#include <math.h>
#include <cstdlib>

int maxElement(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

long double averageOfOddElements(int* arr, int size) {
    int count = 0, sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] & 1) {
            sum += arr[i];
            count++;
        }
    }

    long double average = 0;
    if (count > 0) {
        average = sum / count;
    }
    return average;
}

std::string negativeElements(int* arr, int size) {
    std::string result = "";
    for (int i = 0; i < size; i++) {
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
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
    // end of array creation
    
    std::cout << "Maximal element - " << maxElement(arr, size) << std::endl;

    std::cout << "Arithmetic mean of odd elements - " << averageOfOddElements(arr, size) << std::endl;

    std::cout << "The negative elements: " << negativeElements(arr, size) << std::endl;
    delete arr;
    return 0;
}