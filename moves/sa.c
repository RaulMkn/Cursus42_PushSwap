/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:45:46 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/19 22:49:05 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swp_a(t_list **head)
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

	ft_printf("sa\n");
}

