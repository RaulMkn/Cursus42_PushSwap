/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:33:32 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/16 00:03:49 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*


t_list *string_push_swap(char const *argv[], t_list *lst, t_list **temp)
{
    char **src;

    src = ft_split(argv[1], ' ');  // Divide la cadena en subcadenas
    if (!src)
        return (NULL);  // Si falla, retorna NULL

    lst = populate_list(src, lst, temp);  // Pasa la lista y el resultado de 'src'
    if (!lst)
        return (NULL);  // Si hubo error en populate_list, retorna NULL

    f_split(src, &lst, 0);  // Libera la memoria usada por 'src'
    return (lst);  // Retorna la lista final
}
t_list *populate_list(char **src, t_list *lst, t_list **temp) {
    int j = 0;
    int comparer = 0;
    int *ptr;

    while (src[j] != NULL) {  // Itera sobre los elementos de 'src'
        ptr = process_number(src[j], &comparer);  // Procesa y valida el número
        if (!ptr) {
            return f_split(src, &lst, 1);  // Si hay error, limpia y retorna NULL
        }
        temp = create_new_node(ptr, &lst, temp);  // Crea un nuevo nodo en la lista
        if (!temp) {
            return NULL;  // Manejo de error en caso de fallo al crear nodo
        }
        j++;
    }

    return lst;  // Retorna la lista actualizada
}

int *process_number(char *str, int *comparer) {
    int *ptr;

    ptr = malloc(sizeof(int));
    if (!ptr) {
        return NULL;  // Manejo de error si falla la asignación de memoria
    }

    *ptr = ft_atoi(str, comparer);  // Convierte la cadena a entero
    if (*comparer) {  // Si hubo un error en la conversión
        free(ptr);
        return NULL;
    }

    // Verifica si "0" es un número válido
    if (*ptr == 0 && is_valid_num(str) == 1) {
        free(ptr);
        return NULL;
    }

    return ptr;  // Retorna el puntero si todo es correcto
}
*/