#include "include/parser.h"

Token *tk_c;

Input *new_input(char *in)
{
    Input *input = malloc(sizeof(Input));

    input->in = in;
    input->pos = 0;

    return input;
}

void test_lexer(char *input)
{
    Input *dt = new_input(input);
    Token *tk;

    while((tk = get_token(dt))->id != END)
    {
        print_token(tk);
        free(tk);
    }
    
    free(dt);
}

Token *get_token(Input *dt)
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
            case ')': { dt->pos++; return new_token(LPAREN, '('); } 
            case '(': { dt->pos++; return new_token(RPAREN, ')'); } 
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

void devour(Input *src, int tk_id)
{
    if(tk_c->id == tk_id)
        tk_c = get_token(src);
    else exit(1); // error to be implemented
}

AST *parse(char *in)
{
    Input *src = new_input(in);
    tk_c = get_token(src);
    AST *tree = expr(src);
    printf("%d", tree->token->id);
    print_tree(tree, 0);
    delete_tree(tree);
    return NULL;
}

AST *expr(Input *src)
{
    AST *root = malloc(sizeof(AST));
    root->ln = terminal(src);

    while(tk_c->id >= AND || tk_c->id <= XOR)
    {
        root->token = tk_c;
        devour(src, tk_c->id);
        root->rn = terminal(src);
    }

    return root;
}   

AST *terminal(Input *src)
{
    AST *node = malloc(sizeof(AST));

    switch(tk_c->id)
    {
        case VAR: { node->token = tk_c;
                    devour(src, VAR);
                    break;
                  }
        case NOT: { node->token = tk_c;
                    node->ln = terminal(src);
                    break;
                  }
        case LPAREN:{ devour(src, LPAREN);     
                      node = expr(src);
                      devour(src, RPAREN);
                      break;
                    }
        default: printf("here");exit(1);
    }
    
    return node;
}
