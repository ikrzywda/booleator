#include "include/AST.h"

AST *new_tree(AST *l, AST *r, Token *t)
{
    AST *tree = malloc(sizeof(AST));
    
    tree->ln = NULL;
    tree->rn = NULL;
    tree->token = NULL;

    return tree;
}

void delete_tree(AST *t)
{
    if(t == NULL) return;

    delete_tree(t->ln);
    delete_tree(t->rn);

    free(t->token);
    free(t);
}

void print_tree(AST *t, unsigned offset)
{
    if(t == NULL) return;
    
    print_token(t->token);
    print_tree(t->ln, offset+4); 
    print_tree(t->rn, offset+4); 
}
