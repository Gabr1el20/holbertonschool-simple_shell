#include "main.h"

int main(int argc, char *argv[])
{
    char *command = NULL;
    size_t len = 0;
    char *copia = NULL;
    char *token = NULL;
    int tokenNum = 0;

    while (1)
    {
        isatty(0) == 1? write(1, "$ ", 2) : 0;

        ssize_t bytesNum = getline(&command, &len, stdin);
        if (bytesNum == -1)
        {
            perror("Error: ");
            exit(1);
        }

        copia = malloc(sizeof(char) * (bytesNum + 1));
        if (copia == NULL)
        {
            perror("Error: ");
            exit(1);
        }
        strcpy(copia, command);
        token = strtok(command, " \n");
        while (token != NULL)
        {
            tokenNum++;
            token = strtok(NULL, " \n");
        }
        tokenNum++;
        char **args = malloc(sizeof(char *) * tokenNum);
        if (args == NULL)
        {
            perror("Error: ");
            exit(1);
        }
        token = strtok(copia, " \n");

        int i;
        for (i = 0; token != NULL; i++)
        {
            args[i] = malloc(sizeof(char) * (strlen(token) + 1));
            if (args[i] == NULL)
            {
                perror("Error: ");
                exit(1);
            }
            strcpy(args[i], token);
            token = strtok(NULL, " \n");
        }
        
        args[i] = NULL;

        printf("%s\n", command);

        free(copia);
        copia = NULL;

        pid_t pid = fork();

        if (pid == -1)
        {
            perror("Error1");
        } 
        else if (pid == 0) 
        {   
            if (execve(args[0], args, NULL) == -1)
            {
                perror("Error2");
                exit(1);
            }
        } 
        else
        {
            wait(NULL);
        }

        for (i = 0; i < tokenNum; i++)
        {
            free(args[i]);
            args[i] = NULL;
        }
        free(args);
        args = NULL;
    }

    free(command);
    command = NULL;

    return 0;
}