/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:42:45 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/04 02:30:43 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

// Function to add a node at the end of the list
void add_node_last(t_list **head, t_list **new_node) {
    if (!new_node)
        return;

    if (*head == NULL) {
        *head = *new_node;  // If list is empty, the new node is the head
    } else {
        t_list *temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = *new_node;
    }
}

// Function to iterate through the list and print the values
void iter_list(t_list *node) {
    while (node != NULL) {
        printf("%d\n", node->content);
        node = node->next;
    }
}

// Function to free the list
void free_list(t_list **head) {
    t_list *temp;

    while (*head != NULL) {
        temp = (*head)->next;
        free(*head);  // Free the node
        *head = temp; // Move to the next node
    }
}


void print_list(t_list *head) {
    t_list *current = head;
    while (current != NULL) {
        printf("%d -> ", current->content);
        current = current->next;
    }
    printf("NULL\n");
}



int main() {
    // Creación de listas de prueba
    t_list *list_a = ft_lstnew(1);
    list_a->next = ft_lstnew(2);
    list_a->next->next = ft_lstnew(3);

    t_list *list_b = ft_lstnew(4);
    list_b->next = ft_lstnew(5);
    list_b->next->next = ft_lstnew(6);

    printf("Lista A inicial: ");
    print_list(list_a);
    printf("Lista B inicial: ");
    print_list(list_b);

    // Probar swp_a (intercambia los dos primeros de A)
    swp_a(&list_a);
    printf("\nDespués de swp_a (Lista A): ");
    print_list(list_a);

    // Probar swp_b (intercambia los dos primeros de B)
    swp_b(&list_b);
    printf("Después de swp_b (Lista B): ");
    print_list(list_b);

    // Probar swp_a_b (intercambia los dos primeros de A y B)
    swp_a_b(&list_a, &list_b);
    printf("\nDespués de swp_a_b (Lista A y Lista B):\n");
    printf("Lista A: ");
    print_list(list_a);
    printf("Lista B: ");
    print_list(list_b);

    // Probar push_a (mueve el primer nodo de B a A)
    push_a(&list_b, &list_a);
    printf("\nDespués de push_a (Lista A y Lista B):\n");
    printf("Lista A: ");
    print_list(list_a);
    printf("Lista B: ");
    print_list(list_b);

    // Probar push_b (mueve el primer nodo de A a B)
    push_b(&list_a, &list_b);
    printf("\nDespués de push_b (Lista A y Lista B):\n");
    printf("Lista A: ");
    print_list(list_a);
    printf("Lista B: ");
    print_list(list_b);

    // Probar rotate_a (rota la lista A)
    rotate_a(&list_a);
    printf("\nDespués de rotate_a (Lista A): ");
    print_list(list_a);

    // Probar rotate_b (rota la lista B)
    rotate_b(&list_b);
    printf("Después de rotate_b (Lista B): ");
    print_list(list_b);

    // Probar rotate_both (rota ambas listas)
    rotate_both(&list_a, &list_b);
    printf("\nDespués de rotate_both (Lista A y Lista B):\n");
    printf("Lista A: ");
    print_list(list_a);
    printf("Lista B: ");
    print_list(list_b);

    // Probar reverse_rotate_a (rotación inversa en A)
    reverse_rotate_a(&list_a);
    printf("\nDespués de reverse_rotate_a (Lista A): ");
    print_list(list_a);

    // Probar reverse_rotate_b (rotación inversa en B)
    reverse_rotate_b(&list_b);
    printf("Después de reverse_rotate_b (Lista B): ");
    print_list(list_b);

    // Probar reverse_rotate_both (rotación inversa en ambas listas)
    reverse_rotate_both(&list_a, &list_b);
    printf("\nDespués de reverse_rotate_both (Lista A y Lista B):\n");
    printf("Lista A: ");
    print_list(list_a);
    printf("Lista B: ");
    print_list(list_b);

    free_list(&list_a);
    free_list(&list_b);
    return 0;
}

