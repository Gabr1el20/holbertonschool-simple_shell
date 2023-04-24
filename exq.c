#include "main.h"

void exq(char **av)
{
	char *comando = NULL, *PATH_com = NULL;
	pid_t pid;
	int status;

	if (av)
	{
		comando = av[0];
		PATH_com = getpath(comando);

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
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
}
