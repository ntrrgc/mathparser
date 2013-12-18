#include <exception>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

#include "ast/Exponentiation.hpp"
#include "ast/Context.hpp"
#include "ast/BinaryOperation.hpp"

ast::Exponentiation::Exponentiation() {}

ast::Exponentiation::Exponentiation(std::unique_ptr<ast::Node> operand1, std::unique_ptr<ast::Node> operand2) {
    setOperand1(move(operand1));
    setOperand2(move(operand2));
}

double ast::Exponentiation::value(const ast::Context& ctx) const {
    return pow(operand1()->value(ctx), operand2()->value(ctx));
}

string ast::Exponentiation::toString() const {
    ostringstream ss;
    ss << "(" << operand1()->toString() << " ^ " << operand2()->toString() << ")";
    return ss.str();
}

