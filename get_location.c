#include "main.h"
/**
 * get_path - function to get the path
 * @command: given a command, find the path
 * Return: the PATH of the command if it exists, NULL otherwise.
*/
char *get_path(char *command)
{
	char *path_env = _getenv("PATH"), *path = NULL;
	char *token, *path_copy;
	struct stat buffer;

	path_copy = strdup(path_env);
	token = strtok(path_copy, ":");

	while (token)
	{
		path = malloc(strlen(token) + strlen(command) + 2);
		if (!path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(path, "%s/%s", token, command);
		if (stat(path, &buffer) == 0)
		{
			free(path_copy);
			return (path);
		}
		free(path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
