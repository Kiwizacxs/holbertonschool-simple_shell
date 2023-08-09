#include "usualies.h"

/**
*main - function for a simple command-line interface.
*
* Simple command-line program that allows users to input and process commands.
*
* @return Returns 0 to indicate successful termination.
*/

#define MAX_COMMAND_LENGTH 100  /* Defino la longitud máxima de un comando */

int main(void)
{
	char *prompt = "#cisfun$ "; /*Cadena que representa el indicador del comando*/

	/* Almacena el comando ingresado por el usuario */
	char command[MAX_COMMAND_LENGTH];

	while (1)  /* Bucle infinito */
	{
		printf("%s", prompt);  /* Imprime el indicador del comando */

			/* Lee el comando desde la entrada estándar */
		if (fgets(command, sizeof(command), stdin) == NULL)
		{	/* Si se alcanzó el final del archivo de entrada (Ctrl+D) */
			if (feof(stdin))
			{
				printf("\n");
				break; /* Condición de fin de archivo (Ctrl+D) */
			}
			else
			{
				/* Imprime un mensaje de error si la lectura falla */
				perror("Error de entrada");
				exit(EXIT_FAILURE);  /* Termina el programa con un código de error */
			}
		}

		/* Eliminar el salto de línea al final de la cadena ingresada */
		/* Busca y reemplaza el carácter de nueva línea */
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)  /* Compara el comando con "exit" */
		{
			break;  /* Sale del bucle si el comando es "exit" */
		}
	}

	return (0);  /* Termina el programa con éxito */
}
