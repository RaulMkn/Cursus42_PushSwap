/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:06:37 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/19 21:46:10 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_b(t_list **head)
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
	ft_printf("rb\n");
}
