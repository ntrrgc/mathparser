#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <cassert>
using namespace std;

#include "ast/FunctionCall.hpp"
#include "ast/Node.hpp"
#include "ast/Context.hpp"

ast::FunctionCall::FunctionCall(const std::string& name)
    : name_(name)
{
}

ast::FunctionCall::FunctionCall(const std::string& name, const Function& function,
                                std::vector<std::unique_ptr<ast::Node> >&& arguments)
    : definition(function.definition), name_(name)
{
    this->arguments = std::move(arguments);
}

double ast::FunctionCall::value(const ast::Context& ctx) const {
    vector<double> argValues(arguments.size());
    for (int i = 0; i < arguments.size(); ++i) {
        argValues[i] = arguments[i]->value(ctx);
    }

    assert(this->definition);
    return this->definition(argValues);
}

string ast::FunctionCall::toString() const {
    ostringstream ss;
    ss << name() << "(";
    for (vector<unique_ptr<ast::Node> >::const_iterator i = arguments.begin(); i != arguments.end(); ++i) {
        if (i != arguments.begin())
            ss << ", ";
        ss << (*i)->toString();
    }
    ss << ")";
    return ss.str();
}

string ast::FunctionCall::name() const {
    return name_;
}

void ast::FunctionCall::setName(string name) {
    this->name_ = name;
}

