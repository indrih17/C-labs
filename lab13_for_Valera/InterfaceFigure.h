#include "Point.h"

#ifndef INTERFACE_FIGURE_H
#define INTERFACE_FIGURE_H

class InterfaceFigure {
public:
    virtual void clockwiseRotation(int degree) = 0;
    virtual void displacement(double x, double y) = 0;

    void operator >> (int degree) { 
        clockwiseRotation(degree); 
    }
    void operator += (Point p) { 
        displacement(p.x, p.y); 
    }
};

#endif