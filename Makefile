# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 19:11:54 by rmakende          #+#    #+#              #
#    Updated: 2024/10/17 18:37:06 by rmakende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# El compilador de C a usar
CC = gcc
# Las flags para el compillador
CFLAGS = -Wall -Wextra -Werror -g3

# Directorios y nombres de librerías
LIBFT_DIR = ./Libft
LIBRARY = $(LIBFT_DIR)/libft.a
LIB_HEADERS = $(LIBFT_DIR)/libft.h

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINT_HEADERS = $(PRINTF_DIR)/ft_printf.h

# Archivos del proyecto principal
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
	   push_swap_utils.c\
	   string_push_swap.c\
	   set_list_indexes.c\



OBJS = $(SRCS:.c=.o)
TARGET = push_swap

# Reglas
all: $(LIBRARY) $(PRINTF) $(TARGET)

# Compilar la librería Libft
$(LIBRARY):
	cd $(LIBFT_DIR) && $(MAKE)

# Compilar la librería Printf
$(PRINTF):
	cd $(PRINTF_DIR) && $(MAKE)

# Compilar el proyecto principal y enlazar con las librerías
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBRARY) $(PRINTF)

# Limpiar archivos objeto y las librerías
clean:
	rm -f $(OBJS)
	cd $(LIBFT_DIR) && $(MAKE) clean
	cd $(PRINTF_DIR) && $(MAKE) clean

# Limpiar todo, incluyendo el ejecutable y las librerías
fclean: clean
	rm -f $(TARGET)
	cd $(LIBFT_DIR) && $(MAKE) fclean
	cd $(PRINTF_DIR) && $(MAKE) fclean

# Recompilar desde cero
re: fclean all

test:
	@trash/algo.sh; trash/algo2.sh; diff trash/output.txt trash/output2.txt; echo "Done"

.PHONY: all clean fclean re test
