#include <iostream>
#include <format>
#include <string>
#include <ctime>
#include <typeinfo>

#include "spdlog/spdlog.h"
#include "toml++/toml.hpp"

#include "inbound/BaseRouter.h"

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
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%ST%z] [%^%l%$] [%s:%#] [process %P] [thread %t] [%!] %v");
    
    SPDLOG_INFO("Starting Machine Learning Engineering Server ...");

    Inbound::BaseRouter base_router(config);

    base_router.init();
    base_router.run();
    base_router.destroy();

    return 0;
}