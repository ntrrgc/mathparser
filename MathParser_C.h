/* Minimal C API */

#ifndef MATHPARSER_C_H
#define MATHPARSER_C_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MathParser MathParser;
typedef struct MathExpression MathExpression;


/* MathParser class */
MathParser * MathParser_new();
void MathParser_delete(MathParser * self);
void MathParser_allowedVariableNames_add(MathParser * self, const char * varname);

MathExpression * MathParser_compileExpression(MathParser * self, const char * expr, char **dstErrorStr);


/* MathExpression class */

void MathExpression_delete(MathExpression *self);

double MathExpression_variable(const MathExpression * self, const char * name);
void MathExpression_setVariable(MathExpression * self, const char * name, double value);

double MathExpression_value(const MathExpression * self);
double MathExpression_valueWith(MathExpression * self, const char * variableName, double variableValue);


#ifdef __cplusplus
}
#endif

#endif // MATHPARSER_C_H
