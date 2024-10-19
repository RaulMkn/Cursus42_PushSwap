/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:18:30 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/19 22:56:55 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_list **list_a, t_list **list_b)
{
	t_list	*first_node;

	if (*list_a == NULL)
		return ;
	first_node = *list_a;
	*list_a = first_node->next;
	first_node->next = *list_b;
	*list_b = first_node;
	ft_printf("pb\n");
}
