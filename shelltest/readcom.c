#include "main.h"

char *readcom(void)
{
    char *command = NULL;
    size_t size = 0;
    ssize_t read;

    read = getline(&command, &size, stdin);
    if (read == -1)
    {
        return (NULL);
    }
    else
    {
        return (command);
    }
}