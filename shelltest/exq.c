#include "main.h"

void exq(char **av)
{
	char *comando = NULL, *PATH_com = NULL;
	
	if (av)
	{
		comando = av[0];

		PATH_com = getpath(comando);
		if (execve(PATH_com, av, NULL) == -1)
		{
			perror("./shell");
		}
	}
}
