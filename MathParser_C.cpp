#include "MathParser_C.h"
#include <MathParser.hpp>
#include <new>
#include <cstring>
using namespace std;

MathParser * MathParser_new() {
    return new (nothrow) MathParser;
}

void MathParser_delete(MathParser * self) {
    delete self;
}

void MathParser_allowedVariableNames_add(MathParser * self, const char * varname) {
    self->allowedVariableNames.insert(varname);
}

MathExpression * MathParser_compileExpression(MathParser *self, const char *expr, char **dstErrorStr) {
    try {
        return new (nothrow) MathExpression (self->compileExpression(expr));
    } catch (MathParserException& ex) {
        *dstErrorStr = strdup(ex.what());
        return nullptr;
    } catch (...) {
        if (dstErrorStr) {
            *dstErrorStr = strdup("Undefined error");
        }
        return nullptr;
    }
}

void MathExpression_delete(MathExpression * self) {
    delete self;
}

double MathExpression_variable(const MathExpression *self, const char *name) {
    return self->variable(name);
}

void MathExpression_setVariable(MathExpression *self, const char *name, double value) {
    self->setVariable(name, value);
}

double MathExpression_value(const MathExpression *self) {
    return self->value();
}

double MathExpression_valueWith(MathExpression *self, const char *variableName, double variableValue) {
    return self->valueWith(variableName, variableValue);
}
