/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:23:25 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/29 19:18:27 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_ITER 250
# define SIZE 200
# include "./MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_color
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	opac;
	uint32_t	color;
}	t_color;

typedef struct s_canvas
{
	long double	xmin;
	long double	xmax;
	long double	ymin;
	long double	ymax;
	long double	width;
	long double	height;
	long double	zoomfactor;
	uint32_t	iter;
}	t_canvas;

typedef struct s_window
{
	uint32_t	size;
	uint32_t	width;
	uint32_t	height;
	int			x;
	int			y;
}	t_window;

typedef struct s_global
{
	t_color		color;
	t_canvas	canvas;
	t_window	window;
	mlx_image_t	*image;
	mlx_t		*mlx;
}	t_global;

void		ft_exit(void);
void		calc_mandelbrot(t_global *global, long double x, long double y);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		draw_lines(void *param);

/* Hooks */

void		ft_keyhook(void *param);
void		ft_scrollhook(double dx, double dy, void *param);

/* Initialise all the structs */

void		initialise_data(t_global *global, int32_t size);
void		init_window(t_window *window, int32_t size);
void		init_canvas(t_canvas *canvas);
void		init_color(t_color *color);

/* Edit them structs */

void		move_canvas(t_global *global, int x, int y);
void		zoom_canvas(t_global *global, long double zoom);

#endif