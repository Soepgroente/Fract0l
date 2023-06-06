# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:30:08 by vvan-der          #+#    #+#              #
#    Updated: 2023/06/06 17:34:42 by vvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"

NAME	= Fractol
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wextra -Wall -Werror #-g -fsanitize=address
LIBFT	= libft
LIBMLX	= ./MLX42
HEADERS	= -I $(LIBMLX)/include/MLX42
LIBS	= $(LIBMLX)/build/libmlx42.a -Ofast -ldl -lglfw3 -pthread -framework Cocoa -framework OpenGL -framework IOKit
OBJDIR	= Fractobjs

SRCS	= fractol.c hooks.c init_canvas.c init_window.c \
		julia_set.c mandelbrot_set.c modify_picture.c utilities.c
OBJS	= $(SRCS:%.c=$(OBJDIR)/%.o)


all: $(NAME) #libmlx 

#libmlx:
#	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

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