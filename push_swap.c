/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:42:45 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/09 17:16:55 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(const char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_strncmp(argv[i], argv[j], 3) == 0)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_list	*create_new_node(int *new_content, t_list **list, t_list **temp)
{
	t_list	*new_node;

	new_node = ft_lstnew(new_content);
	if (!new_node)
	{
		ft_printf("Error\n");
		free(new_content);
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

t_list	*string_push_swap(char const *argv[], t_list *lst, t_list *temp)
{
	char	**src;
	int		j;
	int		comparer;
	int		*ptr;

	j = 0;
	src = ft_split(argv[1], ' ');
	if (!src)
		return (NULL);
	while (src[j] != NULL)
	{
		ptr = malloc(sizeof(int));
		if (!ptr)
			return (NULL);
		*ptr = ft_atoi(src[j]);
		if (*ptr == 0)
		{
			comparer = is_valid_num(src[j]);
			if (comparer == 1)
				return (ft_printf("Error\n"), free(ptr), f_split(src, &lst, 1));
		}
		temp = create_new_node(ptr, &lst, &temp);
		j++;
	}
	return (f_split(src, &lst, 0), lst);
}

int	handle_new_content(const char *arg, int **new_content, t_list **list)
{
	int	comparer;

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
			free(*new_content);
			free_list(list);
			return (0);
		}
	}
	return (1);
}

int	process_arguments(int argc, char const *argv[],
t_list **list, t_list **temp)
{
	int		i;
	int		*new_content;
	int		result;

	i = 1;
	while (i < argc)
	{
		if (argv[2] == NULL)
		{
			*list = string_push_swap(argv, *list, *temp);
			if (!*list)
				return (1);
			else
				break ;
		}
		result = handle_new_content(argv[i], &new_content, list);
		if (result == 0)
			return (1);
		*temp = create_new_node(new_content, list, temp);
		i++;
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_list	*list;
	t_list	*temp;

	list = NULL;
	temp = NULL;
	if (check_duplicates(argv) == 1)
		return (ft_printf("Error\n"), 1);
	if (argc > 1)
	{
		if (process_arguments(argc, argv, &list, &temp) == 1)
			return (1);
		print_list(list);
	}
	else
		printf("Error: No se proporcionaron argumentos.\n");
	return (free_list(&list), 0);
}
