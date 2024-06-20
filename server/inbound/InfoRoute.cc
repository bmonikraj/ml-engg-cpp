#include "InfoRoute.h"
#include "oatpp/web/server/HttpRequestHandler.hpp"
#include "spdlog/spdlog.h"
#include "toml++/toml.hpp"
#include <memory>
#include "service/InfoService.h"

Inbound::InfoRoute::InfoRoute(toml::value& config) {
    this->config = config;
    this->object_mapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
    
    Service::InfoService info_service_obj(this->config);
    this->info_service = info_service_obj;
}

std::shared_ptr<oatpp::web::server::HttpRequestHandler::OutgoingResponse> Inbound::InfoRoute::handle(const std::shared_ptr<IncomingRequest> &request) {
    return ResponseFactory::createResponse(Status::CODE_200, this->info_service.info(), this->object_mapper);
}