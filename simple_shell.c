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
	char **tok = NULL;
	/*char *PATH = _getenv(environ);*/


	while (1)  /* Bucle infinito */
	{
		printf("%s", prompt);  /* Imprime el indicador del comando */
		characters = getline(&lineptr, &n, stdin);
		if (characters == -1)
		{
			break;
		}
		/**
		printf("%c\n", PATH[79]);
		printf("%ld", strlen(PATH));
		free(PATH);
		*/
		if (strcmp(lineptr, "exit\n") == 0)
		{
			break;
		}
		tok = tokens(lineptr, " \n\t");
		if (_execve(tok, tok[0]) == 3)
		{
			perror("Error");
			continue;
		}
		free(tok[0]);
		free(tok);
	}
	free(lineptr); /*libera lineptr*/
	return (0);  /* Termina el programa con éxito */
}
