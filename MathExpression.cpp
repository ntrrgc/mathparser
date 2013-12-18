#include "MathExpression.hpp"

MathExpression::MathExpression(std::shared_ptr<ast::Node> compiledExpression,
                               const std::set<std::string> allowedVariableNames)
    : compiledExpression(compiledExpression)
{
    /* Initialize variables with default values */
    for (const std::string& variableName : allowedVariableNames) {
        context.variables.insert({ variableName, double() });
    }
}

MathExpression::MathExpression(MathExpression &&other) {
    this->compiledExpression = std::move(other.compiledExpression);
    this->context = std::move(other.context);
}

MathExpression::~MathExpression() {}

double
MathExpression::variable(const std::string& name) const {
    return context.variables.at(name);
}

void
MathExpression::setVariable(const std::string& name, double value) {
    context.variables.at(name) = value;
}

double
MathExpression::value() const {
    return this->compiledExpression->value(context);
}

double
MathExpression::valueWith(const std::string &variableName, double variableValue) {
    setVariable(variableName, variableValue);
    return this->value();
}

std::string
MathExpression::toString() const {
    return this->compiledExpression->toString();
}
