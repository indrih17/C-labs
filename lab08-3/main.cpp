/**
    To convert a matrix to contain only positive elements.
    Instead of remaining elements record 0.
*/

#include <iostream>

int** replaceNegElementsByZero(int** matrix, int size) {
    int** newMatr = new int*[size];

    for (int i = 0; i < size; i++) {
        newMatr[i] = new int[size];

        for (int j = 0; j < size; j++) {
            if (matrix[i][j] < 0) {
                newMatr[i][j] = 0;
            } else {
                newMatr[i][j] = matrix[i][j];
            }
        }
    }

    return newMatr;
}

int main() {
    // start of matrix creation
    int size;
    std::cout << "Enter the size of the matrix: ";
    std::cin >> size;

    if (size < 1) {
        std::cerr << "The size of the matrix is less than 1." << std::endl;
        std::cerr << "The matrix will not be created." << std::endl;
        return -1;
    }

    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];

        for (int j = 0; j < size; j++) {
            std::cout << "Enter the [" << i+1 << "][" << j+1 << "]"<< " element: ";
            std::cin >> matrix[i][j];
        }
    }
    // end of matrix creation

    int** newMatr = replaceNegElementsByZero(matrix, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            std::cout << newMatr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // memory clearing
    for (int i = 0; i < size; i++) {
        delete [] (newMatr[i]);
    }
    delete [] newMatr;
    
    for (int i = 0; i < size; i++) {
        delete [] (matrix[i]);
    }
    delete [] matrix;
    return 0;
}