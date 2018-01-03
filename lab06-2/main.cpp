/**
    Given a matrix of random elements.
    Determine whether there is a row in this array that contains
    more positive elements than a negative one.
*/

#include <iostream>
#include <cstdlib>

bool hasRowWithMorePositiveElements(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        int positiveCount = 0;
        int negativeCount = 0;

        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] < 0) {
                negativeCount += 1;
            } else if (matrix[i][j] > 0) {
                positiveCount += 1;
            }
        }

        if (positiveCount > negativeCount) {
            return true;
        }
    }
    return false;
}

int main() {
    // start of matrix creation
    int rows, columns;
    std::cout << "Enter the number of rows in the matrix: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns in the matrix: ";
    std::cin >> columns;

    if (rows < 1) {
        std::cerr << "The number of rows of the matrix is less than 1." << std::endl;
        std::cerr << "The matrix will not be created." << std::endl;
        return -1;
    } else if (columns < 1) {
        std::cerr << "The number of columns of the matrix is less than 1." << std::endl;
        std::cerr << "The matrix will not be created." << std::endl;
        return -1;
    }

    int** matrix = new int*[rows];
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];

        for (int j = 0; j < columns; j++) {
            matrix[i][j] = rand();
        }
    }
    // end of matrix creation

    std::cout << "Let's check if there is such a row in the array, where the number of ";
    std::cout << "positive is greater than negative: ";
    if (hasRowWithMorePositiveElements(matrix, rows, columns)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    // memory clearing
    for (int i = 0; i < rows; i++) {
        delete [] (matrix[i]);
    }
    delete [] matrix;
    return 0;
}