#include "main.h"
/**
 * refcommand - function to refine the command and manipulate its exit value
 * @command: first value of the array of strings
 * @splitted: args
 * @count: this is for the error message.
 * Return: 0 on succes, 2 or 127 depending the error.
*/
int refcommand(char *command, char **splitted, int count, char *av[])
{
	char *first = NULL;
	struct stat st;
	int exitcode = 0;

	if (splitted && splitted[0])
	{
		if (stat(splitted[0], &st) == 0)
		{
			first = splitted[0];
			exitcode = exq(first, splitted);
		}
		else if (stat(splitted[0], &st) == -1)
		{
			first = get_path(splitted[0]);
			if (first)
			{
				exitcode = exq(first, splitted);
				if (exitcode == -1)
				{
					exit(2);
				}
			}
			else
			{
				_perror(av[0], count, command);
				exit(127);
			}
			free(first);
		}
	}
	return (exitcode);
}
