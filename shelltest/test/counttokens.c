#include "main.h"

int count_tokens(char *command, const char *delim)
{
    char *token = NULL;
    int argstok = 0;

    token = strtok(command, delim);
    while (token != NULL)
    {
        argstok++;
        token = strtok(NULL, delim);
    }
    return (argstok);

}