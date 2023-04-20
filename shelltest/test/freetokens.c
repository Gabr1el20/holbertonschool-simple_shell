#include "main.h"

void free_tokens(char **av)
{
    int i;
    
    for (i = 0; av[i] != NULL; i++)
    {
        free(av[i]);
    }
    free(av);
}