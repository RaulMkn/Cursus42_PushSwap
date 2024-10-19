/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:54:50 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/19 21:46:21 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swp_b(t_list **head)
{
	t_list	*first;
	t_list	*second;
	void	*temp;

	first = *head;
	second = (*head)->next;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
	ft_printf("sb\n");

}
