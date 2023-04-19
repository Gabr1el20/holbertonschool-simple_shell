#include "main.h"


int main(int ac, char *argv[])
{
	char *prompt = NULL, *copy = NULL;
	size_t tam = 0;
	ssize_t read;
	const char *del = " \n";


	while(1)
	{
		printf("SH: ");
		read = getline(&prompt, &tam, stdin);
		if (read == -1)
		{
			printf("Saliendo ...\n");
			sleep(1);
			exit(1);
		}
		printf("%s\n", prompt);
	}
	free(prompt);
	return (0);
}
