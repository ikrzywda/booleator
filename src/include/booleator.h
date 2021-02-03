#ifndef BTOR_H
#define BTOR_H

#include "AST.h"
#include "token.h"
#include "parser.h"
#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>

void run();

void compute(char *buffer);

char *get_buffer_cli();

char *get_buffer_file(char *fpath);

#endif
