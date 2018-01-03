#include "Square.h"
#include "Point.h"
#include <iostream>

Square::Square(Point topLeft, Point bottomRight, bool checkSymmetry = true) {
    if (topLeft.y <= bottomRight.y) {
        throw "The top left point should be below the bottom right point";
    }
    if (bottomRight.x <= topLeft.x) {
        throw "The bottom right point should be to the right of the top left point";
    }
    if (checkSymmetry && bottomRight.x - topLeft.x != topLeft.y - bottomRight.y) {
        throw "This figure is not a square";
    }
    this->topLeft = topLeft;

    this->bottomRight = bottomRight;

    this->topRight = {bottomRight.x, topLeft.y};

    this->bottomLeft = {topLeft.x, bottomRight.y};

    this->center = {bottomRight.x - topLeft.x, topLeft.x - bottomRight.x}; 
}

void Square::clockwiseRotation(int degree) {
    bottomRight.x = calculateNewX(bottomRight.x, center.x, bottomRight.y, center.y, degree);
    bottomRight.y = calculateNewY(bottomRight.x, center.x, bottomRight.y, center.y, degree);

    topLeft.x = calculateNewX(topLeft.x, center.x, topLeft.y, center.y, degree);
    topLeft.y = calculateNewY(topLeft.x, center.x, topLeft.y, center.y, degree);

    bottomLeft.x = calculateNewX(bottomLeft.x, center.x, bottomLeft.y, center.y, degree);
    bottomLeft.y = calculateNewY(bottomLeft.x, center.x, bottomLeft.y, center.y, degree);

    topRight.x = calculateNewX(topRight.x, center.x, topRight.y, center.y, degree);
    topRight.y = calculateNewY(topRight.x, center.x, topRight.y, center.y, degree);
}

void Square::displacement(double x, double y) {
    bottomRight.x += x;
    bottomRight.y += y;

    topRight.x += x;
    topRight.y += y;

    bottomLeft.x += x;
    bottomLeft.y += y;

    topLeft.x += x;
    topLeft.y += y;
}