/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:07:57 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/23 18:36:45 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_both(t_list **list_a, t_list **list_b)
{
	reverse_rotate_a(list_a, 0);
	reverse_rotate_b(list_b, 0);
	ft_printf("rrr\n");

}
