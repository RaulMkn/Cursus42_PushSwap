/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:42:45 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/06 21:46:09 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para imprimir la lista
void print_list(t_list *head)
{
	t_list *current = head;
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

void free_split(char **head)
{
	int i;

	i = 0;
	while (head[i] != NULL)
	{
		free(head[i]);
		i++;
	}
	free(head);
}

int is_valid_num(const char *str) {
    // Recorre cada carácter de la cadena
    while (*str) {
        // Si no es un dígito, devuelve 0 (falso)
        if (!ft_isdigit(*str)) {
            return 1; // No es un número válido
        }
        str++;
    }
    return 0; // Es un número válido
}

int main(int argc, char const *argv[])
{
	int i;
	t_list *list = NULL; // Inicializa la lista a NULL
	t_list *temp = NULL; // Puntero temporal para el último nodo
	char **new_argv;
	int j;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (argv[2] == NULL)
			{
				j = 0;
				new_argv = ft_split(argv[1], ' ');
				if (!new_argv)
					return (1); // Verificación de errores en ft_split
				while (new_argv[j] != NULL)
				{
					// Asignar memoria para cada contenido nuevo
					int *new_content = malloc(sizeof(int));
					if (!new_content)
					{
						return (0);
					}
					*new_content = ft_atoi(new_argv[j]);
					ft_printf("%d\n", *new_content);
					if (*new_content == 0)
					{
						int comparer = is_valid_num(new_argv[j]);
						if (comparer == 1)
						{
							ft_printf("Error\n");
							free(new_content); // Libera la memoria si falla la creación
							free_split(new_argv); // Libera la memoria de new_argv
							free_list(&list); // Libera la lista completa

							return (1);		   // Retorna un error
						}
					}

					t_list *new_node = ft_lstnew(new_content); // Crea un nuevo nodo
					if (!new_node)
					{
						ft_printf("Error\n");
						free(new_content); // Libera la memoria si falla la creación
						return (1);		   // Retorna un error
					}

					// Agregar el nuevo nodo a la lista
					if (list == NULL)
					{
						list = new_node; // Si la lista está vacía, establece el primer nodo
					}
					else
					{
						temp->next = new_node; // Enlaza el nuevo nodo al final
					}
					temp = new_node; // Actualiza el puntero temporal al nuevo nodo
					j++;
				}
				free_split(new_argv); // Libera la memoria de new_argv
				break;
			}

			// Asignar memoria para cada contenido nuevo
			int *new_content = malloc(sizeof(int));
			if (!new_content)
			{
				return (0);
			}
			*new_content = ft_atoi(argv[i]); // Convierte el argumento y almacena en el entero
			if (*new_content == 0)
			{
				int comparer = is_valid_num(argv[i]);
						if (comparer == 1)
						{
							ft_printf("Error\n");
							free(new_content); // Libera la memoria si falla la creación
							free_list(&list); // Libera la lista completa

							return (1);		   // Retorna un error
						}
			}

			t_list *new_node = ft_lstnew(new_content); // Crea un nuevo nodo
			if (!new_node)
			{
				ft_printf("Error\n");
				free(new_content); // Libera la memoria si falla la creación
				return (1);		   // Retorna un error
			}

			// Agregar el nuevo nodo a la lista
			if (list == NULL)
			{
				list = new_node; // Si la lista está vacía, establece el primer nodo
			}
			else
			{
				temp->next = new_node; // Enlaza el nuevo nodo al final
			}
			temp = new_node; // Actualiza el puntero temporal al nuevo nodo
			i++;
		}
		swp_a(&list);
		print_list(list);
	}
	else
	{
		printf("Error: No se proporcionaron argumentos.\n");
	}

	free_list(&list); // Libera la lista completa

	return 0;
}
