#include <iostream>
#include <format>
#include <string>
#include <ctime>

#include "service/Circle.h"
#include "service/Square.h"
#include "spdlog/spdlog.h"
#include "boost/random/mersenne_twister.hpp"
#include "boost/random/uniform_int_distribution.hpp"

int main(int argc, char *argv[]) {

    /**
     * Setting log level globally
    */
    spdlog::set_level(spdlog::level::debug);

    spdlog::info("Hello, World!");

    if (argc < 3) {
        spdlog::error("Length of the arguments = {} and it is not sufficient", argc);
        exit(1);
    }

    boost::random::mt19937 gen;
    gen.seed(std::time(0));
    boost::random::uniform_int_distribution<> dist(1, 583399531);
    spdlog::info("Randomly generated number using boost with constant seed is {}", dist(gen));

    std::string shapeKind = argv[1];
    float dimension = std::stof(argv[2]);

    if (shapeKind == "circle") {
        Service::Circle circle(dimension);
        circle.computeArea();
        spdlog::info("Area of circle = {}", std::to_string(circle.getArea()));
    } else if (shapeKind == "square") {
        Service::Square square(dimension);
        square.computeArea();
        spdlog::info("Area of square = {}", std::to_string(square.getArea()));
    } else {
        spdlog::warn("Invalid shape kind!");
    }

    return 0;
}