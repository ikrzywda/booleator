#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Token Token;
struct Token
{
    enum
    {
        VAR, AND, OR, XOR, NOT, LPAREN, RPAREN, END
    }id; 
        /* DO NOT CHANGE THE ORDER OF id!!! */
    char var_name;
};

Token *new_token(int id, char var_name);

void delete_token(Token *token);

void print_token(Token *token);

#endif
