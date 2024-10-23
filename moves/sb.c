/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:54:50 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/23 18:34:26 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swp_b(t_list **head, int printable)
{
	t_list *first;
	t_list *second;


	if (*head == NULL || (*head)->next == NULL)
		return;
	first = *head;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*head = second;
	if (printable == 1)
		ft_printf("sb\n");
}

