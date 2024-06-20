#ifndef INFO_ROUTE
#define INFO_ROUTE

#include "spdlog/spdlog.h"
#include "toml++/toml.hpp"
#include "oatpp/web/server/HttpRequestHandler.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include <memory>
#include "service/InfoService.h"

namespace Inbound {
    class InfoRoute : public oatpp::web::server::HttpRequestHandler {
        private:
            toml::value config;
            std::shared_ptr<oatpp::parser::json::mapping::ObjectMapper> object_mapper;
            Service::InfoService info_service;
        public:
            InfoRoute(toml::value& config);
            std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override;
    };
};

#endif