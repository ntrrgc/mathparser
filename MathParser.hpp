#ifndef MATHPARSER_HPP
#define MATHPARSER_HPP

#include <ast/Node.hpp>
#include <ast/Function.hpp>
#include <map>
#include <string>
#include <set>
#include <stdexcept>

#include "MathExpression.hpp"

class MathParserException : public std::runtime_error {
public:
    MathParserException(const std::string& error);
};

class MathParser
{
public:
    MathParser();
    virtual ~MathParser();

    std::map<std::string, const double> constants;
    std::map<std::string, const ast::Function> functions;
    std::set<std::string> allowedVariableNames;

    MathExpression compileExpression(const std::string& expr); /* throws MathParserException */
};

#endif // MATHPARSER_HPP
