#include "main.h"

void exq(char **av)
{
	char *comando = NULL, *PATH_com = NULL;
	pid_t pid;
	int status;

	if (av)
	{
		comando = av[0];

		while ((PATH_com = getpath(comando)))
		{
			pid = fork();
			if (pid == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				if (execve(PATH_com, av, NULL) == -1)
				{
					perror("./shell");
					return;
				}
			}
			else
			{
				wait(&status);
				free(PATH_com);
				av[0] = NULL;
				break;
			}
		}
		if (!PATH_com)
		{
			perror("errorr");
			return;
		}
	}
}