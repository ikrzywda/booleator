#include "include/token.h"


Token *new_token(int id, char var_name)
{
    Token *token = malloc(sizeof(Token));

    token->id = id;
    token->var_name = var_name;

    return token; 
}

void delete_token(Token *token)
{
    free(token);
}

void print_token(Token *token)
{
    char token_name[4];

    switch(token->id)
    {
        case VAR:    { strncpy(token_name, "VAR\0", 4); break; }
        case AND:    { strncpy(token_name, "AND\0", 4); break; }
        case OR:     { strncpy(token_name, "OR\0", 4); break; }
        case XOR:     { strncpy(token_name, "XOR\0", 4); break; }
        case NOT:    { strncpy(token_name, "NOT\0", 4); break; }
        case LPAREN: { strncpy(token_name, "(\0", 4); break; }
        case RPAREN: { strncpy(token_name, ")\0", 4); break; }
        case END: { strncpy(token_name, "END\0", 4); break; }
        default: { printf("undefined token id\n"); exit(1); }
    }

    printf("{%s, %c}\n", token_name, token->var_name);
}
