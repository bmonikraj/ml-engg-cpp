#ifndef BASE_ROUTER
#define BASE_ROUTER

namespace Inbound {
    class BaseRouter {
        public:
            virtual void run() = 0;
    };
};

#endif