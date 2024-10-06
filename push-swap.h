#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
#include "Libft/libft.h"
#include "printf/ft_printf.h"



void swp_a(t_list **head);
void swp_b(t_list **head_b);
void swp_a_b(t_list **head_a, t_list **head_b);
void push_a(t_list **list_b, t_list **list_a);
void push_b(t_list **list_a, t_list **list_b);
void rotate_a(t_list **head);
void rotate_b(t_list **head);
void rotate_both(t_list **list_a, t_list **list_b);
void reverse_rotate_a(t_list **head);
void reverse_rotate_b(t_list **head);
void reverse_rotate_both(t_list **list_a, t_list **list_b);

#endif