/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:54:50 by rmakende          #+#    #+#             */
/*   Updated: 2024/09/25 18:54:51 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void swp_b(t_list **head_b) {
    if (*head_b == NULL || (*head_b)->next == NULL) {
        return;
    }
    t_list *first = *head_b;
    t_list *second = (*head_b)->next;

    int temp = first->content;
    first->content = second->content;
    second->content = temp;
}