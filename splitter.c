#include "main.h"

/**
 * splitter - Function to split the commands and args
 * @command: the command.
 * Return: the command tokenized.
*/
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
		return (NULL);
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

/**
 * free_token - Function to free the splitted args
 * @av: splitted args.
*/
void free_token(char **av)
{
	int i;

	for (i = 0; av[i]; i++)
	{
		free(av[i]);
	}
	free(av);
}
