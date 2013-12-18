#include "Error.hpp"

#include <stdexcept>
using namespace std;

namespace ast {

Error::Error()
{}

double
Error::value(const ast::Context& ctx) const {
    throw std::runtime_error("Attempted to calculate value of error node.");
}

std::string
Error::toString() const {
    return "[error node]";
}

} // namespace ast
