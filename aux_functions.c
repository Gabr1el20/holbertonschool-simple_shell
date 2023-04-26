#include "main.h"

int checkemptiness(char *command)
{
    int i;

    for (i = 0; command[i] != '\0'; i++)
    {
        if (command[i] != ' ')
            return (0);
    }
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
        exit(0);
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
        if (execve(av[0], av, NULL) == -1)
        {
            perror("./shell");
            return (-1);
        }
    }
    else
    {
        wait(&status);
        if (WIFEXITED(status))
            status = WEXITSTATUS(status);
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