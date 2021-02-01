#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "AST.h"

#include <stdlib.h>

typedef struct Parser Parser;

struct Parser
{
    Lexer *lex;
    Token *tk;
};

Parser *prs_new(Lexer *lex);

AST *prs_parse(Parser *prs);

AST *prs_expr(Parser *prs);

AST *prs_prmtv(Parser * prs);

void prs_eat(Parser *prs);

#endif
