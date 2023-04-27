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
	free(command);
	return (1);
}
/**
 * exq - Function to execute the command and its args
 * @av: the command splitted.
 * Return: the status of the execve.
*/
int exq(char **av)
{
	pid_t pid;
	int status;
	char *command;

	if (av[0][0] == '/')
	{
		command = av[0];
	}
	else
		command = get_path(av[0]);
	pid = fork();
	if (pid == -1)
	{
		perror("error");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(command, av, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
		if (status == 0)
		{
			free(command);
			return (0);
		}
	}
	free(command);
	return (status);
}

