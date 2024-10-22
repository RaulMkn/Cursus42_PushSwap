/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:41:53 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/22 19:55:35 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void sort_three(t_list **list_a)
{
	int min;
	int	max;
	t_list  *temp;

	temp = *list_a;
	min = temp->index;
	max = temp->next->next->index;
	if (min == 2)
	{
		rotate_a(list_a);
		if (max == 0)
			swp_a(list_a);
	}
	else if (min == 1)
	{
		if (max == 0)
			reverse_rotate_a(list_a);
		else
			swp_a(list_a);
	}
	else if (min == 0)
	{
		reverse_rotate_a(list_a);
		swp_a(list_a);
	}
}

static void sort_four(t_list **list_a, t_list **list_b)
{
	int second, third, fourth;
	t_list *temp;

	temp = *list_a;
	second = temp->next->index;
	third = temp->next->next->index;
	fourth = temp->next->next->next->index;
	if (fourth == 3)
		reverse_rotate_a(list_a);  // El cuarto elemento es el más grande, lo llevamos al inicio
	else if (third == 3)
	{
		rotate_a(list_a);  // El tercer elemento es el más grande
		rotate_a(list_a);
	}
	else if (second == 3)
		rotate_a(list_a);  // El segundo elemento es el más grande
	temp = *list_a;	
	push_b(list_a, list_b);
	if (is_list_sorted(list_a) != 1)
		sort_three(list_a);    
	push_a(list_a, list_b);
	rotate_a(list_a);      
}

static void sort_five(t_list **list_a, t_list **list_b)
{
    int second, third, fourth, fifth;
    t_list *temp;

    temp = *list_a;
    second = temp->next->index;
    third = temp->next->next->index;
    fourth = temp->next->next->next->index;
    fifth = temp->next->next->next->next->index;

    if (fifth == 4)
        reverse_rotate_a(list_a);
    else if (fourth == 4)
    {
        reverse_rotate_a(list_a);
        reverse_rotate_a(list_a);
    }
    else if (third == 4)
    {
        rotate_a(list_a);
        rotate_a(list_a);
    }
    else if (second == 4)
        rotate_a(list_a);  
    push_b(list_a, list_b);
    sort_four(list_a, list_b);
    push_a(list_a, list_b);
	rotate_a(list_a);
}


void	simple_sort(t_list **list_a, t_list **list_b)
{
	int size_a;
	//int size_b;

	size_a = ft_lstsize(*list_a);
	if (size_a == 2)
		swp_a(list_a);
	else if (size_a == 3)
		sort_three(list_a);
	else if (size_a == 4)
		sort_four(list_a, list_b);
	else if (size_a == 5)
		sort_five(list_a, list_b);
}