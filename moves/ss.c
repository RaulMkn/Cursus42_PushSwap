/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:54:54 by rmakende          #+#    #+#             */
/*   Updated: 2024/09/25 18:54:55 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void swp_a_b(t_list **head_a, t_list **head_b) {
    if (*head_b == NULL || (*head_b)->next == NULL) {
        return;
    }
	if (*head_a == NULL || (*head_a)->next == NULL) {
        return;
    }
    t_list *first = *head_b;
    t_list *second = (*head_b)->next;

    void *temp = first->content;
    first->content = second->content;
    second->content = temp;

	first = *head_a;
    second = (*head_a)->next;

    temp = first->content;
    first->content = second->content;
    second->content = temp;
}