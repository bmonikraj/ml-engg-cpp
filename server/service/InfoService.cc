#include "spdlog/spdlog.h"
#include "toml++/toml.hpp"
#include "model/InfoResponse.h"
#include "InfoService.h"

Service::InfoService::InfoService() {
    this->config = NULL;
}

Service::InfoService::InfoService(toml::value& config) {
    this->config = config;
}

Model::InfoResponse::Wrapper Service::InfoService::info()  {
    auto message = Model::InfoResponse::createShared();
    message->message = "Up!";
    message->statusCode = 100;
    return message;
}