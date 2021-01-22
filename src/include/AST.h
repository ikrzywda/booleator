#ifndef AST_H
#define AST_H

#include "token.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AST AST;

struct AST
{
    AST *ln;
    AST *rn;
    Token *token;
};

AST *new_tree();

void delete_tree(AST *t);

void print_tree(AST *t, unsigned offset);

#endif
