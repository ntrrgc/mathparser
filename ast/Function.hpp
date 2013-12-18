#include <exception>
#include <vector>

#ifndef __ast__Function_hpp__
#define __ast__Function_hpp__

namespace ast
{
    class Function;
}

namespace ast
{
    typedef double (*FunctionDefinition) (const std::vector<double>&);

    class Function
    {
    public:
        Function(FunctionDefinition definition, int minArguments, int maxArguments);

        FunctionDefinition definition;
        int minArguments;
        int maxArguments;

        bool enoughArguments(int howMany) const;
        double call(const std::vector<double>& params) const;
    };
}

#endif
