#include "spdlog/spdlog.h"
#include "toml++/toml.hpp"
#include "model/EchoRequest.h"
#include "model/EchoResponse.h"
#include "EchoService.h"

Service::EchoService::EchoService() {
    this->config = NULL;
}

Service::EchoService::EchoService(toml::value& config) {
    this->config = config;
}

Model::EchoResponse::Wrapper Service::EchoService::echo(Model::EchoRequest* request)  {
    auto response = Model::EchoResponse::createShared();
    if (request->message.get() == NULL) {
        SPDLOG_ERROR("param `message` is not passed as expected");
    }
    response->echo = request->message;
    return response;
}