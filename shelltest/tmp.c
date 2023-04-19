#include "main.h"

int main(void)
{
	int i, status;
	char *argv[] = {"/bin/ls", "-l", ".", NULL};

	for (i = 0; i < 5; i++)
	{
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("Error:");
		}
		else if (pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
