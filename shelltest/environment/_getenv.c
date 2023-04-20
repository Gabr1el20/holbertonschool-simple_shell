#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
    int name_len = 0;
    char **env = environ;

    name_len = strlen(name);

    for (env = environ; *env != NULL; env++)
    {
        if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
        {
            return (&(*env)[name_len + 1]);
        }
    }
    return (NULL);
}

