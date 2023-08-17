#include "main.h"

char **tokens(char *str, char *del)
{
    char **tok = NULL;
    int len = 0;
    int n_tokens = 0;
    char *copy = NULL;
    
    copy = strdup(str);
    while (copy[len] != '\0')
    {
        if (copy[len] == del[0] || copy[len + 1] == '\0')
        {
            n_tokens++;
        }
        len++;
    }
    tok = malloc(sizeof(char *) * (n_tokens + 1));
    if (tok == NULL)
    {
        return (NULL);
    }
    len = 0;
    tok[0] = strtok(copy, del);
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

void add_route(char *tok, char **str)
{
    char *PATH = _getenv(environ);
    char **dir;
    int len = 0;
    char *update = NULL;
    int success = 1;

    if (PATH == NULL)
    {
        return;
    }
    dir = tokens(PATH, ":");
    while (dir[len] != NULL)
    {
        update = calloc(strlen(dir[len]) + strlen(tok) + 2, sizeof(char));
        strcat(update, dir[len]);
        strcat(update, "/");
        strcat(update, tok);
        success = _execve(str, update);
        len++;
        free(update);
        if (success == 0)
        {
            break;
        }
    }
    if (success == 3)
    {
        perror("Error");
    }
    free(dir);
}