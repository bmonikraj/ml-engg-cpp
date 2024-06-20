#ifndef BASE_ROUTER
#define BASE_ROUTER

#include "toml++/toml.hpp"

namespace Inbound {
    class BaseRouter {
        private:
            toml::value config;
        public:
            BaseRouter(toml::value& config);
            void init();
            void run();
            void destroy();
    };
};

#endif