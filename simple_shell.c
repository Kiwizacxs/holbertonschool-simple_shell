#include "main.h"

/**
* main - function for a simple command-line interface.
*
* @return Returns 0 to indicate successful termination.
*/


int main(void)
{
	char *prompt = "#cisfun$ "; /*Cadena que representa el indicador del comando*/
	size_t n = 0;
	int characters;
	char *lineptr;

	while (1)  /* Bucle infinito */
	{
		printf("%s", prompt);  /* Imprime el indicador del comando */
		characters = getline(&lineptr, &n, stdin);
		if (characters == -1)
		{
			break;
		}
		if (strcmp(lineptr, "exit\n") == 0)
		{
			break;
		}

	}
	free(lineptr); /*libera lineptr*/
	return (0);  /* Termina el programa con éxito */
}
