/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:23:25 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/04 16:30:31 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include <stdbool.h>

# ifndef S_COLOR
# define S_COLOR

typedef struct s_color
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	opac;
	uint32_t	color;
}	t_color;

#endif

# ifndef S_CANVAS
# define S_CANVAS

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
	uint32_t	max_iter;
}	t_canvas;

#endif

# ifndef S_WINDOW
# define S_WINDOW

typedef struct s_window
{
	int32_t		size;
	uint32_t	width;
	uint32_t	height;
	int32_t		x;
	int32_t		y;
}	t_window;

#endif

# ifndef S_data
# define S_data

typedef struct s_data
{
	t_color		color;
	t_canvas	canvas;
	t_window	window;
	mlx_image_t	*image;
	mlx_t		*mlx;
}	t_data;

#endif

void		ft_exit(void);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		change_detail(t_data *data, int direction);
void		calc_color(t_data *data, long double x);
char		*ft_tolower_str(char *str);

/* Mandelbrot */

void		calc_mandelbrot(t_data *data, long double x, long double y);
void		ft_mandelbrot(int size);
void		draw_mandel(void *param);

/* Hooks */

void		ft_keyhook(void *param);
void		ft_scrollhook(double dx, double dy, void *param);
void		ft_mousehook(void *param);

/* Initialise all the structs */

t_data		ft_openwindow(int size, int fractal);
void		initialise_data(t_data *data, int fractal);
void		init_mandel(t_data *data, int32_t size);
void		init_julia(t_data *data, int32_t size);
void		init_canvas(t_data *data, int fractal);

/* Edit them structs */

void		move_canvas(t_data *data, long double x, long double y);
void		zoom_canvas(t_data *data, long double zoom);

#endif
