/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:35:42 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/22 22:15:34 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "printf/ft_printf.h"

void	swp_a(t_list **head);
void	swp_b(t_list **head_b);
void	swp_a_b(t_list **head_a, t_list **head_b);
void	push_a(t_list **list_b, t_list **list_a);
void	push_b(t_list **list_a, t_list **list_b);
void	rotate_a(t_list **head);
void	rotate_b(t_list **head);
void	rotate_both(t_list **list_a, t_list **list_b);
void	reverse_rotate_a(t_list **head);
void	reverse_rotate_b(t_list **head);
void	reverse_rotate_both(t_list **list_a, t_list **list_b);
void	print_list(t_list *head);
void	free_list(t_list **head);
void	*f_split(char **head, t_list **list, int n);
int		is_valid_num(const char *str);
int		check_duplicates(t_list *lst);
t_list	*string_push_swap(char const *argv[], t_list *lst, t_list *temp);
t_list	*create_new_node(int *new_content, t_list **list, t_list **temp);
t_list  *set_index(t_list **list);
void bubble_sort(int *arr, int n);
void assign_indices(t_list *list, int *arr, int size);
int *list_to_sorted_array(t_list *list, int size);
int	is_list_sorted(t_list **lst);
void	simple_sort(t_list **list_a, t_list **list_b);
t_list	*create_new_node(int *new_content, t_list **list, t_list **temp);
void	ksort(t_list **list_a, t_list **list_b);





/*
t_list *string_push_swap(char const *argv[], t_list *lst, t_list **temp);
t_list	*populate_list(char **src, t_list *lst, t_list **temp);
int		*process_number(char *str, int *comparer);
*/

#endif