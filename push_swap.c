/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:42:45 by rmakende          #+#    #+#             */
/*   Updated: 2024/11/07 23:41:38 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char ***token_temp)
{
	int		j;
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

int	*convertir_argumentos_a_numeros(const char *argv[], int argc, int *contador)
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
	return (nums);
}

t_list	*create_new_node(int *new_content, t_list **list, t_list **temp)
{
	t_list	*new_node;
	int		*new_content_copy;

	new_content_copy = malloc(sizeof(int));
	if (!new_content_copy)
		return (NULL); // O maneja el error según tu lógica
	*new_content_copy = *new_content;
	new_node = ft_lstnew(new_content_copy);
	if (!new_node)
	{
		free_list(list);
		return (NULL);
	}
	if (*list == NULL)
	{
		*list = new_node;
	}
	else
	{
		(*temp)->next = new_node;
	}
	*temp = new_node;
	return (new_node);
}

int	handle_new_content(const char *arg, int **new_content, t_list **list)
{
	int	comparer;
	int	i;
	int	contador;
	int	*numeros;

	comparer = 0;
	*new_content = malloc(sizeof(int));
	if (!(*new_content))
		return (0);
	**new_content = ft_atoi(arg, &comparer);
	if (comparer)
		return (free(*new_content), free_list(list), 0);
	if (**new_content == 0)
	{
		comparer = is_valid_num(arg);
		if (comparer == 1)
		{
			free(*new_content);
			free_list(list);
			return (0);
		}
	}
	return (1);
}
int	process_arguments(int argc, char const *argv[], t_list **list,
		t_list **temp)
{
	int i;
	int *numeros;
	int contador;
	
	i = 0;
	numeros = convertir_argumentos_a_numeros(argv, argc, &contador);
	while (i < contador)
	{
		*temp = create_new_node(&numeros[i], list, temp);
		i++;
	}
	free(numeros);
	set_index(list);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_list	*list;
	t_list	*temp;
	t_list	*aux;

	list = NULL;
	temp = NULL;
	aux = NULL;
	if (argc == 1)
		return (0);
	if (argc > 1)
	{
		if (process_arguments(argc, argv, &list, &temp) == 1)
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	else
		ft_putstr_fd("Error\n", 2);
	if (check_duplicates(list) == 1)
		return (ft_putstr_fd("Error\n", 2), ft_lstclear(&list, free), 1);
	if (is_list_sorted(&list) == 1)
		return (free_list(&list), 0);
	ksort(&list, &aux);
	return (free_list(&list), free_list(&aux), 0);
}
