#include "main.h"

void create_tokens(char *command, char **av, const char *delim)
{
    int i = 0;
    char *token = strtok(command, delim);
    while(token != NULL)
    {
        av[i] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(av[i], token);
        token = strtok(NULL, delim);
        i++;
    }
    av[i] = NULL;
}