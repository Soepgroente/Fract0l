/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:01:21 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/08 15:28:40 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	squid_math(t_complex z, t_complex c)
{
	t_complex	z1;
	t_complex	z2;
	t_complex	num;
	t_complex	tmp;

	z1 = z;
	z2 = z;
	num.x = -1;
	num.i = 0;
	z1 = c_add(z1, num);
	z1 = c_pow(z1, 3);
	z2 = c_multi(z2, z2);
	num.x = 3;
	z2 = c_multi(z2, num);
	tmp = c_div(z1, z2);
	z = c_add(z, tmp);
	z = c_add(z, c);
	return (z);
}

void	calc_squid(t_data *data, long double x, long double y)
{
	t_canvas	*cv;
	t_complex	c;
	t_complex	z;

	cv = &data->canvas;
	c.x = cv->width * ft_fraction(x, data->window.width) + cv->xmin;
	c.i = cv->height * ft_fraction(y, data->window.height) + cv->ymin;
	z.x = c.x;
	z.i = c.i;
	cv->iter = 1;
	while (z.x*z.x + z.i*z.i < 1000 && (cv->iter < data->canvas.max_iter))
	{
		z = squid_math(z, c);
		cv->iter++;
	}
	// exit(EXIT_SUCCESS);
	calc_color(data);
}

void	draw_squid(void *param)
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
			calc_squid(data, x, y);
			mlx_put_pixel(data->image, x, y, data->color.color);
			y++;
		}
		x++;
	}
}

void	ft_squid(int size)
{
	t_data	d;

	d.fractal = 3;
	ft_openwindow(&d, size);
	init_canvas(&d);
	draw_fractal(&d);
	mlx_scroll_hook(d.mlx, ft_scrollhook, &d);
	mlx_loop_hook(d.mlx, ft_keyhook, &d);
	mlx_loop(d.mlx);
	mlx_terminate(d.mlx);
	exit(EXIT_SUCCESS);
}
