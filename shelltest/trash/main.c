#include "main.h"

char *readcom(void);
char **tokenize(char *command);
void free_tokens(char **tokens, int num_tokens);
void exq(char **tokens);

int main(int ac, char *av[])
{
    char *command;
    char **tokens;
    int num_tokens;
    (void)ac;
    (void)av;

    while(1)
    {
        printf("$ ");
        command = readcom();
        if (command == NULL)
        {
            printf("Exiting...\n");
            sleep(1);
            exit(1);
        }
        tokens = tokenize(command);
        if (tokens != NULL)
        {
            exq(tokens);
        }
        free(command);
    }
    return (0);
}