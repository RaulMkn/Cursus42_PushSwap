/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:20:27 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/19 23:06:38 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *head)
{
	t_list	*current;
	t_list	*temp;

	current = head;
	temp = head;
	while (current != NULL)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
	printf("NULL\n");
	while (temp != NULL)
	{
		printf("%d -> ", temp->index);
		temp = temp->next;
	}
}

int	is_list_sorted(t_list **lst)
{
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return (1);
	temp = *lst;
	while (temp->next != NULL)
	{
		if (*(int *)(temp->content) > *(int *)(temp->next->content))
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
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

int	check_duplicates(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (*(int *)(tmp->content) == *(int *)(lst->content))
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
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
