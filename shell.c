#include "main.h"
/**
 * main - main function
 * @ac: count of args.
 * @av: args.
 * Return: 0 on success, 1 on fail.
*/
int main(int ac, char *av[])
{
	char *comando = NULL, **argus;
	size_t bufsize = 0;
	ssize_t buffer = 0;
	int status = 0, wexit = 0;

	(void)ac;
	(void)av;

	while (1)
	{
		isatty(0) == 1 ? write(1, "$ ", 2) : 0;
		buffer = getline(&comando, &bufsize, stdin);
		if (buffer == -1)
		{
			free(comando);
			exit(EXIT_SUCCESS);
		}
		comando[bufsize - 1] = '\0';
		if (strlen(comando) == 1)
			continue;
		if (checkemptiness(comando) == 1)
		{
			status = 0;
			break;
		}
		argus = splitter(comando);
		if (!argus)
		{
			free_token(argus);
		}
		status = exq(argus);
		if (status == -1)
			exit(EXIT_FAILURE);
		else
		{
			wexit = status;
		}
		free_token(argus);
	}
	return (wexit);
}
