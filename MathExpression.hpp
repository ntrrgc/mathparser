#ifndef MATHEXPRESSION_HPP
#define MATHEXPRESSION_HPP

#include <memory>
#include <map>
#include <string>
#include <set>
#include <ast/Node.hpp>
#include <ast/Context.hpp>

class MathExpression {
public:
    MathExpression(std::shared_ptr<ast::Node> compiledExpression,
                   const std::set<std::string> allowedVariableNames);
    MathExpression(MathExpression&& other);
    virtual ~MathExpression();

    double variable(const std::string& name) const;
    void setVariable(const std::string& name, double value);

    double value() const;
    /* shortcut for { setVariable(variableName, variableValue); return value(); } */
    double valueWith(const std::string &variableName, double variableValue);

    std::string toString() const;

private:
    std::shared_ptr<ast::Node> compiledExpression;

    ast::Context context;
};

#endif // MATHEXPRESSION_HPP
