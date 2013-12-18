#ifndef AST_ERROR_HPP
#define AST_ERROR_HPP

#include "ast/Terminal.hpp"

namespace ast {

class Error : public ast::Terminal
{
public:
    Error();

    virtual double value(const ast::Context& ctx) const;
    virtual std::string toString() const;
};

} // namespace ast

#endif // AST_ERROR_HPP
