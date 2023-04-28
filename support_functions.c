#include "main.h"
/**
 * checkemptiness - Function to check if command is empty
 * @command: the command to verify
 * Return: 1 if it is empty, 1 otherwise.
*/
int checkemptiness(char *command)
{
	int i;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] != ' ' && command[i] != '\n' && command[i] != '\t')
			return (0);
	}
	return (1);
}
/**
 * exq - Function to execute the command and its args
 * @completo: command.
 * @argus: argumentos
 * Return: the status of the execve.
*/
int exq(char *completo, char **argus)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid > 0)
	{
		wait(&status);
	}
	else if (pid == 0)
	{
		execve(completo, argus, environ);
	}
	else
	{
		perror("./shell");
		free_token(argus);
	}
	return (WEXITSTATUS(status));
}

/**
 * _perror - prints a message to the stderr
 * @name: command[0]
 * @count: instance of the iteration
 * @command: args.
*/
void _perror(char *name, int count, char *command)
{
	fprintf(stderr, "%s: %d: %s: not found\n", name, count, command);
}
