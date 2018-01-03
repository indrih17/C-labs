/**
    Given an array of N integer elements.
    Find the minimal element.
    Calculate the product of negative elements in the array
*/

#include <iostream>

int findMinElem(int* arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int sumOfElements(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

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
        std::cout << "Enter the " << i+1 << " element: ";
        std::cin >> arr[i];
    }
    // end of array creation

    int min = findMinElem(arr, size);
    std::cout << "Minimal element: " << min << std::endl;

    int sum = sumOfElements(arr, size);
    std::cout << "Sum of array elements: " << sum << std::endl;
    
    // memory clearing
    delete [] arr;
    return 0;
}