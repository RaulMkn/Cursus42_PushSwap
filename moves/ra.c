/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:34:35 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/02 16:51:18 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void rotate_a(t_list **head) 
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
