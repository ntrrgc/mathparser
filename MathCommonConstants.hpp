#ifndef MATHCOMMONCONSTANTS_HPP
#define MATHCOMMONCONSTANTS_HPP

#include <map>
#include <string>

class MathCommonConstants : public std::map<std::string, const double>
{
    typedef std::map<std::string, const double> super;
public:
    MathCommonConstants();
};

#endif // MATHCOMMONCONSTANTS_HPP
