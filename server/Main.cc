#include <iostream>
#include <format>
#include <string>

#include "Circle.h"
#include "Square.h"

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl; 

    if (argc < 3) {
        std::cout << std::format("Length of the arguments = {} and it is not sufficient", argc) << std::endl;
        exit(1);
    }

    std::string shapeKind = argv[1];
    float dimension = std::stof(argv[2]);

    if (shapeKind == "circle") {
        Service::Circle circle(dimension);
        circle.computeArea();
        std::cout << std::format("Area of circle = {}", std::to_string(circle.getArea())) << std::endl;
    } else if (shapeKind == "square") {
        Service::Square square(dimension);
        square.computeArea();
        std::cout << std::format("Area of square = {}", std::to_string(square.getArea())) << std::endl;
    } else {
        std::cout << "Invalid shape kind!" << std::endl;
    }

    return 0;
}