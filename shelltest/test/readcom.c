#include "main.h"

void readcom(char **command, size_t *len)
{
    printf("$ ");
    ssize_t read = getline(command, len, stdin);
    if (read == -1)
    {
        printf("Exiting...\n");
        exit(1);
    }
}