#include "InterfaceFigure.h"
#include "Point.h"
#include <math.h>

#ifndef SQUARE_H
#define SQUARE_H

class Square : public InterfaceFigure {
private:
    Point topLeft, topRight, bottomLeft, bottomRight, center;

    inline double calculateNewX(double x, double x0, double y, double y0, double degree) {
        return x0 + (x - x0) * cos(degree) - (y - y0) * sin(degree);
    }
    inline double calculateNewY(double x, double x0, double y, double y0, double degree) {
        return y0 + (y - y0) * cos(degree) + (x - x0) * sin(degree);
    }

public:
    Square(Point topLeft, Point bottomRight, bool checkSymmetry);
    
    Point getTopLeft() {
        return topLeft;
    }
    void setTopLeftPoint(Point topLeft) {
        this->topLeft = topLeft;
        this->topRight.y = topLeft.y;
        this->bottomLeft.x = topLeft.x;
    }

    Point getTopRight() {
        return topRight;
    }

    Point getBottomLeft() {
        return bottomLeft;
    }

    Point getBottomRight() {
        return bottomRight;
    }

    void setBottomRightPoint(Point bottomRight) {
        this->bottomRight = bottomRight;
        this->bottomLeft.y = bottomRight.y;
        this->topRight.x = bottomRight.x;
    }

    virtual void clockwiseRotation(int degree);
    virtual void displacement(double x, double y);
};

#endif