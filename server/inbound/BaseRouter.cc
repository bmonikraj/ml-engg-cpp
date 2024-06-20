#include "spdlog/spdlog.h"
#include "toml++/toml.hpp"
#include "oatpp/core/base/Environment.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "BaseRouter.h"
#include "InfoRoute.h"
#include <memory>

Inbound::BaseRouter::BaseRouter(toml::value& config) {
    this->config = config;
}

void Inbound::BaseRouter::init() {
    oatpp::base::Environment::init();
}

void Inbound::BaseRouter::run() {

    /* Create Router for HTTP requests routing */
    auto router = oatpp::web::server::HttpRouter::createShared();

    /* Route addition */
    router->route("GET", "/info", std::make_shared<InfoRoute>(this->config));

    /* Create HTTP connection handler with router */
    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

    std::string address = this->config.as_table().at("server").at("address").as_string();
    int port = this->config.as_table().at("server").at("port").as_integer();

    /* Create TCP connection provider */
    auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({
        address,
        static_cast<v_uint16>(port),
        oatpp::network::Address::IP_4
    });

    /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
    oatpp::network::Server server(connectionProvider, connectionHandler);

    spdlog::info("Server running at {}:{}", address, port);

    server.run();
}

void Inbound::BaseRouter::destroy() {
    oatpp::base::Environment::destroy();
}