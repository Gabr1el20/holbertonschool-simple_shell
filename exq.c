#include "main.h"

void exq(char **av)
{
    char *comando = NULL, *PATH_com = NULL;
    pid_t pid;
    int status;

<<<<<<< HEAD
    if (av)
    {
        comando = av[0];

        while ((PATH_com = getpath(comando)) != NULL)
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
                    perror("error");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                waitpid(pid, &status, 0);
                if (PATH_com != NULL)
                {
                    free(PATH_com);
                }
                break;
            }
        }
        if (PATH_com == NULL)
        {
            fprintf(stderr, "Error: command not found: %s\n", av[0]);
            exit(EXIT_FAILURE);
        }
    }
=======
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
>>>>>>> 9083cd00c005677854b1af4a7a605bcd22226834
}