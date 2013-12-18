#include <exception>
#include <string>
#include <memory>

#ifndef __ast__UnaryMinus_hpp__
#define __ast__UnaryMinus_hpp__

#include "ast/Context.hpp"
#include "ast/UnaryOperation.hpp"

namespace ast
{
    class Context;
    // class UnaryOperation;
    class UnaryMinus;
}

namespace ast
{
    class UnaryMinus: public ast::UnaryOperation
    {
    public:
        UnaryMinus();
        UnaryMinus(std::unique_ptr<ast::Node> operand);

        double value(const ast::Context& ctx) const;
        std::string toString() const;
    };
}

#endif
