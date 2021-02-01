#include "include/symtab.h"

Map *map_new(char sym, char offset)
{
    Map *map = malloc(sizeof(Map));

    map->ln = NULL;
    map->sym = sym;
    map->offset = offset;
    map->rn = NULL;

    return map;
}

Map *map_new_empty()
{
    Map *map = malloc(sizeof(Map));

    map->ln = NULL;
    map->rn = NULL;

    return map;
}

void map_free(Map *map)
{
    if(map == NULL) return;

    map_free(map->ln);
    map_free(map->rn);
    free(map);
}

char map_lookup(Map *map, char sym)
{
    if(map == NULL) return -1;
    
    if(map->sym == sym) return map->offset;
    else if(sym < map->sym) return map_lookup(map->ln, sym);
    else return map_lookup(map->rn, sym);
}

void map_insert(Map *map, char sym, char offset)
{
    if(map == NULL) map = map_new(sym, offset); 

    if(map->sym < sym) map_insert(map->ln, sym, offset);
    else if(map->sym > sym) map_insert(map->rn, sym, offset);
    else if(map->sym == sym) return;
}
