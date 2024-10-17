/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:40:50 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/17 19:31:01 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void *content; // Cambiado a void *
    int index;
    struct s_list *next;
} t_list;

// Crear un nuevo nodo de la lista
t_list *ft_lstnew(void *content) {
    t_list *new = malloc(sizeof(t_list));
    if (!new)
        return NULL;
    new->content = content; // Almacenar el puntero directamente
    new->index = -1; // Inicializamos con un índice no asignado
    new->next = NULL;
    return new;
}


// Función para añadir un nuevo nodo al final de la lista
void ft_lstadd_back(t_list **list, t_list *new) {
    t_list *temp;
    
    if (!*list) {
        *list = new;
        return;
    }
    temp = *list;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

// Función para calcular el tamaño de la lista
int ft_lstsize(t_list *list) {
    int size = 0;
    while (list) {
        size++;
        list = list->next;
    }
    return size;
}

void bubble_sort(int *arr, int n) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        int i = 0;
        while (i < n - 1) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
            i++;
        }
        n--;
    }
}

t_list *set_index(t_list **list)
{
    t_list *temp = *list;
    int *arr;
    int size = 0;
    int i = 0;

    // Obtener el tamaño de la lista
    size = ft_lstsize(*list);

    // Reservar memoria para el array
    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);

    // Llenar el array con los valores de la lista
    temp = *list;
    i = 0;
    while (temp) {
        arr[i++] = *(int *)(temp->content);
        temp = temp->next;
    }

    // Ordenar el array
    bubble_sort(arr, size);

    // Asignar los índices en la lista original
    i = 0;
    while (i < size) {
        temp = *list; // Reiniciar temp para recorrer la lista desde el principio
        while (temp) {
            if (arr[i] == *(int *)(temp->content)) {
                temp->index = i;
                break; // Salir del bucle interno una vez que se encuentra el elemento
            }
            temp = temp->next;
        }
        i++;
    }

    free(arr); // Liberar memoria del array
    return (*list); // Devolver el puntero al inicio de la lista
}
int main() {
    t_list *list = NULL;
    t_list *temp;

    // Crear 15 elementos desordenados y añadirlos a la lista
    int values[15] = {42, 15, 23, 8, 4, 16, 50, 29, 31, 10, 5, 2, 9, 3, 6};
    
// Cambiar la adición de elementos a la lista
for (int i = 0; i < 15; i++) {
    int *value = malloc(sizeof(int)); // Reservar memoria para un int
    *value = values[i]; // Asignar el valor
    ft_lstadd_back(&list, ft_lstnew(value)); // Pasar el puntero
}

    // Aplicar la función para asignar índices
    set_index(&list);

    // Mostrar el contenido y los índices
    temp = list;
    printf("Contenido\tÍndice\n");
    while (temp) {
        printf("%d\t\t%d\n", *(int *)(temp->content), temp->index);
        temp = temp->next;
    }

    // Liberar memoria
    while (list) {
        temp = list->next;
        free(list);
        list = temp;
    }

    return 0;
}
