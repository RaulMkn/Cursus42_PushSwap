/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:59:26 by rmakende          #+#    #+#             */
/*   Updated: 2024/11/10 14:14:02 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_sqrt(int nbr)
{
	int	i;

	if (nbr == 0)
		return (0);
	i = 1;
	while (i * i <= nbr)
		i++;
	return (i - 1);
}

static void	push_to_b(t_list **list_a, t_list **list_b, int *size_a,
		int *size_b)
{
	int	range;

	range = get_sqrt(*size_a) * 133 / 100;
	while (*size_a > 0)
	{
		if ((*list_a)->index <= *size_b)
		{
			push_b(list_a, list_b, 1);
			(*size_a)--;
			(*size_b)++;
		}
		else if ((*list_a)->index <= *size_b + range)
		{
			push_b(list_a, list_b, 1);
			(*size_a)--;
			(*size_b)++;
			if (!((*list_a)->index <= *size_b + range))
				rotate_both(list_a, list_b);
			else
				rotate_b(list_b, 1);
		}
		else
			rotate_a(list_a, 1);
	}
}

static void	push_to_a(t_list **list_a, t_list **list_b, int *size_a,
		int *size_b)
{
	while (*size_b > 0)
	{
		while ((*list_b)->index != *size_b - 1)
		{
			if (ft_lstpos(*list_b, *size_b - 1) <= *size_b / 2)
				rotate_b(list_b, 1);
			else
				reverse_rotate_b(list_b, 1);
		}
		push_a(list_a, list_b, 1);
		size_a++;
		size_b--;
	}
}

void	ksort(t_list **list_a, t_list **list_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*list_a);
	size_b = ft_lstsize(*list_b);
	if (size_a > 5)
	{
		push_to_b(list_a, list_b, &size_a, &size_b);
		push_to_a(list_a, list_b, &size_a, &size_b);
	}
	else
		simple_sort(list_a, list_b);
}
