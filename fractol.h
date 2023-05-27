/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:23:25 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/27 15:21:55 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#include "./MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>

typedef struct	s_color
{
	uint32_t	R;
	uint32_t	G;
	uint32_t	B;
	uint32_t	opac;
	uint32_t	color;
}	t_color;

typedef struct	s_canvas
{
	long double	xmin;
	long double	xmax;
	long double	ymin;
	long double	ymax;
	long double	width;
	long double	height;
	uint32_t	iter;
	uint32_t	max_iter;
}	t_canvas;

typedef struct	s_window
{
	uint32_t	size;
	uint32_t	width;
	uint32_t	height;
	uint32_t	x;
	uint32_t	y;
}	t_window;

typedef struct	s_global
{
	t_color		*color;
	t_canvas	*canvas;
	t_window	*window;
	mlx_image_t	*image;
	mlx_t		*mlx;
	long double	zoom;
}	t_global;

void		ft_exit(void);
void		calc_mandelbrot(t_global *global, long double x, long double y);
int32_t 	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		draw_lines(void *param);

/* Hooks */

void		ft_keyhook(void *param);
void		ft_scrollhook(void *param);

/* Initialise all the structs */

t_global	*initialise_data(int32_t size);
t_window	*init_window(int32_t size);
t_canvas	*init_canvas(void);
t_color		*init_color(void);

/* Edit them structs */

void		move_canvas(t_global *global, int x, int y);

#endif