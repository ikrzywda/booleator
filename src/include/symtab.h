#ifndef SYMTAB_H
#define SYMTAB_H

#include "AST.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Map Map;

struct Map
{
    Map *ln;
    Map *rn;
    char sym;
    unsigned val, offset;
};

Map *map_new();

Map *map_search(Map *tgt, char sym);

int map_insert(Map *tgt, char sym, int offset);

typedef struct Symtab Symtab;

struct Symtab
{
    unsigned size;
    Map *symbols;
    unsigned values;
};

Symtab *st_new();

void st_insert(Symtab *tgt, char sym);

int st_lookup(Symtab *src, char sym);

#endif
