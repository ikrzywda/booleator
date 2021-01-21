#ifndef PARSER_H
#define PARSER_H

#include "AST.h"
#include "token.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Input Input;

struct Input
{
    char *in;
    unsigned pos;
};

Input *new_input(char *dt);

void test_lexer(char *input);

Token *get_token(Input *input);

void devour(Input *src, int tk_id);

AST *parse(char *in);

AST *expr(Input *src);

AST *terminal(Input *src);

#endif
