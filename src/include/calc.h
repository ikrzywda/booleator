#ifndef CALC_H
#define CALC_H

#include "AST.h"

#include <stdio.h>
#include <stdbool.h>

void clc_interpret(AST *ast, unsigned size);

void clc_calc_row(AST *ast, unsigned key);

bool clc_binop(AST *ast, unsigned key);

bool clc_not(AST *ast, unsigned key);

#endif
