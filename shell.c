#include "main.h"
/**
 * main - main function
 * @ac: count of args.
 * @av: args.
 * Return: 0 on success, 1 on fail.
*/
int main(int ac __attribute__((unused)), char *av[] __attribute__((unused)))
{
	char *comando = NULL, **splitted;
	size_t bufsize = 0;
	int status = 0, count = 0, buffer = 0;

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
		splitted = splitter(comando);
		status = refcommand(comando, splitted, count);
	}
	return (status);
}
