#ifndef ECHO_SERVICE
#define ECHO_SERVICE

#include "toml++/toml.hpp"
#include "model/EchoRequest.h"
#include "model/EchoResponse.h"

namespace Service {
    class EchoService {
        private:
            toml::value config;
        public:
            EchoService();
            EchoService(toml::value& config);
            Model::EchoResponse::Wrapper echo(Model::EchoRequest* request);
    };
};

#endif