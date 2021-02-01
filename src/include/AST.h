#ifndef AST_H
#define AST_H
   
#include "token.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct AST AST;

struct AST
{
    AST *ln;
    AST *rn;
    Token *tk;
};

AST *ast_new(AST *ln, AST *rn, Token *tk);

AST *ast_new_empty();

void ast_free(AST *ast);

#endif
