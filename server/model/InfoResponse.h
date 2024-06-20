#ifndef INFO_RESPONSE
#define INFO_RESPONSE

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

namespace Model {
    class InfoResponse : public oatpp::DTO {
        private:
        public:
            DTO_INIT(InfoResponse, DTO);
            DTO_FIELD(Int32, statusCode);
            DTO_FIELD(String, message);
    };
};

#include OATPP_CODEGEN_END(DTO)

#endif