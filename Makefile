# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 21:07:40 by rmakende          #+#    #+#              #
#    Updated: 2024/11/19 17:16:41 by rmakende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR = ./Libft
LIBRARY = $(LIBFT_DIR)/libft.a
LIB_HEADERS = $(LIBFT_DIR)/libft.h

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINT_HEADERS = $(PRINTF_DIR)/ft_printf.h

SRCS = push_swap.c \
       ./moves/sa.c\
	   ./moves/sb.c\
	   ./moves/ss.c\
	   ./moves/pb.c\
	   ./moves/pa.c\
	   ./moves/ra.c\
	   ./moves/rb.c\
	   ./moves/rr.c\
	   ./moves/rra.c\
	   ./moves/rrb.c\
	   ./moves/rrr.c\
	   ./utils/push_swap_utils.c\
	   ./utils/arguments_parser.c\
	   ./utils/set_list_indexes.c\
	   ./sorters/simple_sort.c\
	   ./sorters/ksort.c

OBJS = $(SRCS:.c=.o)
TARGET = push_swap

all: $(LIBRARY) $(PRINTF) $(TARGET)

$(LIBRARY):
	cd $(LIBFT_DIR) && $(MAKE)

$(PRINTF):
	cd $(PRINTF_DIR) && $(MAKE)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBRARY) $(PRINTF)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re test
