#ifndef _MAIN_H_
#define _MAIN_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void exq(char **argv);
int main (int ac, char *av[]);
char *readcom(void);
char **tokenize(char *command);
void free_tokens(char **tokens, int num_tokens);
void exq(char **tokens);

#endif