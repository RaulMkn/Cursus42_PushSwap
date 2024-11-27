/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:35:42 by rmakende          #+#    #+#             */
/*   Updated: 2024/11/20 21:23:50 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "printf/ft_printf.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	swp_a(t_list **head, int printable);
void	swp_b(t_list **head_b, int printable);
void	swp_a_b(t_list **head_a, t_list **head_b);
void	push_a(t_list **list_b, t_list **list_a, int printable);
void	push_b(t_list **list_a, t_list **list_b, int printable);
void	rotate_a(t_list **head, int printable);
void	rotate_b(t_list **head, int printable);
void	rotate_both(t_list **list_a, t_list **list_b);
void	reverse_rotate_a(t_list **head, int printable);
void	reverse_rotate_b(t_list **head, int printable);
void	reverse_rotate_both(t_list **list_a, t_list **list_b);
int		is_valid_num(const char *str);
int		check_duplicates(t_list *lst);
t_list	*set_index(t_list **list);
void	bubble_sort(int *arr, int n);
void	assign_indices(t_list *list, int *arr, int size);
int		*list_to_sorted_array(t_list *list, int size);
int		is_list_sorted(t_list **lst);
void	simple_sort(t_list **list_a, t_list **list_b);
void	ksort(t_list **list_a, t_list **list_b);
int		*init_nums(int **contador, t_list **list);
int		parse_argument(const char *arg, int *nums, int *contador,
			t_list **list);
int		validate_and_store_num(const char *token, int *nums, int *contador,
			t_list **list);
int		parse_tokens(char **tokens, int *nums, int *contador, t_list **list);

#endif