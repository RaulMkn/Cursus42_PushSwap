/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:54:54 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/06 19:48:24 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swp_a_b(t_list **head_a, t_list **head_b)
{
	t_list	*first;
	t_list	*second;
	void	*temp;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	first = *head_b;
	second = (*head_b)->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
	first = *head_a;
	second = (*head_a)->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
}
