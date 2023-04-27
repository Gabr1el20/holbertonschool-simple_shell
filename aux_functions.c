#include "main.h"

int checkemptiness(char *command)
{
    int i;

    for (i = 0; command[i] != '\0'; i++)
    {
        if (command[i] != ' ' && command[i] != '\n' && command[i] != '\t')
            return (0);
    }
    free(command);
    return (1);
}

char **splitter(char *command)
{
	char *token, *copia, **argus;
	int wc = 0, count = 0, lupe = 0;
    const char *delim = " \n\t";

    while (command[lupe] != '\0')
    {
        if (command[lupe] == '\n' || command[lupe] == '\t' || command[lupe] == ' ')
        {
            lupe++;
            wc++;
            continue;
        }
        lupe++;
    }
    argus = malloc(sizeof(char *) * (wc + 1));
    if (!argus)
    {
        free(argus);
        perror("./shellmalloc");
        return NULL;
    }
    copia = strdup(command);
    token = strtok(copia, delim);
    while (token)
    {
        argus[count] = strdup(token);
        token = strtok(NULL, delim);
        count++;
    }
    argus[count] = NULL;
    free(copia);
    return (argus);
}

int exq(char **av)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1)
    {
        perror("error");
        return (-1);
    }
    else if (pid == 0)
    {
        if (execve(av[0], av, environ) == -1)
        {
            perror("./shell");
            exit(EXIT_FAILURE);
        }
        return (0);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            status = WEXITSTATUS(status);
        }
        if (status == 0)
        {
            return (0);
        }
    }
    return (status);
}

void free_token(char **av)
{
    int i = 0;

    for (; av[i] != NULL; i++)
    {
        free(av[i]);
    }
    free(av);
}