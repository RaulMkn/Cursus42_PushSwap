/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:16:02 by rmakende          #+#    #+#             */
/*   Updated: 2024/09/27 18:21:42 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void push_a(t_list **list_b, t_list **list_a) {
    if (*list_b == NULL) {
        return;
    }
    t_list *first_node = *list_b;
    
    *list_b = first_node->next;

    first_node->next = *list_a;
    *list_a = first_node;
}