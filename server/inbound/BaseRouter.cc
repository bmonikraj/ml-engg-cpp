#include "oatpp/oatpp/network/Server.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "BaseRouter.h"

Inbound::BaseRouter::BaseRouter() {

}

void Inbound::BaseRouter::run() {

    /* Create Router for HTTP requests routing */
    auto router = oatpp::web::server::HttpRouter::createShared();

    /* Create HTTP connection handler with router */
    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

}