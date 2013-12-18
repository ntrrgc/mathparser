#include <exception>
#include <string>

#ifndef __ast__Node_hpp__
#define __ast__Node_hpp__

#include "ast/Context.hpp"

namespace ast
{
    class Context;
    class Node;
}

namespace ast
{
    class Node
    {
    public:
        virtual ~Node();

        virtual double value(const ast::Context& ctx) const = 0;
        virtual std::string toString() const;
    };
}

#endif
