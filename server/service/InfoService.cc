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
    auto response = Model::InfoResponse::createShared();
    response->message = "Up!";
    response->status_code = 100;
    return response;
}