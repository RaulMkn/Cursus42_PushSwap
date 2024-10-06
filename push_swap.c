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

// Función para imprimir la lista
void print_list(t_list *head)
{
    t_list *current = head;
    while (current != NULL)
    {
        printf("%d -> ", *(int *)current->content); // Hacer cast y desreferenciar
        current = current->next;
    }
    printf("NULL\n");
}

// Función para liberar la lista
void free_list(t_list **head)
{
    t_list *temp;
    while (*head != NULL)
    {
        temp = (*head)->next;
        //free((*head)->content); // Libera el contenido si se ha asignado memoria
        free(*head);            // Libera el nodo
        *head = temp;           // Mueve al siguiente nodo
    }
}

int main(int argc, char const *argv[])
{
    int i;
    t_list *list = NULL; // Inicializa list a NULL
    t_list *temp = NULL; // Puntero temporal para el último nodo
    char **new_argv;
    int j;

    if (argc > 1)
    {
        i = 1;
        while (i < argc)
        {
            int *new_content = malloc(sizeof(int));
            if (!new_content)
            {
                return (0);
            }
            if (argv[2] == NULL)
            {
                j = 0;
                new_argv = ft_split(argv[1], ' ');
                while (new_argv[j] != NULL)
                {
                    *new_content = ft_atoi(new_argv[j]);
                    t_list *new_node = ft_lstnew(new_content); // Crea un nuevo nodo
                    if (!new_node)
                    {
                        ft_printf("Error\n");
                        free(new_content); // Libera la memoria si falla la creación
                        return 1;          // Retorna un error
                    }
                    // Agregar el nuevo nodo a la lista
                    if (list == NULL)
                    {
                        list = new_node; // Si la lista está vacía, establece el primer nodo
                    }
                    else
                    {
                        temp->next = new_node; // Enlaza el nuevo nodo al final
                    }
                    temp = new_node; // Actualiza el puntero temporal al nuevo nodo
                    j++;
                }
                break;

            }

            *new_content = ft_atoi(argv[i]); // Convierte el argumento y almacena en el entero

            t_list *new_node = ft_lstnew(new_content); // Crea un nuevo nodo
            if (!new_node)
            {
                ft_printf("Error\n");
                free(new_content); // Libera la memoria si falla la creación
                return 1;          // Retorna un error
            }
            // Agregar el nuevo nodo a la lista
            if (list == NULL)
            {
                list = new_node; // Si la lista está vacía, establece el primer nodo
            }
            else
            {
                temp->next = new_node; // Enlaza el nuevo nodo al final
            }
            temp = new_node; // Actualiza el puntero temporal al nuevo nodo
            i++;
        }
        print_list(list);
    }
    else
    {
        printf("Error: No se proporcionaron argumentos.\n");
    }

    free_list(&list); // Libera la lista completa

    return 0;
}
