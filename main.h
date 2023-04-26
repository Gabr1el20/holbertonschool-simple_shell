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
int exq(char **av);
void free_token(char **av);

#endif