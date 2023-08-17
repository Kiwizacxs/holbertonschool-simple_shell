#include "main.h"

char **tokens(char *str, char *del)
{
    char **tok = NULL;
    int len = 0;
    int n_tokens = 0;

    while (str[len] != '\0')
    {
        if (str[len] == del[0] || str[len + 1] == '\0')
        {
            n_tokens++;
        }
        len++;
    }
    tok = malloc(sizeof(char *) * (n_tokens + 1));
    if (tok == NULL)
    {
        free(str);
        return (NULL);
    }
    len = 0;
    tok[0] = strtok(str, del);
    while (len < n_tokens)
    {
        len++;
        tok[len] = strtok(NULL, del);
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
        if (execve(av_zero, av, environ) == -1)
        {
            perror("error");
            exit(1);
        }
    }
    else
    {
        waitpid(child, &status, 0);
    }
    return (0);
}

char *_getenv(char **env)
{
    char *PATH = NULL;
    int len = 0, index = 0, i = 0;
    char find[6] = "PATH=";

    while (env[len] != NULL)
    {
        if (strncmp(env[len], find, 5) == 0)
        {
            PATH = malloc(strlen(env[len]) - 4);
            index = 5;
            while (env[len][index] != '\0')
            {
                PATH[i] = env[len][index];
                index++;
                i++;
            }
            PATH[i] = '\0';
            break;
        }
        len++;
    }
    return (PATH);
}

int add_route(char **str)
{
    char *PATH = _getenv(environ);
    char **dir;
    char *update;
    int len = 0;

    dir = tokens(PATH, ":");
    while (dir[len] != NULL)
    {
        update = malloc(strlen(dir[len]) + strlen(str[0]) + 2);
        strcpy(update, dir[len]);
        strcat(update, "/");
        strcat(update, str[0]);
        if (_execve(str, update) == 0)
        {
            free(PATH);
            free(update);
            free(dir);
            return (0);
        }
        free(update);
        len++;
    }
    free(PATH);
    free(dir);
    return (3);
}

char *check_lineptr(char *str)
{
    int len = 0;

    if (strcmp(str, "\n") == 0)
    {
        return (NULL);
    }
    if (str[0] == 9 || str[0] == 32)
    {
        while (str[len] != '\0')
        {
            if (str[len] != 32 && str[len] != 10 && str[len] != 9)
            {
                break;
            }
            len++;
        }
        if (str[len] == '\0')
        {
            return (NULL);
        }
    }
    return (str);
}