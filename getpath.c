#include "main.h"

char *getpath(char *command)
{
	char *path = NULL, *copypath = NULL, *tokenp = NULL, *encount = NULL;
	int comlen, dirlen;
	struct stat st;

	path = getenv("PATH");

	if (path)
	{
		copypath = strdup(path);
		comlen = strlen(command);
		tokenp = strtok(path, ":");
		while (tokenp != NULL)
		{
			dirlen = strlen(tokenp);
			encount = malloc(comlen + dirlen + 2);
			if (encount == NULL)
			{
				free(copypath);
				return (NULL);
			}
			
			strcpy(encount, tokenp);
			strcat(encount, "/");
			strcat(encount, command);
			strcat(encount, "\0");

			if (stat(encount, &st) == 0)
			{
				free(copypath);
				return (encount);
			}
			else
			{
				free(encount);
				tokenp = strtok(NULL, ":");
			}
		}
		free(copypath);
		return (NULL);
	}
	return (command);
}