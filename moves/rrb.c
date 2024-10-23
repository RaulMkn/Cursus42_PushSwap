/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:46:33 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/23 18:33:51 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_b(t_list **head, int printable)
{
	t_list	*current;
	t_list	*last;
	t_list	*second_last;

	// Si la lista está vacía o tiene solo un nodo, no hay necesidad de rotar.
	if (*head == NULL || (*head)->next == NULL)
		return;

	current = *head;

	// Recorrer la lista hasta el penúltimo nodo.
	while (current->next->next != NULL)
		current = current->next;

	second_last = current;  // El penúltimo nodo.
	last = current->next;   // El último nodo.

	// Desconectar el último nodo y moverlo al frente.
	second_last->next = NULL;
	last->next = *head;
	*head = last;
	if (printable == 1)
		ft_printf("rrb\n");

}

