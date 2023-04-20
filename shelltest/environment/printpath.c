#include "main.h"

char *_getenv(const char *name);

void print_PATH(void)
{
    char *path_var = _getenv("PATH");
    char *copy = NULL;
    char *dir = NULL;

    if (path_var == NULL)
    {
        printf("Variable de entorno PATH no encontrada\n");
        return;
    }
    copy = strdup(path_var);
    if (copy == NULL)
    {
        printf("Fallo al alocar memoria\n");
        return;
    }
    dir = strtok(copy, ":");
    while (dir != NULL)
    {
        printf("%s\n", dir);
        dir = strtok(NULL, ":");
    }
    free(copy);
}

int main(void)
{
    print_PATH();
    return (0);
}