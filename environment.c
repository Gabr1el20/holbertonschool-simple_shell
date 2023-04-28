#include "main.h"
/**
 * _getenv - gets the environment
 * @directory: direc of the environment variable
 * Return: Direction of the environment variable, plus 1 for the '\0'.
 * NULL otherwise
*/
char *_getenv(char *directory)
{
	char **env = environ;
	int i = 0;
	size_t length = strlen(directory);


	while (env[i])
	{
		if (strncmp(env[i], directory, length) == 0 && env[i][length] == '=')
		{
			return (&(env[i][length + 1]));
		}
		i++;
	}
	return (NULL);
}
