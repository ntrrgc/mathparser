#include <exception>
#include <string>
#include <sstream>
using namespace std;

#include "ast/Sum.hpp"
#include "ast/Context.hpp"
#include "ast/BinaryOperation.hpp"

ast::Sum::Sum() {}

ast::Sum::Sum(std::unique_ptr<ast::Node> operand1, std::unique_ptr<ast::Node> operand2) {
    setOperand1(move(operand1));
    setOperand2(move(operand2));
}

double ast::Sum::value(const ast::Context& ctx) const {
    return operand1()->value(ctx) + operand2()->value(ctx);
}

string ast::Sum::toString() const {
    ostringstream ss;
    ss << "(" << operand1()->toString() << " + " << operand2()->toString() << ")";
    return ss.str();
}

