/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:41:53 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/19 22:10:28 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_three(t_list **list_a, t_list **list_b)
{
    int min;
    t_list  *temp;

    temp = *list_a;
    min = temp->index;
    if (min == 1)
    {
        swp_a(list_a);
        return ;
    }
    while (min != 0)
    {
        reverse_rotate_a(list_a);
        temp = *list_a;
        min = temp->index;
    }
    if (is_list_sorted(list_a) == 1)
        return ;
    push_b(list_a,list_b);
    temp = *list_a;
    if (temp->index > temp->next->index)    
        swp_a(list_a);
    push_a(list_a,list_b);
    
}

void	simple_sort(t_list **list_a, t_list **list_b)
{
    int size_a;
    //int size_b;

    size_a = ft_lstsize(*list_a);
    if (size_a == 2)
        swp_a(list_a);
    else if (size_a == 3)
        sort_three(list_a, list_b);
    //else if (size_a == 4)
    //    sort_four();
    //else if (size_a == 5)
    //    sort_five();
}