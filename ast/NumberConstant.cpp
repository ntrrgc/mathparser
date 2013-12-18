#include <exception>
#include <string>
#include <sstream>
using namespace std;

#include "ast/NumberConstant.hpp"
#include "ast/Context.hpp"
#include "ast/Terminal.hpp"

ast::NumberConstant::NumberConstant() {}
ast::NumberConstant::NumberConstant(double value)
    : value_(value) {}

double ast::NumberConstant::value(const ast::Context& ctx) const {
    return value();
}

double ast::NumberConstant::value() const {
    return value_;
}

void ast::NumberConstant::setValue(double value) {
    this->value_ = value;
}

string ast::NumberConstant::toString() const {
    ostringstream ss;
    ss << value();
    return ss.str();
}

