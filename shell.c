#include "main.h"
/**
 * main - main function
 * @ac: count of args.
 * @av: args.
 * Return: 0 on success, 1 on fail.
*/
int main(int ac, char *av[])
{
	char *comando = NULL, **argus, *completo = NULL;
	size_t bufsize = 0;
	ssize_t buffer = 0;
	int status = 0, wexit = 0, count = 0;
	struct stat st;

	(void)ac;
	(void)av;
	(void)wexit;
	(void)completo;

	while (1)
	{
		count++;
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
		if (argus && argus[0])
		{
			if (stat(argus[0], &st) == 0)
			{
				completo = argus[0];
				status = exq(completo, argus);
			}
			else if (stat(argus[0], &st) == -1)
			{
				completo = get_path(argus[0]);
				if (completo)
				{
					status = exq(completo, argus);
					free(completo);
					(status == -1) ? status = 2 : 0;
				}
				else
					_perror(av[0], count, comando);
			}
		}
		free_token(argus);
	}
	free(comando);
	return (status);
}
