#ifndef SHELL
#define SHELL

/*necessaries libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*prototypes functions*/
extern char **environ;
int _execve(char **av);
char **tokens(char *str);
char *_getenv(char **env);
#endif
