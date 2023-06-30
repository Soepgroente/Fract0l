/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:23:25 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/30 11:03:38 by vvan-der         ###   ########.fr       */
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
# define PI 3.14159265

# ifndef S_COMPLEX
#  define S_COMPLEX

typedef struct s_complex
{
	long double	x;
	long double	i;
}	t_complex;

# endif

# ifndef S_COLOR
#  define S_COLOR

typedef struct s_color
{
	uint8_t		r[16];
	uint8_t		g[16];
	uint8_t		b[16];
	uint8_t		x;
	uint8_t		y;
	uint8_t		z;
	uint8_t		opac;
	uint32_t	color;
	uint32_t	spectrum[256];
	uint32_t	sr[256];
	uint32_t	sg[256];
	uint32_t	sb[256];
}	t_color;

# endif

# ifndef S_CANVAS
#  define S_CANVAS

typedef struct s_canvas
{
	long double	xmin;
	long double	xmax;
	long double	ymin;
	long double	ymax;
	long double	width;
	long double	height;
	long double	x;
	long double	y;
	uint32_t	iter;
	uint32_t	max_iter;
}	t_canvas;

# endif

# ifndef S_WINDOW
#  define S_WINDOW

typedef struct s_window
{
	int32_t		size;
	int32_t		width;
	int32_t		height;
	int32_t		x;
	int32_t		y;
}	t_window;

# endif

# ifndef S_DATA
#  define S_DATA

typedef struct s_data
{
	uint8_t		fractal;
	uint8_t		power;
	t_color		color;
	t_canvas	canvas;
	t_window	window;
	mlx_image_t	*image;
	mlx_t		*mlx;
}	t_data;

# endif

/* Complex math functions */

t_complex	c_add(t_complex a, t_complex b);
t_complex	c_div(t_complex a, t_complex b);
t_complex	c_multi(t_complex a, t_complex b);
t_complex	c_pow(t_complex x, int power);
t_complex	c_sub(t_complex a, t_complex b);

/* Executional functions */

void		calc_color(t_data *data, long double velocity);
void		change_detail(t_data *data, int direction);
void		draw_fractal(t_data *data);
void		ft_exit(void);

/* Julia */

void		calc_julia(t_data *data);
void		draw_julia(void *param);
void		ft_julia(int size, long double x, long double y);

/* Mandelbrot */

void		calc_mandelbrot(t_data *data);
void		ft_mandelbrot(int size);
void		draw_mandel(void *param);

/* Multibrot */

void		calc_multibrot(t_data *data, uint8_t pow);
void		draw_multibrot(void *param);
void		ft_multibrot(int size, uint32_t power);

/* Nova */

void		ft_nova(int size);
void		draw_nova(void *param);

/* Hooks */

void		ft_keyhook(void *param);
void		ft_scrollhook(double dx, double dy, void *param);
void		ft_mousehook(void *param);
void		ft_mh2(mouse_key_t btn, action_t act, modifier_key_t m, void *p);

/* Initialise all the structs */

void		ft_openwindow(t_data *d, int fractal);
void		init_mandel(t_data *data, int32_t size);
void		init_julia(t_data *data, int32_t size);
void		init_canvas(t_data *data);
void		init_color(t_data *data);

/* Edit them structs */

void		move_canvas(t_data *data, long double x, long double y);
void		zoom_canvas(t_data *data, long double zoom);

/* Utilities */

uint32_t	ft_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

#endif
