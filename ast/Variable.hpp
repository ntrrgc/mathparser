#include <exception>
#include <string>

#ifndef __ast__Variable_hpp__
#define __ast__Variable_hpp__

#include "ast/Context.hpp"
#include "ast/Terminal.hpp"

namespace ast
{
    class Context;
    // class Terminal;
    class Variable;
}

namespace ast
{
    class Variable: public ast::Terminal
    {
    public:
        Variable();
        Variable(const std::string& name);

        double value(const ast::Context& ctx) const;
        std::string toString() const;
        const std::string & name() const;
        void setName(const std::string& name);
    private:
        std::string name_;

    };
}

#endif
