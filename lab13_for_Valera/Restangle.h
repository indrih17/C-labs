#include "InterfaceFigure.h"
#include "Square.h"
#include "Point.h"

#ifndef RESTANGLE_H
#define RESTANGLE_H

class Rectangle : public Square {
public:
    Rectangle(Point topLeft, Point bottomRight): Square(topLeft, bottomRight, false) {}
};

#endif