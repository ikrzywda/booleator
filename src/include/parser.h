#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "AST.h"

#include <stdlib.h>

typedef struct Parser Parser;

struct Parser
{
    Lexer *lex;
    Token *tk_c;
};


Parser *prs_new(char *buffer);

void prs_eat(Parser *prs, int tk_id);

AST *prs_parse(Parser *prs);

AST *prs_expr(Parser *prs);

AST *prs_prmtv(Parser * prs);


#endif
