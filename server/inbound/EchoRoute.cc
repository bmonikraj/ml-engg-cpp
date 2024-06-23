#include "EchoRoute.h"
#include "oatpp/web/server/HttpRequestHandler.hpp"
#include "spdlog/spdlog.h"
#include "toml++/toml.hpp"
#include <memory>
#include "service/EchoService.h"
#include "model/EchoRequest.h"
#include <iostream>

Inbound::EchoRoute::EchoRoute(toml::value& config) {
    this->config = config;
    this->object_mapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
    
    Service::EchoService echo_service_obj(this->config);
    this->echo_service = echo_service_obj;
}

std::shared_ptr<oatpp::web::server::HttpRequestHandler::OutgoingResponse> Inbound::EchoRoute::handle(const std::shared_ptr<IncomingRequest> &request) {
    SPDLOG_INFO("InfoRoute invoked");
    
    if (request.get()->getHeader("Content-Type") != "application/json") {
        SPDLOG_ERROR("content-type must be application/json");
        return ResponseFactory::createResponse(Status::CODE_415, "Media type not supported");
    }

    Model::EchoRequest::Wrapper echo_request;
    try {
        echo_request = this->object_mapper->readFromString<oatpp::Object<Model::EchoRequest>>(request.get()->readBodyToString());
    } catch(oatpp::parser::ParsingError err) {
        SPDLOG_ERROR("request body is malformed");
        SPDLOG_ERROR("{}", err.getMessage().getValue(""));
        return ResponseFactory::createResponse(Status::CODE_400, "Bad request");
    }

    return ResponseFactory::createResponse(Status::CODE_200, this->echo_service.echo(echo_request.get()), this->object_mapper);
}