#include <exception>
#include <string>
#include <sstream>
using namespace std;

#include "ast/UnaryMinus.hpp"
#include "ast/Context.hpp"
#include "ast/UnaryOperation.hpp"

ast::UnaryMinus::UnaryMinus() {}

ast::UnaryMinus::UnaryMinus(std::unique_ptr<ast::Node> operand) {
    setOperand(move(operand));
}

double ast::UnaryMinus::value(const ast::Context& ctx) const {
    return -(operand()->value(ctx));
}

string ast::UnaryMinus::toString() const {
    ostringstream ss;
    ss << "(-" << operand()->toString() << ")";
    return ss.str();
}

