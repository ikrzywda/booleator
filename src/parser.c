#include "include/parser.h"

Parser *prs_new(Lexer *lex);

AST *prs_parse(Parser *prs);

AST *prs_expr(Parser *prs);

AST *prs_prmtv(Parser * prs);

void prs_eat(Parser *prs);
