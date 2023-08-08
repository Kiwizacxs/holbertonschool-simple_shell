#include "usualies.h"

int main(int argc, char **argv)
{
	size_t n = 0;
	char *lineptr = NULL;

	
	(void)argv;
	(void)argc;
	while (1)
	{
		printf("#cisfun$ ");
		getline(&lineptr,&n, stdin);
	}
	free(lineptr);
	return (0);
}
