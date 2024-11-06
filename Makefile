# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 21:07:40 by rmakende          #+#    #+#              #
#    Updated: 2024/11/06 15:52:37 by rmakende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

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
	   ./utils/string_push_swap.c\
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
	cd $(LIBFT_DIR) && $(MAKE) clean
	cd $(PRINTF_DIR) && $(MAKE) clean

fclean: clean
	rm -f $(TARGET)
	cd $(LIBFT_DIR) && $(MAKE) fclean
	cd $(PRINTF_DIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re test
