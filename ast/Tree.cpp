#include <exception>

#include "ast/Tree.hpp"
#include "ast/Context.hpp"
#include "ast/Node.hpp"

double ast::Tree::value() const {
    return rootNode->value(context);
}

