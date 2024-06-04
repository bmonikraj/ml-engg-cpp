#include <cmath>

#include "Square.h"

void Service::Square::computeArea() {
    this->area = length*length;
}

Service::Square::Square(float length) {
    this->length = length;
}

float Service::Square::getArea()
{
    return this->area;
}