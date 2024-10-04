/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:35:36 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/04 02:27:51 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int(*f)(int), void (*del)(int))
{
	t_list	*begin;
	t_list	*new;
	t_list	*temp;

	if (!lst)
		return (0);
	temp = lst;
	begin = NULL;
	while (temp)
	{
		new = ft_lstnew(temp->content);
		if (!new)
		{
			ft_lstclear(&begin, del);
			return (0);
		}
		new->content = f(new->content);
		ft_lstadd_back(&begin, new);
		temp = temp->next;
	}
	return (begin);
}
