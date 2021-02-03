#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include "symtab.h"

#include <stdlib.h>
#include <ctype.h>

typedef struct Lexer Lexer;

struct Lexer
{
    char *buffer;
    unsigned pos, size;
    Map *symtab;
};

Lexer *lex_new(char *buffer);

void lex_free(Lexer *target);

Token *lex_next_token(Lexer *lex);

Token *lex_var(Lexer *lex, char c);

#endif
