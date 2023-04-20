#include "main.h"

void exq(char **av)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("./shell");
    }
    else if (pid == 0)
    {
        execve(av[0], av, NULL);
        perror(":/shell");
        exit(1);
    }
    else
        wait(NULL);
}