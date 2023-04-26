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

char **splitter(char *input)
{
	char *token, *inputcpy, **inputarray;
	int wordcounter = 0, arraycounter = 0, cfinder = 0;


	while (input[cfinder])
	{
		if (input[cfinder] == '\t' || input[cfinder] == '\n' || input[cfinder] == 32)
		{
			cfinder++;
			wordcounter++;
		}
		cfinder++;
	}
	inputarray = malloc(sizeof(char *) * (wordcounter + 1));
	if (inputarray == NULL)
	{
		free(inputarray);
		perror("Malloc error: ");
		exit(-1);
	}
	inputcpy = strdup(input);
	token = strtok(inputcpy, " \t\n");
	for (arraycounter = 0; token; arraycounter++)
	{
		inputarray[arraycounter] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	inputarray[arraycounter] = NULL;
	free(inputcpy);
	return (inputarray);
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