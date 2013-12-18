#include <exception>
#include <memory>

#ifndef __ast__Tree_hpp__
#define __ast__Tree_hpp__

#include "ast/Context.hpp"
// #include "ast/Node.hpp"

namespace ast
{
    class Context;
    class Node;
    class Tree;
}

namespace ast
{
    class Tree
    {
        public:
            std::unique_ptr<ast::Node> rootNode;

            double value() const;
        //private:
            ast::Context context;

    };
}

#endif
