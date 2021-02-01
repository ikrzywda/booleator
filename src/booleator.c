#include "include/booleator.h"

const unsigned INPUT_WIDTH = 51;

const char WELCOME_MSG[] = "Welcome to Booleator - a simple boolean algebra calculator\n\
type in an expression to get table of results\n\
'~' - NOT\n\
'&' - AND\n\
'|' - OR\n\
'^' - XOR\n\0";

void run()
{
    printf("%s", WELCOME_MSG);

    while(1)
    {
        printf("\n>>> ");
        compute(get_buffer_cli());
    }
}

void compute(char *buffer)
{
    printf("%s", buffer);
    free(buffer);
}

char *get_buffer_cli()
{
    char *buffer = malloc(INPUT_WIDTH);
    char i = 0, c;
    
    while(i < (INPUT_WIDTH - 1) 
          && (c = getchar()) != '\n')
    {
        *(buffer + i) = c;
        ++i;
    }
    
    *(buffer + INPUT_WIDTH - 1) = '\0';

    return buffer;
}

