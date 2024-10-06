/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:45:46 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/06 19:47:39 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swp_a(t_list **head)
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
}
