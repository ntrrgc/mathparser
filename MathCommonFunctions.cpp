#include "MathCommonFunctions.hpp"

#include <cmath>
using namespace std;
using namespace ast;

namespace common_functions {

/* Special functions:
 * * fabs: renamed to abs
 * * pow: needs 2 arguments
 */

/* awk script:

a) To generate function definitions:
       awk '{                                                       \
         print "double " $0 "(const std::vector<double>& args) {";  \
         print "    return ::" $0 "(args[0]);";                     \
         print "}";                                                 \
       }'

b) To generate initialization map:
       awk '{
         print "{\"" $0 "\", {" $0 ", 1, 1} },";
       }'

*/

/*
sin
sinh
cos
cosh
tan
tanh
asin
asinh
acos
acosh
atan
atanh
log2
log10
sqrt
cbrt
ceil
floor
round

pow
fabs
fmod
log
*/

double sin(const std::vector<double>& args) {
    return ::sin(args[0]);
}
double sinh(const std::vector<double>& args) {
    return ::sinh(args[0]);
}
double cos(const std::vector<double>& args) {
    return ::cos(args[0]);
}
double cosh(const std::vector<double>& args) {
    return ::cosh(args[0]);
}
double tan(const std::vector<double>& args) {
    return ::tan(args[0]);
}
double tanh(const std::vector<double>& args) {
    return ::tanh(args[0]);
}
double asin(const std::vector<double>& args) {
    return ::asin(args[0]);
}
double asinh(const std::vector<double>& args) {
    return ::asinh(args[0]);
}
double acos(const std::vector<double>& args) {
    return ::acos(args[0]);
}
double acosh(const std::vector<double>& args) {
    return ::acosh(args[0]);
}
double atan(const std::vector<double>& args) {
    return ::atan(args[0]);
}
double atanh(const std::vector<double>& args) {
    return ::atanh(args[0]);
}
double log2(const std::vector<double>& args) {
    return ::log2(args[0]);
}
double log10(const std::vector<double>& args) {
    return ::log10(args[0]);
}
double sqrt(const std::vector<double>& args) {
    return ::sqrt(args[0]);
}
double cbrt(const std::vector<double>& args) {
    return ::cbrt(args[0]);
}
double ceil(const std::vector<double>& args) {
    return ::ceil(args[0]);
}
double floor(const std::vector<double>& args) {
    return ::floor(args[0]);
}
double round(const std::vector<double>& args) {
    return ::round(args[0]);
}

double pow(const std::vector<double>& args) {
    return ::pow(args[0], args[1]);
}
double abs(const std::vector<double>& args) {
    return ::fabs(args[0]);
}
double mod(const std::vector<double>& args) {
    return ::fmod(args[0], args[1]);
}
double log(const std::vector<double>& args) {
    if (args.size() == 1) {
        return ::log(args[0]);
    } else {
        return ::log(args[0]) / ::log(args[1]);
    }
}

}

using namespace common_functions;
MathCommonFunctions::MathCommonFunctions()
    : super
{
    {"sin", {sin, 1, 1} },
    {"sinh", {sinh, 1, 1} },
    {"cos", {cos, 1, 1} },
    {"cosh", {cosh, 1, 1} },
    {"tan", {tan, 1, 1} },
    {"tanh", {tanh, 1, 1} },
    {"asin", {asin, 1, 1} },
    {"asinh", {asinh, 1, 1} },
    {"acos", {acos, 1, 1} },
    {"acosh", {acosh, 1, 1} },
    {"atan", {atan, 1, 1} },
    {"atanh", {atanh, 1, 1} },
    {"log2", {log2, 1, 1} },
    {"log10", {log10, 1, 1} },
    {"sqrt", {sqrt, 1, 1} },
    {"cbrt", {cbrt, 1, 1} },
    {"ceil", {ceil, 1, 1} },
    {"floor", {floor, 1, 1} },
    {"round", {round, 1, 1} },

    /* Functions with special implementations (>1 parameter) */
    {"pow", {pow, 2, 2} },
    {"abs", {abs, 1, 1} },
    {"mod", {mod, 2, 2} },
    {"log", {log, 1, 2} },
} {}
