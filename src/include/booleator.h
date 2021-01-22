#ifndef BTOR_H
#define BTOR_H

#include "parser.h"
#include "symtab.h"

typedef struct BtorData BtorData;

struct BtorData
{
    AST *tree;
    Symtab *st;
};

BtorData *btd_new(AST *tree, Symtab *st);

void btor_run(BtorData *dt);

unsigned btor_compute(BtorData *dt, unsigned key);

void print_row(unsigned val);

#endif
