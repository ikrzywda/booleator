#include "include/calc.h"

void clc_interpret(AST *ast, unsigned size)
{
    while(size >= 0)
    {
        clc_calc_row(ast, size);
    }
}

void clc_calc_row(AST *ast, unsigned key)
{
    bool out = clc_binop(ast, key);
    
    
}

bool clc_binop(AST *ast, unsigned key);

bool clc_not(AST *ast, unsigned key);
