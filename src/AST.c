#include "include/AST.h"

AST *ast_new(AST *ln, AST *rn, Token *tk)
{
    AST *ast = malloc(sizeof(AST));

    ast->ln = ln;
    ast->rn = rn;
    ast->tk = tk;

    return ast;
}

AST *ast_new_empty()
{
    AST *ast = malloc(sizeof(AST));

    ast->ln = NULL;
    ast->rn = NULL;

    return ast;
}

void ast_free(AST *ast)
{
    if(ast == NULL) return;

    ast_free(ast->ln);
    ast_free(ast->rn);
    free(ast);
}

