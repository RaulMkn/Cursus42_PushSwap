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

int is_valid_num(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return 1;
		}
		str++;
	}
	return 0;
}

t_list *create_new_node(int *new_content, t_list **list, t_list **temp) 
{
    t_list *new_node;

    new_node = ft_lstnew(new_content); // Crea un nuevo nodo
    if (!new_node) {
        ft_printf("Error\n");
        free(new_content); // Libera el contenido en caso de error
        free_list(list);  // Asegúrate de liberar toda la lista hasta el momento
        return (NULL);     // Retorna NULL por error
    }
    if (*list == NULL) {
        *list = new_node; // Si la lista está vacía, establece el primer nodo
    } else {
        (*temp)->next = new_node; // Enlaza el nuevo nodo al final
    }
    *temp = new_node; // Actualiza el puntero temporal al nuevo nodo
    return (new_node);
}

t_list *string_push_swap(char const *argv[], t_list *list, t_list *temp)
{
	char **new_argv;
	int j;
	int comparer;
	int *new_content;

	j = 0;
	new_argv = ft_split(argv[1], ' ');
	if (!new_argv)
		return (NULL);
	while (new_argv[j] != NULL)
	{
		new_content = malloc(sizeof(int));
		if (!new_content)
			return (NULL);
		*new_content = ft_atoi(new_argv[j]);
		if (*new_content == 0)
		{
			comparer = is_valid_num(new_argv[j]);
			if (comparer == 1)
				return (ft_printf("Error\n"), free(new_content), free_split(new_argv), free_list(&list), NULL); // Retorna un error
		}
		temp = create_new_node(new_content, &list, &temp);
		j++;
	}
	return (free_split(new_argv), list);
}

int handle_new_content(const char *arg, int **new_content, t_list **list)
{
	int comparer;

	*new_content = malloc(sizeof(int));
	if (!(*new_content))
		return (0);
	**new_content = ft_atoi(arg);
	if (**new_content == 0)
	{
		comparer = is_valid_num(arg);
		if (comparer == 1)
		{
			ft_printf("Error\n");
			free(*new_content); // Libera la memoria si falla
			free_list(list);    // Libera la lista completa
			return (0);         // Retorna un error
		}
	}
	return (1); // Operación exitosa
}

int main(int argc, char const *argv[])
{
	int i;
	t_list *list = NULL; // Inicializa la lista a NULL
	t_list *temp = NULL; // Puntero temporal para el último nodo
	int *new_content;
	int result; // Variable para guardar el resultado de handle_new_content

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (argv[2] == NULL)
			{
				list = string_push_swap(argv, list, temp);
				if (!list)
					return (1);
				else
					break;
			}
			result = handle_new_content(argv[i], &new_content, &list);
			if (result == 0)
				return (1);
			temp = create_new_node(new_content, &list, &temp);
			i++;
		}
		print_list(list);
	}
	else
		printf("Error: No se proporcionaron argumentos.\n");
	return (free_list(&list), 0);
}
