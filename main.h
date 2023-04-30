#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>


extern char **environ;
int checkemptiness(char *command);
char **splitter(char *input);
int exq(char *completo, char **av);
void free_token(char **av);
char *get_path(char *command);
void _perror(char *name, int count, char *command);
char *_getenv(char *directory);
int refcommand(char *command, char **splitted, int count, char *av[]);

#endif
