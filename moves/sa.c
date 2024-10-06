/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:45:46 by rmakende          #+#    #+#             */
/*   Updated: 2024/09/25 18:29:17 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void swp_a(t_list **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    // Asignar punteros a los dos primeros nodos
    t_list *first = *head;
    t_list *second = (*head)->next;

    // Intercambiar los valores de los nodos
    void *temp = first->content;
    first->content = second->content;
    second->content = temp;
}

