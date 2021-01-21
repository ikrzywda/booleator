#include "include/AST.h"

AST *new_tree(AST *l, AST *r, Token *t)
{
    AST *tree = malloc(sizeof(AST));
    
    tree->ln = l;
    tree->rn = r;
    tree->token = t;

    return tree;
}

void delete_tree(AST *t)
{
    if(t == NULL) return;

    free(t->token);
    free(t->ln);
    free(t->rn);
}

void print_tree(AST *t, unsigned offset)
{
    if(t == NULL) return;
    
    for(unsigned i = offset; i < offset; --i) putc(' ', stdout);
    printf("h\u2560\u2550\u2550");
    print_token(t->token);

    print_tree(t->ln, offset+4); 
    print_tree(t->rn, offset+4); 
    printf("h\u2560\u2550\u2550");
}
