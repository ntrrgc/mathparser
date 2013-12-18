#include <exception>
#include <string>

#ifndef __ast__Subtract_hpp__
#define __ast__Subtract_hpp__

#include "ast/Context.hpp"
#include "ast/BinaryOperation.hpp"

namespace ast
{
    class Context;
    // class BinaryOperation;
    class Subtract;
}

namespace ast
{
    class Subtract: public ast::BinaryOperation
    {
    public:
        Subtract();
        Subtract(std::unique_ptr<ast::Node> operand1, std::unique_ptr<ast::Node> operand2);

        double value(const ast::Context& ctx) const;
        std::string toString() const;
    };
}

#endif
