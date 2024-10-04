/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:02:47 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/04 02:23:21 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int cont)
{
	t_list	*node; 

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = cont;
	node->next = NULL;
	return (node);
}
