#include "main.h"

char *readcom()
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&command, &len, stdin);
	if (read == -1)
	{
		free(command);
		printf("Exiting...\n");
		exit(EXIT_FAILURE);
	}
	return (command);
}