#include "main.h"

char *readcom()
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&command, &len, stdin);
	if (read == -1)
	{
		free(command);
		perror("./shell");
		return (NULL);
	}
	return (command);
}