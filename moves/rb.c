/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:06:37 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/23 18:47:40 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_b(t_list **head, int printable)
{
	t_list	*first;
	t_list	*current;

	if (!head || !(*head) || !((*head)->next))
		return ;
	first = *head;
	current = *head;
	*head = (*head)->next;
	while (current->next != NULL)
		current = current->next;

	current->next = first;
	first->next = NULL;
	if (printable == 1)
		ft_printf("rb\n");
}

