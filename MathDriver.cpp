#include "MathDriver.hpp"
#include <iostream>
#include <ast/ast.hpp>

MathDriver::MathDriver(const std::map<std::string, const double>& constants,
                       const std::map<std::string, const ast::Function>& functions,
                       const std::set<std::string>& allowedVariableNames)
    : bufferState(nullptr),
      constants(&constants),
      functions(&functions),
      allowedVariableNames(&allowedVariableNames)
{}

MathDriver::~MathDriver() {}

bool
MathDriver::parse(const std::string &expr) {
    errorBit = false;
    buffer = expr;
    scan_begin();
    yy::MathParser parser(*this, yyscanner);
    //parser.set_debug_level(false);
    int res = parser.parse();
    scan_end();
    return (res == 0 && !errorBit);
}

void
MathDriver::error(const yy::location &l, const std::string &m) {
    /* Print newline if it isn't the first error */
    if (errorBuffer.tellp() != 0)
        errorBuffer << "\n";
    /* Don't print position if error is at the end of expression */
    if (l.begin.column < buffer.length())
        errorBuffer << l.begin.column << ": ";
    errorBuffer << m;
}

void
MathDriver::error(const std::string &m) {
    /* Print newline if it isn't the first error */
    if (errorBuffer.tellp() != 0)
        errorBuffer << "\n";
    errorBuffer << m;
}
