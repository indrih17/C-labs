#include "InterfaceFigure.h"
#include "Point.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public InterfaceFigure {
private:
    Point center;
    double radius;
public:
    Circle(Point center, double radius) {
        this->center = center;
        this->radius = radius;
    }

    Point getCenter() {
        return center;
    }
    void setCenter(Point center) {
        this->center = center;
    }

    double getRadius() {
        return radius;
    }
    void setRadius(double radius) {
        this->radius = radius;
    }
    
    virtual void clockwiseRotation(int degree);
    virtual void displacement(double x, double y);
};

void Circle::displacement(double x, double y) {
    this->center.x += x;
    this->center.y += y;
}

#endif