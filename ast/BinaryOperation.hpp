#include <memory>

#ifndef __ast__BinaryOperation_hpp__
#define __ast__BinaryOperation_hpp__

#include "ast/Node.hpp"
#include "ast/Operation.hpp"

namespace ast
{
    // class Node;
    // class Operation;
    class BinaryOperation;
}

namespace ast
{
    class BinaryOperation: public ast::Operation
    {
    public:
        const std::unique_ptr<ast::Node>& operand1() const;
        const std::unique_ptr<ast::Node>& operand2() const;

        void setOperand1(std::unique_ptr<ast::Node> newNode);
        void setOperand2(std::unique_ptr<ast::Node> newNode);

    private:
        std::unique_ptr<ast::Node> operands_[2];

    };
}

#endif
