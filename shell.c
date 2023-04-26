#include "main.h"

int main(int ac, char **av)
{
	char *command = NULL, *copycom = NULL;
	const char *delim = " \n";
	int tokens = 0;

	(void) ac;

	while (1)
	{
		isatty(0) == 1? write(1, "$ ", 2) : 0;
		command = readcom();
		if (command == NULL || strlen(command) == 1)
		{
			continue;
		}
		copycom = malloc(sizeof(char) * strlen(command) + 1);
		if (copycom == NULL)
		{
			free(command);
			free(copycom);
			perror("./shell");
			return (-1);
		}
		strcpy(copycom, command);
		tokens = count_tokens(command, delim) + 1;
		av = malloc(sizeof(char *) * tokens);
		if (av == NULL)
		{
			free(command);
			free(av);
			perror("./shell");
			return (-1);
		}
		create_tokens(copycom, av, delim);  /*delimitar*/
		exq(av); /*ejecutar*/
		free(copycom);
		free(command);
	}
	return (0);
}
