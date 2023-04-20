#include "main.h"

void exq(char **argv)
{
    char *command = NULL;

    if (argv)
    {
        command = argv[0];

        if (execve(command, argv, NULL) == -1)
        {
            perror("./shell");
        }
    }
}