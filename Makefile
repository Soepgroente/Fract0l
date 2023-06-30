# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:30:08 by vvan-der          #+#    #+#              #
#    Updated: 2023/06/30 11:37:49 by vvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"

NAME	= Fractol
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wextra -Wall -Werror #-g3 -fsanitize=address
LIBFT	= libft
LIBMLX	= ./MLX42
HEADERS	= -I $(LIBMLX)/include/MLX42
LIBS	= $(LIBMLX)/build/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit # -pthread -Ofast -ldl
OBJDIR	= Fractobjs

SRCS	= complex_math.c fractol.c hooks.c init_canvas.c init_color.c init_window.c \
		julia_set.c mandelbrot_set.c modify_picture.c multibrot.c nova.c utilities.c

OBJS	= $(SRCS:%.c=$(OBJDIR)/%.o)


all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT)/$(LIBFT).a:
	$(MAKE) -C $(LIBFT)

$(OBJDIR)/%.o : %.c
	mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME): $(OBJS) $(LIBFT)/$(LIBFT).a
	$(CC) $(OBJS) $(LIBFT)/$(LIBFT).a $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJDIR)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/$(LIBFT).a

re: fclean all

.PHONY: all, clean, fclean, re, libmlx