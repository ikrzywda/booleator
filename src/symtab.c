#include "include/symtab.h"

Map *map_new()
{
    Map *m = malloc(sizeof(Map));
    m->ln = m->rn = NULL;
    return m;
}

Map *map_search(Map *tgt, char sym)
{
    if(tgt == NULL) return NULL;

    if(sym < tgt->sym)
        return map_search(tgt->ln, sym);
    else
        return map_search(tgt->rn, sym);
}

// implement self-balancing tree

int map_insert(Map *tgt, char sym, int offset)
{
    if(map_search(tgt, sym) == NULL) return 0;
    
    if(tgt->sym < sym)
    {
        if(tgt->ln == NULL)
        {
            tgt->ln = map_new();
            tgt->ln->sym = sym;
            tgt->ln->offset = offset;
            return 1;
        }
        map_insert(tgt->ln, sym, offset);
    }
    else
    {
        if(tgt->rn == NULL)
        {
            tgt->rn = map_new();
            tgt->rn->sym = sym;
            tgt->rn->offset = offset;
            return 1;
        }
        map_insert(tgt->rn, sym, offset);
    }

    return 0;
}

Symtab *st_new()
{
    Symtab *s = malloc(sizeof(Symtab)); 

    s->symbols = map_new();
    s->values = 0;
    s->size = 0;

    return s;
}

void st_insert(Symtab *tgt, char sym)
{
    if(!map_insert(tgt->symbols, sym, tgt->size))
        tgt->size++;
}

int st_lookup(Symtab *src, char sym)
{
    int pos = map_search(src->symbols, sym)->val;
    return (src->values & (1 << pos)) > 0 ? 1 : 0; 
}
