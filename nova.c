/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:48:42 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/30 11:05:51 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	black_hole(t_data *data, t_complex z, t_complex z_prev)
{
	t_complex	a;
	t_complex	b;
	t_complex	c;
	long double	tol;

	tol = 0.00001;
	a.x = 1;
	a.i = 0;
	b.x = -0.5;
	b.i = 0.86602540378;
	c.x = -0.5;
	c.i = -0.86602540378;
	if (fabsl(z.x - a.x) < tol && fabsl(z.i - a.i) < tol)
		return (calc_color(data, 0), true);
	else if (fabsl(z.x - b.x) < tol && fabsl(z.i - b.i) < tol)
		return (calc_color(data, 64), true);
	else if (fabsl(z.x - c.x) < tol && fabsl(z.i - c.i) < tol)
		return (calc_color(data, 128), true);
	else if (fabsl(z.x - z_prev.x) < tol && fabsl(z.i - z_prev.i) < tol)
		return (calc_color(data, 192), true);
	return (false);
}

static t_complex	nova_math(t_complex z, t_complex c)
{
	t_complex	z1;
	t_complex	z2;
	t_complex	num;
	t_complex	tmp;

	z1 = z;
	z2 = z;
	num.x = 1;
	num.i = 0;
	z1 = c_pow(z1, 3);
	z1 = c_sub(z1, num);
	z2 = c_multi(z2, z2);
	num.x = 3;
	z2 = c_multi(z2, num);
	tmp = c_div(z1, z2);
	z = c_sub(z, tmp);
	z = c_add(z, c);
	return (z);
}

void	calc_nova(t_data *data, long double x, long double y)
{
	t_canvas	*cv;
	t_complex	c;
	t_complex	z;
	t_complex	z_prev;

	cv = &data->canvas;
	c.x = cv->width * x / data->window.width + cv->xmin;
	c.i = cv->height * y / data->window.height + cv->ymin;
	z.x = 1;
	z.i = 0;
	cv->iter = 1;
	while (cv->iter < cv->max_iter)
	{
		z_prev.x = z.x;
		z_prev.i = z.i;
		z = nova_math(z, c);
		if (black_hole(data, z, z_prev) == true)
			break ;
		cv->iter++;
	}
	calc_color(data, 0);
}

void	draw_nova(void *param)
{
	t_data	*data;
	int32_t	x;
	int32_t	y;

	data = param;
	x = 0;
	while (x < data->window.width)
	{
		y = 0;
		while (y < data->window.height)
		{
			calc_nova(data, x, y);
			mlx_put_pixel(data->image, x, y, data->color.color);
			y++;
		}
		x++;
	}
}

void	ft_nova(int size)
{
	t_data	d;

	d.fractal = 3;
	ft_openwindow(&d, size);
	init_canvas(&d);
	draw_fractal(&d);
	mlx_scroll_hook(d.mlx, ft_scrollhook, &d);
	mlx_loop_hook(d.mlx, ft_keyhook, &d);
	mlx_loop_hook(d.mlx, ft_mousehook, &d);
	mlx_mouse_hook(d.mlx, ft_mh2, &d);
	mlx_loop(d.mlx);
	mlx_terminate(d.mlx);
	exit(EXIT_SUCCESS);
}
