#ifndef INFO_SERVICE
#define INFO_SERVICE

#include "toml++/toml.hpp"
#include "model/InfoResponse.h"

namespace Service {
    class InfoService {
        private:
            toml::value config;
        public:
            InfoService();
            InfoService(toml::value& config);
            Model::InfoResponse::Wrapper info();
    };
};

#endif