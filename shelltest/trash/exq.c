#include "main.h"

void exq(char **tokens)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("./shell");
        exit(1);
    }
    else if (pid == 0)
    {
        if (execve(tokens[0], tokens, NULL) == -1)
        {
            perror("./shell");
            exit(1);
        }
    }
    else
    {
        if(waitpid(pid, &status, 0) == -1)
        {
            perror("./shell");
        }
    }
}