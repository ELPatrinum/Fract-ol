# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 13:10:17 by muel-bak          #+#    #+#              #
#    Updated: 2024/01/15 16:20:18 by muel-bak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f

NAME = fractol
BSNAME = fractol_bonus

SRCS = ./fractal/fractal_init.c ./fractal/mandelbrot.c ./fractal/julia.c ./fractal/clolors.c \
	   ./fractal/hook_function.c \
	   ./input/eroor.c ./input/ft_atoi.c ./input/string_functions.c \
	   ./bonus/burning_ship_bonus.c

MAIN = ./fractol_main.c 
BSMAIN = ./main_bonus.c

OBJS = $(SRCS:.c=.o) $(MAIN:.c=.o)
BSOBJS = $(SRCS:.c=.o) $(BSMAIN:.c=.o)

LIBMLX = ./MLX42
HEADERS = -I$(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -lm -L"/Users/$(USER)/goinfre/.brew/Cellar/glfw/3.3.9/lib/"


all: $(NAME)

bonus: $(BSNAME)

%.o: %.c ./fractol.h
	@$(CC) -c $(CFLAGS) $< -o $@ $(HEADERS)

$(BSNAME): $(BSOBJS)
	@$(CC) $(BSOBJS) $(LIBS) $(HEADERS) -o $(BSNAME)


$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@$(RM) $(OBJS) $(BSOBJS)

fclean: clean
	@$(RM) $(NAME) $(BSNAME)

re: fclean all

.PHONY: all, clean, fclean, re
