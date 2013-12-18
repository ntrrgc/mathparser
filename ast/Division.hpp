#include <exception>
#include <string>

#ifndef __ast__Division_hpp__
#define __ast__Division_hpp__

#include "ast/Context.hpp"
#include "ast/BinaryOperation.hpp"

namespace ast
{
    class Context;
    // class BinaryOperation;
    class Division;
}

namespace ast
{
    class Division: public ast::BinaryOperation
    {
    public:
        Division();
        Division(std::unique_ptr<ast::Node> operand1, std::unique_ptr<ast::Node> operand2);

        double value(const ast::Context& ctx) const;
        std::string toString() const;
    };
}

#endif
