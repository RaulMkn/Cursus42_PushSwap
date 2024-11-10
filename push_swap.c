/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:42:45 by rmakende          #+#    #+#             */
/*   Updated: 2024/11/10 14:54:59 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_to_int_array(const char *argv[], int argc, int *contador,
		t_list **list)
{
	int	i;
	int	*nums;

	i = 1;
	nums = init_nums(&contador, list);
	if (!nums)
		return (NULL);
	while (i < argc)
	{
		if (parse_argument(argv[i], nums, contador, list) == -1)
			return (NULL);
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
		return (NULL);
	*new_content_copy = *new_content;
	new_node = ft_lstnew(new_content_copy);
	if (!new_node)
	{
		free_list(list);
		return (NULL);
	}
	if (*list == NULL)
		*list = new_node;
	else
		(*temp)->next = new_node;
	*temp = new_node;
	return (new_node);
}

int	process_arguments(int argc, char const *argv[], t_list **list,
		t_list **temp)
{
	int	i;
	int	*numeros;
	int	contador;

	i = 0;
	numeros = convert_to_int_array(argv, argc, &contador, list);
	if (numeros == NULL)
		return (1);
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
