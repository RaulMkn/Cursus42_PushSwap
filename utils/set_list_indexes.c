/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list_indexes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:40:50 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/27 18:31:13 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubble_sort(int *arr, int n)
{
	int	swapped;
	int	i;
	int	temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < n - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
		n--;
	}
}

int	*list_to_sorted_array(t_list *list, int size)
{
	int		*arr;
	int		i;
	t_list	*temp;

	i = 0;
	temp = list;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (temp)
	{
		arr[i++] = *(int *)(temp->content);
		temp = temp->next;
	}
	bubble_sort(arr, size);
	return (arr);
}

void	assign_indices(t_list *list, int *arr, int size)
{
	int		i;
	t_list	*temp;

	i = 0;
	while (i < size)
	{
		temp = list;
		while (temp)
		{
			if (arr[i] == *(int *)(temp->content))
			{
				temp->index = i;
				break ;
			}
			temp = temp->next;
		}
		i++;
	}
}

t_list	*set_index(t_list **list)
{
	int	size;
	int	*arr;

	size = ft_lstsize(*list);
	arr = list_to_sorted_array(*list, size);
	if (!arr)
		return (NULL);
	assign_indices(*list, arr, size);
	free(arr);
	return (*list);
}
