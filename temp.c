#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	convertir_argumentos_a_numeros(char *argv[], int argc, int numeros[],
		int *contador)
{
	char	**token;
	int *temp;

	int i = 1; // Comienza en 1 para omitir el nombre del programa.
	*contador = 0; // Inicia el contador en 0 para el array de números.
	while (i < argc)
	{
		if (strchr(argv[i], ' ') != NULL)
		{
			token = ft_split(argv[i], ' ');
			int j = 0; // Reinicia `j` para cada nuevo uso de ft_split
			while (token[j] != NULL)
			{
				numeros[*contador] = ft_atoi(token[j], temp);
				(*contador)++;
				j++;
			}
			j = 0;
			while (token[j] != NULL)
			{
				free(token[j]);
				j++;
			}
			free(token);
		}
		else
		{
			if (argv[i][0] == '\0')
				i++;
			numeros[*contador] = ft_atoi(argv[i], temp);
			(*contador)++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	contador;

	int numeros[argc * 2]; // Suponiendo que el array tendrá suficiente espacio
	// Convierte los argumentos a números
	convertir_argumentos_a_numeros(argv, argc, numeros, &contador);
	// Imprime los números separados por espacio
	for (int j = 0; j < contador; j++)
	{
		printf("%d ", numeros[j]);
	}
	printf("\n");
	return (0);
}
