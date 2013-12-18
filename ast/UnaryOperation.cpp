#include "ast/UnaryOperation.hpp"
#include "ast/Node.hpp"
#include "ast/Operation.hpp"

#include <utility>
using namespace std;

const std::unique_ptr<ast::Node>&
ast::UnaryOperation::operand() const {
    return operand_;
}

void
ast::UnaryOperation::setOperand(std::unique_ptr<ast::Node> newNode) {
    operand_ = move(newNode);
}
