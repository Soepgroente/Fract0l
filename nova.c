/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:01:21 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/06 19:51:49 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	top_number(long double x, long double y)
{
	t_complex	top;
	
	top.x = ft_pow_fl(x, 3) - ft_pow_fl((3*x*y), 2);
	top.i = ft_pow_fl(3*x, 2) * y - ft_pow_fl(y, 3);
	return (top);
}

t_complex	bot_number(long double x, long double y)
{
	t_complex	bot;
	
	bot.x = 3*(x*x - y*y);
	bot.i = 6*x*y;
	return (bot);
}

t_complex	divide_number(t_complex *top, t_complex *bot)
{
	top.x =
	top.i = 
	bot.x = 
	bot.i = 
	return (z);
}

void	calc_nova(t_data *data, long double x, long double y)
{
	t_canvas	*cv;
	t_complex	c;
	t_complex	z;
	t_complex	value;

	c.x = cv->width * ft_fraction(x, data->window.width) + cv->xmin;
	c.i = cv->height * ft_fraction(y, data->window.height) + cv->ymin;
	while (c.x*c.x + c.i*c.i < 4 && (cv->iter < data->canvas.max_iter))
	{
		value.x = 
		value.i =
	}	
	calc_color(data);
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
	mlx_loop(d.mlx);
	mlx_terminate(d.mlx);
	exit(EXIT_SUCCESS);
}
