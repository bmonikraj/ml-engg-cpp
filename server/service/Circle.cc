#include <cmath>

#include "Circle.h"

void Service::Circle::computeArea() {
    this->area = M_PI*radius*radius;
}

Service::Circle::Circle(float radius) {
    this->radius = radius;
}

float Service::Circle::getArea()
{
    return this->area;
}