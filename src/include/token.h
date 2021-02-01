#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>

enum ids
{
    NOT, AND, OR, XOR, VAR, END
};

typedef struct Token Token;

struct Token
{
    unsigned id;
    unsigned offset;
};

Token *token_new(unsigned id, unsigned offset);

#endif
