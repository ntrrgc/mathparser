#define _POSIX_C_SOURCE 200809L

#include "MathParser_C.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    MathParser * parser = MathParser_new();

    while (1) {
        char * input = NULL; int input_len; size_t input_capacity = 0;
        printf(">> ");
        fflush(stdout);

        if (-1 == (input_len = getline(&input, &input_capacity, stdin))) {
            if (input) free(input);
            break;
        }

        /* remove trailing '\n' */
        input[input_len-1] = '\0';

        char * error = NULL;
        MathExpression * expr = MathParser_compileExpression(parser, input, &error);
        if (expr) {
            printf("%lg\n", MathExpression_value(expr));
            MathExpression_delete(expr);
        } else {
            printf("Error: %s\n", error);
            free(error);
        }
        free(input);
    }

    MathParser_delete(parser);
    return 0;
}
