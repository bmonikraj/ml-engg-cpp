#ifndef ECHO_RESPONSE
#define ECHO_RESPONSE

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

namespace Model {
    class EchoResponse : public oatpp::DTO {
        private:
        public:
            DTO_INIT(EchoResponse, DTO);
            DTO_FIELD(String, echo);
    };
};

#include OATPP_CODEGEN_END(DTO)

#endif