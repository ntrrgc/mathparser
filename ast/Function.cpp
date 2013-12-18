#include <exception>
#include <vector>
#include <cassert>
using namespace std;

#include "ast/Function.hpp"

ast::Function::Function(ast::FunctionDefinition definition, int minArguments, int maxArguments)
    : definition(definition), minArguments(minArguments), maxArguments(maxArguments)
{
}

bool
ast::Function::enoughArguments(int howMany) const {
    return howMany >= minArguments && howMany <= maxArguments;
}

double
ast::Function::call(const vector<double> &params) const {
    assert(enoughArguments(params.size()));
    return definition(params);
}
