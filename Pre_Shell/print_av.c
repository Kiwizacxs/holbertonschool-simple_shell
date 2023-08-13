#include "main.h"

int main(int ac, char **av)
{
    int i = 0;

    (void)ac;
    while(av[i] != NULL)
    {
        printf("%s", av[i]);
        if (av[i + 1] != NULL)
        {
            putchar (' ');
        }
        i++;
    }
    putchar ('\n');
    return (0);
}
