#include <string>
#include <map>

#ifndef __ast__Context_hpp__
#define __ast__Context_hpp__

#include "ast/Function.hpp"

namespace ast
{
    class Function;
    class Context;
}

namespace ast
{
    class Context
    {
        public:
            std::map<std::string, double> variables;
    };
}

#endif
