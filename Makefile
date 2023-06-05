# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:30:08 by vvan-der          #+#    #+#              #
#    Updated: 2023/06/04 15:14:45 by vincent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Fractol
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wextra -Wall -Werror #-g -fsanitize=address
LIBFT	= libft
LIBMLX	= ./MLX42
HEADERS	= -I $(LIBMLX)/include/MLX42
LIBS	= $(LIBMLX)/build/libmlx42.a -Ofast -ldl -lglfw -pthread -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" -framework Cocoa -framework OpenGL -framework IOKit
OBJDIR	= Fractobjs

SRCS	= hooks.c init_canvas.c init_window.c main.c mandelbrot_set.c modify_picture.c utilities.c
OBJS	= $(SRCS:.c=.o)
#OBJS	= $(SRCS:%.c=$(OBJDIR)/%.o)


all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT)/$(LIBFT).a:
	$(MAKE) -C $(LIBFT)

#$(OBJS): $(OBJDIR)
#	$(CC) $(SRCS) -c $(OBJDIR)/$(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) $(LIBFT)/$(LIBFT).a
	$(CC) $(OBJS) $(LIBFT)/$(LIBFT).a $(LIBS) -o $(NAME)

#$(OBJDIR):
#	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx