#ifndef PARSER_H
#define PARSER_H

#include "AST.h"
#include "symtab.h"
#include "token.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct ParseData ParseData;

struct ParseData
{
    char *in;
    unsigned pos;
    Token *tk_c;    
    Symtab *st;
};

ParseData *prsdt_new(char *dt);

void test_lexer(char *input);

Token *get_token(ParseData *input);

void devour(ParseData *src, int tk_id);

AST *parse(char *in);

AST *expr(ParseData *src);

AST *terminal(ParseData *src);

#endif
