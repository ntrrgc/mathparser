#ifndef MATHDRIVER_HPP
#define MATHDRIVER_HPP

#include <bison/MathParser.tab.hpp>
namespace ast { class Node; }

#define YY_DECL                                     \
    yy::MathParser::token_type                      \
    yylex (yy::MathParser::semantic_type* yylval,   \
           yy::MathParser::location_type* yylloc,   \
           MathDriver& driver,                      \
           void * yyscanner)
YY_DECL;

struct yy_buffer_state;
typedef yy_buffer_state * YY_BUFFER_STATE;

#include <memory>
#include <string>
#include <sstream>
#include <set>
#include <map>

class MathDriver
{
public:
    MathDriver(const std::map<std::string, const double>& constants,
               const std::map<std::string, const ast::Function>& functions,
               const std::set<std::string>& allowedVariableNames);
    virtual ~MathDriver();

    void* yyscanner;

    std::string buffer;
    YY_BUFFER_STATE bufferState;

    bool errorBit;
    std::ostringstream errorBuffer;

    const std::map<std::string, const double>* constants;
    const std::map<std::string, const ast::Function>* functions;
    const std::set<std::string>* allowedVariableNames;

    std::shared_ptr<ast::Node> result;

    void scan_begin();
    void scan_end();
    bool trace_scanning;

    bool parse(const std::string& expr);
    bool trace_parsing;

    void error(const yy::location& l, const std::string& m);
    void error(const std::string& m);
};

#endif // MATHDRIVER_HPP
