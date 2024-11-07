#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	free_split(char ***token_temp)
{
	int	j;
	char	**token;

	j = 0;
	token = *token_temp;
	while (token[j] != NULL)
	{
		free(token[j]);
		j++;
	}
	free(token);
}


int	*convertir_argumentos_a_numeros(char *argv[], int argc,
		int *contador)
{
	char	**token;
	int		*temp;
	int		j;
	int		i;
	int		*nums;

	temp = 0;
	i = 1;
	*contador = 0;
	nums = malloc(500 * (sizeof(int)));
	while (i < argc)
	{
		if (strchr(argv[i], ' ') != NULL)
		{
			token = ft_split(argv[i], ' ');
			j = 0;
			while (token[j] != NULL)
			{
				nums[*contador] = ft_atoi(token[j], temp);
				(*contador)++;
				j++;
			}
			free_split(&token);
		}
		else
		{
			if (argv[i][0] == '\0')
				i++;
			nums[*contador] = ft_atoi(argv[i], temp);
			(*contador)++;
		}
		i++;
	}
	return nums;
}

int	main(int argc, char *argv[])
{
	int	contador;

	int *numeros = convertir_argumentos_a_numeros(argv, argc, &contador);
	// Imprime los números separados por espacio
	for (int j = 0; j < contador; j++)
	{
		printf("%d ", numeros[j]);
	}
	printf("\n");
	free(numeros);
	return (0);
}
