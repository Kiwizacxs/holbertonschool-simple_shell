#include "main.h"

char **tokens(char *str)
{
    char **tok = NULL;
    int len = 0;
    int n_tokens = 0;

    while (str[len] != '\0')
    {
        if (str[len] == ' ' || str[len + 1] == '\0')
        {
            n_tokens++;
        }
        len++;
    }
    tok = malloc(sizeof(char *) * n_tokens);
    if (tok == NULL)
    {
        return (NULL);
    }
    len = 1;
    tok[0] = strtok(str, "\n"" ");
    while (len != n_tokens)
    {
        tok[len] = strtok(NULL, "\n"" ");
        len++;
    }
    tok[len] = '\0';
    return (tok);
}

int _execve(char **av)
{
    pid_t child = fork()
    char *bin;

    bin = malloc(strlen(bin) + sizeof(av))
    if (execve(av[0], av, NULL) == -1)
    {
        perror("Error");
    }
   
    return (0);
}