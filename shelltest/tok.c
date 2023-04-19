#include "main.h"
#include <string.h>

int main()
{
	char cadena[] = "Hello there - kenobi";
	char delimitador[] = " -";
	char *token = strtok(cadena, delimitador);

	if (token != NULL)
	{
		while(token != NULL)
		{
			printf("Encontramos un token: %s\n", token);
			token = strtok(NULL, delimitador);
		}
	}
	return 0;
}
