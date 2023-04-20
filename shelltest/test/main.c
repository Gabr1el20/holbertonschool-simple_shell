#include "main.h"

int main(int ac, char *av[])
{
	char *command = NULL, *copycom = NULL;
	size_t len = 0;
	const char *delim = " \n";
	int tokens;
	
	while (1)
	{
		readcom(&command, &len);
		copycom = malloc(sizeof(char) * (strlen(command) + 1));
		if (copycom == NULL)
		{
			perror("./shell");
			return (-1);
		}
		strcpy(copycom, command);
		tokens = count_tokens(command, delim) + 1;
		av = malloc(sizeof(char *) * tokens);
		if (av == NULL)
		{
			perror("./shell");
			return (-1);
		}
		create_tokens(copycom, av, delim);
		exq(av);
		free_tokens(av);
		free(copycom);
	}
	free(command);
	return (0);
}