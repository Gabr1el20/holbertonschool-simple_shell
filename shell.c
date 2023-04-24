#include "main.h"

/**
 * main - main function
 * @ac: count of args.
 * @av: Args
 *
 * Return: 0 (always success)
*/

int main(int ac, char **av)
{
	char *command = NULL, *copycom = NULL;
	const char *delim = " \n";
	int tokens = 0;

	(void) ac;

	while (1)
	{
		command = readcom();  /*leer la entrada*/
		copycom = malloc(sizeof(char) * strlen(command) + 1);
		if (copycom == NULL)
		{
			free(copycom);
			perror("./shell");
			return (-1);
		}
		strcpy(copycom, command);
		tokens = count_tokens(command, delim) + 1;
		av = malloc(sizeof(char *) * tokens);
		if (av == NULL)
		{
			free(av);
			perror("./shell");
			return (-1);
		}
		create_tokens(copycom, av, delim);  /*delimitar*/
		exq(av); /*ejecutar*/
		free_tokens(av);
		free(copycom);
		free(command);
	}
	return (0);
}

