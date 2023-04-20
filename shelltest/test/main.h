#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


void readcom(char **command, size_t *len);
int count_tokens(char *command, const char *delim);
void create_tokens(char *command, char **av, const char *delim);
void exq(char **av);
void free_tokens(char **av);
