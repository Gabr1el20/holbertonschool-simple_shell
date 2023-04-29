#include "main.h"
/**
 * main - main function
 * @ac: count of args.
 * @av: args.
 * Return: 0 on success, 1 on fail.
*/
int main(int ac __attribute__((unused)), char *av[])
{
	char *comando = NULL, **argus, *com = NULL;
	size_t bufsize = 0;
	int status = 0, count = 0, buffer = 0;
	struct stat st;

	while (1)
	{
		count++;
		isatty(0) == 1 ? write(1, "$ ", 2) : 0;
		buffer = getline(&comando, &bufsize, stdin);
		if (buffer == -1 || strcmp(comando, "exit\n") == 0)
			free(comando), exit(EXIT_SUCCESS);
		if (comando[buffer - 1] == '\n')
			comando[buffer - 1] = '\0';
		if (strlen(comando) == 1)
			continue;
		if (checkemptiness(comando) == 1)
			continue;
		argus = splitter(comando);
		if (argus && argus[0])
		{
			if (stat(argus[0], &st) == 0)
				com = argus[0], status = exq(com, argus);
			else if (stat(argus[0], &st) == -1)
			{
				com = get_path(argus[0]);
				if (com)
					status = exq(com, argus), free(com), status == -1 ? status = 2 : 0;
			}
			else
			{
				_perror(av[0], count, comando), status = 2;
			}
		}
	}
	if (buffer == -1 || strcmp(comando, "exit\n") == 0)
	{
		free(comando);
		return (status);
	}
}