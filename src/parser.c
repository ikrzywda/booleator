#include "include/parser.h"

ParseData *prsdt_new(char *in)
{
    ParseData *dt = malloc(sizeof(ParseData));

    dt->in = in;
    dt->pos = 0;
    dt->tk_c = get_token(dt);
    dt->st = st_new();

    return dt;
}

void test_lexer(char *input)
{
    ParseData *dt = prsdt_new(input);
    Token *tk;

    while((tk = get_token(dt))->id != END)
    {
        print_token(tk);
        free(tk);
    }
    
    free(dt);
}

Token *get_token(ParseData *dt)
{
    char *current;
    Token *tk;

    while(1)
    {
        current = dt->in + dt->pos; 
        switch(*current)
        {
            case '~': { dt->pos++; return new_token(NOT, '~');  } 
            case '&': { dt->pos++; return new_token(AND, '&'); } 
            case '|': { dt->pos++; return new_token(OR, '|');  } 
            case '^': { dt->pos++; return new_token(XOR, '^'); } 
            case '(': { dt->pos++; return new_token(LPAREN, '('); } 
            case ')': { dt->pos++; return new_token(RPAREN, ')'); } 
            case '\0':{ dt->pos++; return new_token(END, '.'); }
            default: { break; }
        }
    
        if(isalnum(*current))
        {
            dt->pos++;
            return new_token(VAR, *current);
        }else if(!isspace(*current)) {
             exit(1);
        }
        
        ++dt->pos;
    }

    return tk; 
}

void devour(ParseData *src, int tk_id)
{
    if(src->tk_c->id == tk_id)
        src->tk_c = get_token(src);
    else exit(1); // error to be implemented
}

AST *parse(char *in)
{
    ParseData *src = prsdt_new(in);
    AST *tree = expr(src);
    print_tree(tree, 0);
    delete_tree(tree);
    return NULL;
}

AST *expr(ParseData *src)
{
    AST *root, *new_node;
    root = terminal(src);

    while((src->tk_c->id >= AND || src->tk_c->id <= XOR)
            && (src->tk_c->id != END && src->tk_c->id != RPAREN))
    {
        new_node = new_tree();
        new_node->token = src->tk_c;
        devour(src, src->tk_c->id);
        new_node->ln = root;
        root = new_node;
        root->rn = terminal(src);
    }

    return root;
}   

AST *terminal(ParseData *src)
{
    AST *node;

    switch(src->tk_c->id)
    {
        case VAR: { node = new_tree();
                    node->token = src->tk_c;
                    st_insert(src->st, src->tk_c->var_name);
                    devour(src, VAR);
                    return node;
                  }
        case NOT: { node = new_tree();
                    node->token = src->tk_c;
                    devour(src, NOT);
                    node->ln = terminal(src);
                    return node;
                  }
        case LPAREN:{ devour(src, LPAREN);     
                      node = expr(src);
                      devour(src, RPAREN);
                      return node;
                    }
        case END:   printf("hi"); break;
        default: print_token(src->tk_c);printf("here");exit(1);
    }
    
    return NULL;
}
