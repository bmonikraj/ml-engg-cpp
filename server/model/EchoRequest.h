#ifndef ECHO_REQUEST
#define ECHO_REQUEST

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

namespace Model {
    class EchoRequest : public oatpp::DTO {
        private:
        public:
            DTO_INIT(EchoRequest, DTO);
            DTO_FIELD(String, message);
    };
};

#include OATPP_CODEGEN_END(DTO)

#endif