#include "main.h"

int main(int ac, char *av[])
{
    char *command = NULL, *copia = NULL;
    size_t len = 0;
    const char *delim = "\t\n ";
    int count;
    ssize_t read;

    (void)ac;

    while(1)
    {
        command = readcom();
    }
}