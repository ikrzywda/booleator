#include "include/token.h"

Token *token_new(unsigned id, unsigned offset)
{
    Token *tok = malloc(sizeof(Token));
    tok->id = id;
    tok->offset = offset;
    return tok;
}
