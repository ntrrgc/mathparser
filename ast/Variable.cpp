#include <exception>
#include <stdexcept>
#include <string>
using namespace std;

#include "ast/Variable.hpp"
#include "ast/Context.hpp"
#include "ast/Terminal.hpp"

ast::Variable::Variable() {}

ast::Variable::Variable(const string& name) {
    setName(name);
}

double ast::Variable::value(const ast::Context& ctx) const {
    map<string, double>::const_iterator varIter = ctx.variables.find(name());
    if (varIter == ctx.variables.end())
        throw std::out_of_range(string("Unknown variable: ") + name());
    return varIter->second;
}

string ast::Variable::toString() const {
    return name();
}

const string& ast::Variable::name() const {
    return name_;
}

void ast::Variable::setName(const string& name) {
    this->name_ = name;
}

