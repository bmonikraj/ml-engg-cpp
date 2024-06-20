#include <iostream>
#include <format>
#include <string>
#include <ctime>
#include <typeinfo>

#include "spdlog/spdlog.h"
#include "toml++/toml.hpp"

#include "inbound/BaseRouter.h"

/** 
 * DELETE
#include "service/Circle.h"
#include "service/Square.h"
#include "boost/random/mersenne_twister.hpp"
#include "boost/random/uniform_int_distribution.hpp"
**/

int main(int argc, char *argv[]) {

    /** checking the argument length in command line */
    if (argc < 1) {
        std::cout<< "Length of the arguments = " << argc << " and it is not sufficient, absolute path of config.toml is required" << std::endl;
        exit(101);
    }

    /** Parsing config.toml file to load configurations */
    toml::value config = toml::parse(argv[1]);

    /** Setting log level globally */
    std::string& log_level = config.as_table().at("log").at("level").as_string(); 
    if (log_level == "DEBUG") {
        spdlog::set_level(spdlog::level::debug);
    } else if (log_level == "INFO") {
        spdlog::set_level(spdlog::level::info);
    } else if (log_level == "WARN") {
        spdlog::set_level(spdlog::level::warn);
    } else if (log_level == "ERROR") {
        spdlog::set_level(spdlog::level::err);
    } else {
        spdlog::set_level(spdlog::level::debug);
    }

    
    spdlog::info("Starting Machine Learning Engineering Server ...");

    Inbound::BaseRouter base_router(config);

    base_router.init();
    base_router.run();
    base_router.destroy();
    
    /** 
     * DELETE
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
    **/

    return 0;
}