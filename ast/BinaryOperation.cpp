#include <vector>
#include <utility>
using namespace std;

#include "ast/BinaryOperation.hpp"
#include "ast/Node.hpp"
#include "ast/Operation.hpp"

const std::unique_ptr<ast::Node>&
ast::BinaryOperation::operand1() const {
    return operands_[0];
}

const std::unique_ptr<ast::Node>&
ast::BinaryOperation::operand2() const {
    return operands_[1];
}

void
ast::BinaryOperation::setOperand1(std::unique_ptr<ast::Node> newNode) {
    operands_[0] = move(newNode);
}

void
ast::BinaryOperation::setOperand2(std::unique_ptr<ast::Node> newNode) {
    operands_[1] = move(newNode);
}
