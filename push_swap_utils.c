/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:20:27 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/09 16:42:01 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
	printf("NULL\n");
}

void	free_list(t_list **head)
{
	t_list	*temp;

	while (*head != NULL)
	{
		temp = (*head)->next;
		free((*head)->content);
		free(*head);
		*head = temp;
	}
}

void	*f_split(char **head, t_list **list, int n)
{
	int	i;

	i = 0;
	while (head[i] != NULL)
	{
		free(head[i]);
		i++;
	}
	if (n == 1)
		free_list(list);
	free(head);
	return (NULL);
}

t_list	*bubble_sort(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	else
	{
		while (lst->next != NULL)
			temp = temp->next;
	}
	return (NULL);
}

int	is_valid_num(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (1);
		}
		str++;
	}
	return (0);
}
