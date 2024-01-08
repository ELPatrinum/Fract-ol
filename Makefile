# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 13:10:17 by muel-bak          #+#    #+#              #
#    Updated: 2024/01/07 16:16:13 by muel-bak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
RM = rm -f

NAME = fractol
SRCS = ./fractol_main.c \
	   ./fractal/fractal_init.c ./fractal/mandelbrot.c ./fractal/julia.c ./fractal/clolors.c \
	   ./input/eroor.c ./input/ft_atoi.c ./input/string_functions.c

OBJS = ${SRCS:.c=.o}

LIBMLX = ./MLX42
HEADERS = -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -lm -L"/Users/$(USER)/goinfre/homebrew/opt/glfw/lib/"


all: $(NAME) clean

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c ./src/fractol.h
	@$(CC) -c $(CFLAGS) $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
