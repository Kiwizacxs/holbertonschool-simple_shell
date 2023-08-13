#ifndef SHELL
#define SHELL

/*necessaries libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*prototypes functions*/
int _execve(char **av);
char **tokens(char *str);

#endif
