#include "include/parser.h"

Parser *prs_new(char *buffer)
{
     Parser *p = malloc(sizeof(Parser));

     p->lex = lex_new(buffer);
     p->tk_c = lex_next_token(p->lex);

     return p;
}

void prs_eat(Parser *prs, int tk_id)
{

    printf("%d ", prs->tk_c->id);

    if(prs->tk_c->id != tk_id)
    {
        lex_free(prs->lex);
        free(prs->tk_c);
        free(prs);

        printf("parse error\n");
    }
    else
    {
        prs->tk_c = lex_next_token(prs->lex);
    }
}

AST *prs_parse(Parser *prs)
{
    return prs_expr(prs);
}

AST *prs_expr(Parser *prs)
{
    AST *new_node, *root;

    root = prs_prmtv(prs);

    while(prs->tk_c->id == AND
            || prs->tk_c->id == OR
            || prs->tk_c->id == XOR)
    {
        new_node = ast_new_empty();
        new_node->tk = prs->tk_c;
        new_node->ln = root;
        root = new_node;

        prs_eat(prs, prs->tk_c->id);

        root->rn = prs_prmtv(prs);
    }
    
    return root;
}   

AST *prs_prmtv(Parser *prs)
{
    AST *node;

    switch(prs->tk_c->id)
    {
        case NOT: { node = ast_new_empty();
                    node->tk = prs->tk_c;
                    prs_eat(prs, NOT);
                    node->ln = prs_prmtv(prs);
                    return node;
                  }
        case VAR: { node = ast_new_empty();
                    node->tk = prs->tk_c;
                    prs_eat(prs, VAR);
                    return node;
                  }
        case LPN: { prs_eat(prs, LPN);
                    node = prs_expr(prs);
                    prs_eat(prs, RPN);
                    return node;
                  }
        default:  { return NULL; }
    }

    return node;
}

