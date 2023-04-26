#include "main.h"

int count_tokens(char *command, const char *delim)
{
	char *token = NULL;
	int argstok = 0;

	token = strtok(command, delim);
	while (token != NULL)
	{
		argstok++;
		token = strtok(NULL, delim);
	}
	return (argstok);
}

void create_tokens(char *command, char **av, const char *delim)
{
	int i = 0;
	char *token = strtok(command, delim);

	while (token != NULL)
	{
<<<<<<< HEAD
		av[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (av[i] == NULL)
		{
			fprintf(stderr, "Out of memory\n");
			exit(EXIT_FAILURE);
		}
=======
		av[i] = malloc(sizeof(char) * (strlen(token)));
>>>>>>> 9083cd00c005677854b1af4a7a605bcd22226834
		strcpy(av[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	av[i] = NULL;
}

void free_tokens(char **av)
{
	int i;

	for (i = 0; av[i] != NULL; i++)
	{
		free(av[i]);
	}
	free(av);
}
