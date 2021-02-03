#include "include/lexer.h"

Lexer *lex_new(char *buffer)
{
    Lexer *lex = malloc(sizeof(Lexer));

    lex->buffer = buffer;
    lex->pos = 0;
    lex->size = 0;
    lex->symtab = map_new_empty();

    return lex;
}

void lex_free(Lexer *target)
{
    map_free(target->symtab);
    free(target->buffer);
    free(target);
}

Token *lex_next_token(Lexer *lex)
{
    Token *out;
    char c = *(lex->buffer + lex->pos);

    while(isspace(c))
    {
        lex->pos++;
        c = *(lex->buffer + lex->pos);
    }

    switch(c)
    {
        case '~': out = token_new(NOT, 0); break;
        case '&': out = token_new(AND,0); break;
        case '|': out = token_new(OR,0); break;
        case '^': out = token_new(XOR,0); break;
        case '(': out = token_new(LPN,0); break;
        case ')': out = token_new(RPN,0); break;
        case '\0': out = token_new(END, 0); break;
        default: out = lex_var(lex, c); break;
    }

    lex->pos++;
    return out;
}

Token *lex_var(Lexer *lex, char c)
{
    unsigned offset;
    if((offset = map_lookup(lex->symtab, c)) >= 0)
        return token_new(VAR, offset); 
    else
    {
        lex->size++;
        map_insert(lex->symtab, c, lex->size);
        return token_new(VAR, lex->size);
    }
}
