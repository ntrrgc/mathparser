#include <exception>
#include <string>

#ifndef __ast__Multiplication_hpp__
#define __ast__Multiplication_hpp__

#include "ast/Context.hpp"
#include "ast/BinaryOperation.hpp"

namespace ast
{
    class Context;
    // class BinaryOperation;
    class Multiplication;
}

namespace ast
{
    class Multiplication: public ast::BinaryOperation
    {
    public:
        Multiplication();
        Multiplication(std::unique_ptr<ast::Node> operand1, std::unique_ptr<ast::Node> operand2);

        double value(const ast::Context& ctx) const;
        std::string toString() const;
    };
}

#endif
