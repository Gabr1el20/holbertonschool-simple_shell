#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *_getenv(const char *name);
void print_PATH(void);

typedef struct path_node
{
    char *direc;
    struct path_node *next;
} path_node_t;