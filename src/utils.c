#include "include/utils.h"

void command_prompt()
{
    char *in;

    while(1)
    {
        printf(">> ");
        in = input(50);
        parse(in);
        free(in);
    }
}

char *input(unsigned input_length)
{
    char *buffer = malloc(sizeof(char) * input_length), c;
    int i = 0;

    while((c = getc(stdin)) != '\n' && i < input_length)
    {
        *(buffer + i) = c;
        ++i; 
    }

    *(buffer + i) = '\0';

    return buffer;
}

