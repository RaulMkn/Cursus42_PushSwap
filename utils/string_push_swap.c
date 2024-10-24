/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:33:32 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/24 21:43:06 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
t_list	*string_push_swap(char const *argv[], t_list *lst, t_list *temp)
{
	char	**src;
	int		j;
	int		comparer;
	int		*ptr;
	
	j =	0;
	comparer = 0;
	src = ft_split(argv[1], ' ');
	if (!src)
		return (NULL);
	while (src[j] != NULL)
	{
		ptr = malloc(sizeof(int));
		if (!ptr)
			return (free(ptr), f_split(src, &lst, 1));
		*ptr = ft_atoi(src[j], &comparer);
		if (comparer)
			return (free(ptr), f_split(src, &lst, 1));
		if (*ptr == 0)
		{
			comparer = is_valid_num(src[j]);
			if (comparer == 1)
				return (free(ptr), f_split(src, &lst, 1));
		}
		temp = create_new_node(ptr, &lst, &temp);
		j++;
	}
	return (f_split(src, &lst, 0), lst);
}
*/

int *process_argument(char *src, int *comparer)
{
	int *ptr;

	ptr = malloc(sizeof(int));
	if (!ptr)
		return (0);
	*ptr = ft_atoi(src, comparer);
	if (*comparer || (*ptr == 0 && is_valid_num(src) == 1))
	{
		free(ptr);
		return (0);
	}
	return (ptr);
}

t_list *string_push_swap(char const *argv[], t_list *lst, t_list *temp)
{
	char    **src;
	int     j;
	int     comparer;
	int     *ptr;

	j = 0;
	comparer = 0;
	src = ft_split(argv[1], ' ');
	if (!src)
		return (NULL);
	while (src[j] != NULL)
	{
		ptr = process_argument(src[j], &comparer);
		if (!ptr)
			return (f_split(src, &lst, 1));
		temp = create_new_node(ptr, &lst, &temp);
		j++;
	}
	return (f_split(src, &lst, 0), lst);
}
