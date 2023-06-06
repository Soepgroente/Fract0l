/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:30:35 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/06 19:56:46 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mandelbrot(t_data *data, long double x, long double y)
{
	t_canvas	*cv;
	long double	dx;
	long double	dy;
	long double	value;

	cv = &data->canvas;
	dx = cv->width * ft_fraction(x, data->window.width) + cv->xmin;
	dy = cv->height * ft_fraction(y, data->window.height) + cv->ymin;
	x = 0;
	y = 0;
	cv->iter = 1;
	while (((x*x + y*y) < 4) && (cv->iter < data->canvas.max_iter))
	{
		value = x*x - y*y + dx;
		y = 2*x*y + dy;
		x = value;
		cv->iter++;
	}
	calc_color(data);
}

void	draw_mandel(void *param)
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
			calc_mandelbrot(data, x, y);
			mlx_put_pixel(data->image, x, y, data->color.color);
			y++;
		}
		x++;
	}
}

void	ft_mandelbrot(int size)
{
	t_data	d;

	d.fractal = 1;
	ft_openwindow(&d, size);
	init_canvas(&d);
	draw_fractal(&d);
	mlx_scroll_hook(d.mlx, ft_scrollhook, &d);
	mlx_loop_hook(d.mlx, ft_keyhook, &d);
	mlx_loop(d.mlx);
	mlx_terminate(d.mlx);
	exit(EXIT_SUCCESS);
}
