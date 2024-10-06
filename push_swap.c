/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:42:45 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/06 20:07:25 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para imprimir la lista
void print_list(t_list **head)
{
	t_list *current = *head;
	while (current != NULL)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
	printf("NULL\n");
}

// Función para liberar la lista
void free_list(t_list **head)
{
	t_list *temp;
	while (*head != NULL)
	{
		temp = (*head)->next;
		free((*head)->content);
		free(*head);
		*head = temp;
	}
}
int main(int argc, char const *argv[])
{
	int i;
	t_list **list = malloc(sizeof(t_list *)); 
	*list = NULL;
	t_list *temp = NULL;
	int j;

	// Verifica si hay al menos un argumento
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			j = 0;

			// Verifica si el argumento es un número negativo válido o un número positivo
			if (argv[i][j] == '-')
			{
				j++; // Avanza al siguiente carácter para verificar si es un número
				if (argv[i][j] == '\0' || !ft_isdigit(argv[i][j]))
				{
					// Si no hay más caracteres o no es un dígito, no es un número válido
					printf("Error\n");
					if (*list != NULL)
					{
						free_list(list); // Libera la lista si ocurre un error
					}
					free(list); // Libera el puntero de la lista
					return 1;
				}
			}

			// Verifica el resto de los caracteres del argumento
			while (argv[i][j] != '\0')
			{
				if (!ft_isdigit(argv[i][j]))
				{
					printf("Error\n");
					if (*list != NULL)
					{
						free_list(list); // Libera la lista si ocurre un error
					}
					free(list); // Libera el puntero de la lista
					return 1;
				}
				j++;
			}

			// Convierte el argumento a número
			int *new_content = malloc(sizeof(int));
			if (!new_content)
			{
				printf("Error de memoria\n");
				free(list); // Libera el puntero de la lista
				return 1;
			}
			*new_content = ft_atoi(argv[i]); // Convierte el argumento actual a entero

			// Crea un nuevo nodo con el contenido convertido
			t_list *new_node = ft_lstnew(new_content);
			if (!new_node)
			{
				printf("Error\n");
				free(new_content); // Libera la memoria si falla la creación del nodo
				free(list);		   // Libera el puntero de la lista
				return 1;
			}

			// Agrega el nuevo nodo a la lista enlazada
			if (*list == NULL)
			{
				*list = new_node; // Si la lista está vacía, el primer nodo es el actual
			}
			else
			{
				temp->next = new_node; // Enlaza el nuevo nodo al final de la lista
			}
			temp = new_node; // Actualiza temp al último nodo creado
			i++;
		}

		// Imprime la lista después de procesar todos los argumentos
		print_list(list);
	}
	else
	{
		printf("Error: No se proporcionaron argumentos.\n");
	}

	free_list(list); // Libera la lista completa
	free(list);		 // Libera el puntero de la lista
	return 0;
}
