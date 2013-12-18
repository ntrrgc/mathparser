#include <exception>
#include <string>
#include <vector>
#include <memory>

#ifndef __ast__FunctionCall_hpp__
#define __ast__FunctionCall_hpp__

#include "ast/Function.hpp"
#include "ast/Node.hpp"
#include "ast/Context.hpp"

namespace ast
{
    // class Node;
    class Context;
    class FunctionCall;
}

namespace ast
{
    class FunctionCall: public ast::Node
    {
    public:
        FunctionCall(const std::string& name);
        FunctionCall(const std::string& name,
                     const Function& function,
                     std::vector<std::unique_ptr<ast::Node> >&& arguments);

        FunctionDefinition definition;
        std::vector<std::unique_ptr<ast::Node> > arguments;

        double value(const ast::Context& ctx) const;
        std::string toString() const;

        std::string name() const;
        void setName(std::string name);

    private:
        std::string name_;

    };
}

#endif
