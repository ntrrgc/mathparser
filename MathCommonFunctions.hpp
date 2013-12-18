#ifndef MATHCOMMONFUNCTIONS_HPP
#define MATHCOMMONFUNCTIONS_HPP

#include <map>
#include <string>
#include <ast/Function.hpp>

class MathCommonFunctions : public std::map<std::string, const ast::Function>
{
    typedef std::map<std::string, const ast::Function> super;
public:
    MathCommonFunctions();
};

#endif // MATHCOMMONFUNCTIONS_HPP
