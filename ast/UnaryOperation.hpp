#include <memory>

#ifndef __ast__UnaryOperation_hpp__
#define __ast__UnaryOperation_hpp__

// #include "ast/Node.hpp"
#include "ast/Operation.hpp"

namespace ast
{
    // class Node;
    // class Operation;
    class UnaryOperation;
}

namespace ast
{
    class UnaryOperation: public ast::Operation
    {
    public:
        const std::unique_ptr<ast::Node>& operand() const;
        void setOperand(std::unique_ptr<ast::Node> newNode);

    private:
        std::unique_ptr<ast::Node> operand_;

    };
}

#endif
