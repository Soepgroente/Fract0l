# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:30:08 by vvan-der          #+#    #+#              #
#    Updated: 2023/06/02 16:38:17 by vvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Fractol
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wextra -Wall -Werror #-g -fsanitize=address
LIBFT	= libft
LIBMLX	= ./MLX42
HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= $(LIBMLX)/build/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

OBJDIR	= o_files
SRCS	= hooks.c init_structs.c main.c mandelbrot_set.c modify_picture.c utilities.c
OBJS	= $(SRC:%.c=$(OBJDIR)/%.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT)/$(LIBFT).a:
	$(MAKE) -C libft

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) $(LIBFT)/$(LIBFT).a:
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(OBJDIR)/%.o : %.c
	mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJDIR)
#	@rm -f $(LIBMLX)/build

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx