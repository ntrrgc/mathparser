#include <exception>
#include <string>

#ifndef __ast__Exponentiation_hpp__
#define __ast__Exponentiation_hpp__

#include "ast/Context.hpp"
#include "ast/BinaryOperation.hpp"

namespace ast
{
    class Context;
    // class BinaryOperation;
    class Exponentiation;
}

namespace ast
{
    class Exponentiation: public ast::BinaryOperation
    {
    public:
        Exponentiation();
        Exponentiation(std::unique_ptr<ast::Node> operand1, std::unique_ptr<ast::Node> operand2);

        double value(const ast::Context& ctx) const;
        std::string toString() const;
    };
}

#endif
