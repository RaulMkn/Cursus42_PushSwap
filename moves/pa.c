/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:16:02 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/21 17:05:02 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_list **list_a, t_list **list_b)
{
	t_list	*first_node;

	if (*list_b == NULL)
		return ;
	first_node = *list_b;
	*list_b = first_node->next;
	first_node->next = *list_a;
	*list_a = first_node;
	ft_printf("pa\n");
}
