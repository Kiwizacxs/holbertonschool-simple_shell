#include "main.h"

char **tokens(const char *str, char *del)
{
    char **tok = NULL;
    int len = 0;
    int n_tokens = 0;
    char *copy = strdup(str);

    while (copy[len] != '\0')
    {
        if (copy[len] == del[0] || copy[len + 1] == '\0')
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
    tok[0] = strtok(copy, del);
    while (len != n_tokens)
    {
        tok[len] = strtok(NULL, del);
        len++;
    }
    return (tok);
}

int _execve(char **av, char *av_zero)
{
    struct stat st;
    pid_t child;
    int status;
    
    if (stat(av_zero, &st) == -1)
    {
        free(av_zero);
        free(av);
        return (3);
    }
    child = fork();

    if (child == -1)
    {
        perror("Error");
        return(-1);
    }
    else if (child == 0)
    {
        if (execve(av_zero, av, NULL) == -1)
        {
            perror("error");
        }
    }
    else
    {
        wait(&status);
    }
    free(av[0]);
    free(av);
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

/**
int add_route(char **str)
{
    char *PATH = _getenv(environ);
    char **dir = tokens(PATH, ":");
    int len = 0;
    int success = 1;
    char *upgrade = NULL;

    while (success != 0 || dir[len] != NULL)
    {
        upgrade = malloc(strlen(str[0]) + strlen(dir[len]) + 2);
        strcpy(upgrade, dir[len]);
        strcat(upgrade, str[0]);
        success = _execve(str, upgrade);
        len++;
        free(upgrade);
    }
    return (0);
}
*/