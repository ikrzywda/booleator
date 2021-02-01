#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdlib.h>

typedef struct Map Map;

struct Map
{
    Map *ln, *rn;
    char sym, offset;
};

Map *map_new(char sym, char offset);

Map *map_new_empty();

void map_free(Map *map);

char map_lookup(Map *map, char sym);

void map_insert(Map *map, char sym, char offset);

#endif
