#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


char *readcom();
int count_tokens(char *command, const char *delim);
void create_tokens(char *command, char **av, const char *delim);
void exq(char **av);
void free_tokens(char **av);
char *getpath(char *command);