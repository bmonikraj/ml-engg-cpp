#ifndef ECHO_ROUTE
#define ECHO_ROUTE

#include "spdlog/spdlog.h"
#include "toml++/toml.hpp"
#include "oatpp/web/server/HttpRequestHandler.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include <memory>
#include "service/EchoService.h"

namespace Inbound {
    class EchoRoute : public oatpp::web::server::HttpRequestHandler {
        private:
            toml::value config;
            std::shared_ptr<oatpp::parser::json::mapping::ObjectMapper> object_mapper;
            Service::EchoService echo_service;
        public:
            EchoRoute(toml::value& config);
            std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override;
    };
};

#endif