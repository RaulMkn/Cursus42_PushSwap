/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:20:27 by rmakende          #+#    #+#             */
/*   Updated: 2024/11/20 20:49:49 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_list_sorted(t_list **lst)
{
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return (1);
	temp = *lst;
	while (temp->next != NULL)
	{
		if (*(int *)(temp->content) > *(int *)(temp->next->content))
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	check_duplicates(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (*(int *)(tmp->content) == *(int *)(lst->content))
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	is_valid_num(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (1);
		}
		str++;
	}
	return (0);
}
