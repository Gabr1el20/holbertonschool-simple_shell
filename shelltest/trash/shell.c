#include "main.h"

int main(int ac, char *av[])
{
	char *command = NULL, *copycom = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	const char *delimitator = " \n";
	int tokens = 0, i, status;
	pid_t pid;

	(void)ac;

	while (1)
	{
		printf("# ");
		read = getline(&command, &len, stdin);
		if (read == -1)
		{
			printf("Saliendo...\n");
			sleep(1);
			exit(1);
		}
		copycom = malloc(sizeof(char *) * read);
		if (copycom == NULL)
		{
			perror("./shell:");
			return (-1);
		}
		strcpy(copycom, command);
		token = strtok(command, delimitator);
		while (token != NULL)
		{
			tokens++;
			token = strtok(NULL, delimitator);
		}
		tokens++;

		av = malloc(sizeof(char *) * tokens);

		token = strtok(copycom, delimitator);

		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			if (av[i] == NULL)
			strcpy(av[i], token);
			token = strtok(NULL, delimitator);
		}
		
		av[i] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("Error: PID");
		}
		else if (pid == 0)
		{
			exq(av);
		}
		else
		{
			wait(&status);
		}
	}
	free(copycom);
	free(command);
	return (0);
}