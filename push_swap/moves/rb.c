/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:06:37 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/02 16:52:05 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void rotate_b(t_list **head) 
{
    t_list *first = *head;
    t_list *current = *head;

    *head = (*head)->next;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = first;
    first->next = NULL;
}