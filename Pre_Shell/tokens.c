#include "main.h"

char **tokens(char *str)
{
    char **luis;
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
    luis = malloc(sizeof(char *) * n_tokens + 1);
    if (luis == NULL)
    {
        return (NULL);
    }
    len = 1;
    luis[len] = strtok(str, " ");
    while (len != n_tokens)
    {
            luis[len] = strtok(NULL, " ");
            len++;
    }

    printf("%s", luis[1]);
    
    return (luis);
}