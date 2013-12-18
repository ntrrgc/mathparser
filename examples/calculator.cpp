#include <iostream>
#include <memory>
#include <ast/ast.hpp>
#include <cassert>
#include <cmath>
#include <MathParser.hpp>

using namespace std;
using namespace ast;

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}


int main()
{
    MathParser parser;
    //To set variables:
    //parser.allowedVariableNames = { "x" };

    while (1) {
        string input;
        cout << ">> " << flush;
        std::getline(cin, input);

        if (input.empty())
            break;

        try {
            MathExpression expr = parser.compileExpression(input);
            cout << expr.value() << endl;
        } catch (MathParserException &ex) {
            cout << "Error: " << ex.what() << endl;
        }
    }
    return 0;
}

