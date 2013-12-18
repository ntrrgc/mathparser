#include <exception>
#include <string>

#ifndef __ast__NumberConstant_hpp__
#define __ast__NumberConstant_hpp__

#include "ast/Context.hpp"
#include "ast/Terminal.hpp"

namespace ast
{
    class Context;
    // class Terminal;
    class NumberConstant;
}

namespace ast
{
    class NumberConstant: public ast::Terminal
    {
    public:
        NumberConstant();
        NumberConstant(double value);

        double value(const ast::Context& ctx) const;
        double value() const;
        void setValue(double value);
        std::string toString() const;
    private:
        double value_;

    };
}

#endif
