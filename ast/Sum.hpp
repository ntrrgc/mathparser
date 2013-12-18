#include <exception>
#include <string>

#ifndef __ast__Sum_hpp__
#define __ast__Sum_hpp__

#include "ast/Context.hpp"
#include "ast/BinaryOperation.hpp"

namespace ast
{
    class Context;
    // class BinaryOperation;
    class Sum;
}

namespace ast
{
    class Sum: public ast::BinaryOperation
    {
    public:
        Sum();
        Sum(std::unique_ptr<ast::Node> operand1, std::unique_ptr<ast::Node> operand2);

        double value(const ast::Context& ctx) const;
        std::string toString() const;
    };
}

#endif
