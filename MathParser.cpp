#include "MathParser.hpp"

#include "MathCommonConstants.hpp"
#include "MathCommonFunctions.hpp"
#include "MathDriver.hpp"
using namespace std;

MathCommonConstants defaultConstants;
MathCommonFunctions defaultFunctions;

MathParserException::MathParserException(const std::string& error)
    : std::runtime_error(error) {}

MathParser::MathParser()
    : constants(defaultConstants), functions(defaultFunctions)
{}

MathParser::~MathParser() {}

MathExpression
MathParser::compileExpression(const string &expr) {
    MathDriver driver(constants, functions, allowedVariableNames);
    if (driver.parse(expr)) {
        /* Correct expression */
        return MathExpression(driver.result, allowedVariableNames);
    } else {
        /* Erroneous expression */
        throw MathParserException(driver.errorBuffer.str());
    }
}
