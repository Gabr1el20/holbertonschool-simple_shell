#include "main.h"

extern char **environ;

int main(int ac, char **av[], char **env)
{
    env = NULL;
    printf("Direccion de env: %p\n", (void *)&env);

    char **environ;
    environ = NULL;
    printf("Direccion de environ: %p\n", (void *)&environ);

    return (0);
}
