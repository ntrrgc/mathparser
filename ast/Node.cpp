#include <exception>
#include <string>
#include <sstream>
#include <typeinfo>
using namespace std;

#include "ast/Node.hpp"
#include "ast/Context.hpp"

ast::Node::~Node() {}

string ast::Node::toString() const {
    ostringstream ss;
    ss << "(unknown " << typeid(*this).name() << ")";
    return ss.str();
}

