/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:46:33 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/27 18:34:55 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_list **head, int printable)
{
	t_list	*current;
	t_list	*last;
	t_list	*second_last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	current = *head;
	last = NULL;
	second_last = NULL;
	while (current->next->next != NULL)
		current = current->next;
	second_last = current;
	last = current->next;
	second_last->next = NULL;
	last->next = *head;
	*head = last;
	if (printable == 1)
		ft_printf("rra\n");
}
