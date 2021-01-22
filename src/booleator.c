#include "include/booleator.h"

BtorData *btd_new(AST *tree, Symtab *st)
{
    BtorData *btd = malloc(sizeof(BtorData));
    
    btd->tree = tree;
    btd->st = st;

    return btd;
}

void btor_run(BtorData *dt)
{
    int key = dt->st->size;
    
    while(key >= 0)
    {
        print_row(btor_compute(dt, key));
        key--;
    }
}

unsigned btor_compute(BtorData *dt, unsigned key)
{
     
}

void print_row(unsigned val);
