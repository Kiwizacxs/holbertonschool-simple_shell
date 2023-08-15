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
    tok[0] = strtok(str, "\n\t ");
    while (len != n_tokens)
    {
        tok[len] = strtok(NULL, "\n\t ");
        len++;
    }
    tok[len] = '\0';
    return (tok);
}

int _execve(char **av)
{
    struct stat st;
    pid_t child;
    int status;
    char *PATH = NULL;
    
    if (stat(av[0], &st) == -1)
    {
        free(av);
        perror("error");
        return (3);
    }

    PATH = _getenv(environ);
    printf("%s\n", PATH);
    child = fork();

    if (child == -1)
    {
        perror("Error");
        return(-1);
    }
    else if (child == 0)
    {
        if (strncmp("/bin/", av[0], 5) == 0)
        {
            if (execve(av[0], av, NULL) == -1)
            {
                perror("error");
            }
        }
    }
        else
        {
            wait(&status);
        }
    return (0);
}

char *_getenv(char **env)
{
    char *PATH = NULL;
    int len = 0, index = 0, i = 0;
    char find[6];

    while (env[len] != NULL)
    {
        while (index != 6)
        {
            find[index] = env[len][index];
            index++;
        }
        find[index] = '\0';
        if (strncmp(find, "PATH=", 5) == 0)
        {
            PATH = malloc(strlen(env[len]) + 4);
            index = 5;
            while (env[len][index] != '\0')
            {
                PATH[i] = env[len][index];
                index++;
                i++;
            }
            PATH[index] = '\0';
            break;
        }
        else
        {
            index = 0;
        }
        len++;
    }
    return (PATH);
}