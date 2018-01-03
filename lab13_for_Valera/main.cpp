#include <iostream>
#include "Restangle.h"

int main() {
    // start of the creation the list of figures
    int numberOfFigures;
    std::cout << "Enter the number of figures: ";
    std::cin >> numberOfFigures;

    if (numberOfFigures < 1) {
        std::cerr << "The number of figures is less than 1." << std::endl;
        std::cerr << "The list of figures will not be created." << std::endl;
        return -1;
    }

    Rectangle *figures = (Rectangle*) operator new (sizeof(Rectangle) * numberOfFigures);
    int i = 0;
    while (i < numberOfFigures) {
        std::cout << "Creating " << i+1 << " figure." << std::endl;

        Point topLeft, bottomRight;
        std::cout << "Enter the X coordinate for the top left point: ";
        std::cin >> topLeft.x;
        std::cout << "Enter the Y coordinate for the top left point: ";
        std::cin >> topLeft.y;
        std::cout << "Enter the X coordinate for the bottom right point: ";
        std::cin >> bottomRight.x;
        std::cout << "Enter the Y coordinate for the bottom right point: ";
        std::cin >> bottomRight.y;
        
        std::cout << std::endl;
        try {
            new(&figures[i]) Rectangle(topLeft, bottomRight);
            i += 1;
        } catch(char const* err) {
            std::cerr << err << std::endl;
        }
    }
    std::cout << std::endl;
    // end of the creation the list of figures

    for (int i = 0; i < numberOfFigures; i++) {
        figures[i] >> 2;
        Point coordinateDisplacement = {1, 2};
        figures[i] += coordinateDisplacement;
    }
    
    // memory cleaning
    for (int i = 0; i < numberOfFigures; i++) {
        figures[i].~Rectangle();
    }
    delete figures;
    return 0;
}