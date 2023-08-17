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
	ssize_t characters = 0;
	char *lineptr = NULL;
	char **tok = NULL;

	while (1)  /* Bucle infinito */
	{
		printf("%s", prompt);  /* Imprime el indicador del comando */
		characters = getline(&lineptr, &n, stdin);
		if (characters == -1)
			break;
		
		if (strcmp(lineptr, "exit\n") == 0)
		{
			free(lineptr);
			return(0);
		}

		if (check_lineptr(lineptr) != NULL)
		{
			tok = tokens(lineptr, " \n\t");
			if (tok == NULL)
			{
				free(lineptr);
				continue;
			}
			else if (_execve(tok, tok[0]) == 3)
			{
				if (add_route(tok) == 3)
				{
					perror("Error");
				}
				free(tok);
				continue;
			}
			free(tok);
		}
	}
	free(lineptr);
	return (0);  /* Termina el programa con éxito */
}
