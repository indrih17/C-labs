/**
    Given an array of N integer elements.
    Find the minimal positive element.
    Calculate the sum of positive and multiple of three elements.
    Display non-zero elements.
*/

#include <iostream>

int minPositiveElem(int* arr, int size) {
    int min = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && (arr[i] < min || min == 0)) {
            min = arr[i];
        }
    }
    return min;
}

int sumOfPositiveAndMutlipleOfThreeElements(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && arr[i] % 3 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

std::string nonZeroElements(int* arr, int size) {
    std::string result = "";
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            result += std::to_string(arr[i]) + " ";
        }
    }
    if (result == "") {
        result = "array does not contain non-zero elements.";
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
        std::cout << "Enter the " << i+1 << " element: ";
        std::cin >> arr[i];
    }
    // end of array creation

    int min = minPositiveElem(arr, size);
    if (min == 0) {
        std::cout << "The array does not contain positive elements." << std::endl;
    } else {
        std::cout << "The minimal positive element - " << min << std::endl;
    }

    int sum = sumOfPositiveAndMutlipleOfThreeElements(arr, size);
    std::cout << "The sum of positive elements that are multiples of three - " << sum << std::endl;

    std::cout << "Non-zero elements: " << nonZeroElements(arr, size) << std::endl;
    return 0;
}