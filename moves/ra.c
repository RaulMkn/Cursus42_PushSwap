/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:34:35 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/23 18:32:34 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_list **head, int printable)
{
	t_list	*first;
	t_list	*current;

	first = *head;
	current = *head;
	*head = (*head)->next;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
	if (printable == 1)
		ft_printf("ra\n");
}
