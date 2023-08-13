#include "main.h"

int
main (void)
{
    size_t n = 0;
    char *newline;

    printf("$ ");
    getline(&newline, &n, stdin);
    tokens(newline);
    free(newline);
    return (0);
}