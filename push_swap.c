/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:42:45 by rmakende          #+#    #+#             */
/*   Updated: 2024/11/20 21:45:21 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*convert_to_int_array(const char *argv[], int argc, int *contador,
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
		if ((ft_strcmp((char *)argv[1], "") == 0)
			|| parse_argument(argv[i], nums, contador, list) == -1)
			return (free(nums), NULL);
		i++;
	}
	return (nums);
}

static int	create_new_node(int *new_content, t_list **list)
{
	t_list	*new_node;
	int		*new_content_copy;

	new_content_copy = malloc(sizeof(int));
	if (!new_content_copy)
		return (1);
	*new_content_copy = *new_content;
	new_node = ft_lstnew(new_content_copy);
	if (!new_node)
	{
		free(new_content_copy);
		ft_lstclear(list, free);
		return (1);
	}
	ft_lstadd_back(list, new_node);
	return (0);
}

static int	process_arguments(int argc, char const *argv[], t_list **list)
{
	int	i;
	int	*nums;
	int	contador;

	i = 0;
	nums = convert_to_int_array(argv, argc, &contador, list);
	if (nums == NULL)
		return (1);
	while (i < contador)
	{
		if (create_new_node(&nums[i], list) == 1)
			return (1);
		i++;
	}
	free(nums);
	set_index(list);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_list	*list;
	t_list	*aux;

	list = NULL;
	aux = NULL;
	if (argc == 1)
		return (0);
	if (argc > 1)
	{
		if (process_arguments(argc, argv, &list) == 1)
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	else
		ft_putstr_fd("Error\n", 2);
	if (check_duplicates(list) == 1)
		return (ft_putstr_fd("Error\n", 2), ft_lstclear(&list, free), 1);
	if (is_list_sorted(&list) == 1)
		return (ft_lstclear(&list, free), 0);
	ksort(&list, &aux);
	return (ft_lstclear(&list, free), ft_lstclear(&aux, free), 0);
}
