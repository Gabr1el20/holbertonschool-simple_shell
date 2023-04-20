#include "main.h"

#define MAX_ARGS 10
#define TOK_DELIM " \n"

char **tokenize(char *command)
{
    char **tokens = NULL;
    char *token;
    int num_tokens;

    tokens = malloc(MAX_ARGS * sizeof(char *));
    if (tokens != NULL)
    {
        perror("./shell");
        exit(EXIT_FAILURE);
    }

    token = strtok(command, TOK_DELIM);
    num_tokens = 0;

    while (token != NULL && num_tokens < MAX_ARGS-1)
    {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, TOK_DELIM);
    }
    tokens[num_tokens] = NULL;

    return (tokens);

}