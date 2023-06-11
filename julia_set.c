/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:27:34 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/11 15:56:40 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void calc_julia(t_data *data)
{
	t_canvas *cv;
	t_complex c;
	t_complex z;

	cv = &data->canvas;
	c.x = cv->x;
	c.i = cv->y;
	z.x = cv->width * ft_fraction(data->window.x, data->window.width) + cv->xmin;
	z.i = cv->height * ft_fraction(data->window.y, data->window.height) + cv->ymin;
	cv->iter = 1;
	while ((z.x * z.x + z.i * z.i) < 4 && cv->iter < cv->max_iter)
	{
		z = c_multi(z, z);
		z = c_add(z, c);
		cv->iter++;
	}
	calc_color(data);
}

void draw_julia(void *param)
{
	t_data *data;
	t_window *w;

	data = param;
	w = &data->window;
	w->x = 0;
	while (w->x < data->window.width)
	{
		w->y = 0;
		while (w->y < data->window.height)
		{
			calc_julia(data);
			mlx_put_pixel(data->image, w->x, w->y, data->color.color);
			w->y++;
		}
		w->x++;
	}
}

void ft_julia(int size, long double x, long double y)
{
	t_data d;

	d.fractal = 2;
	ft_openwindow(&d, size);
	d.canvas.x = x;
	d.canvas.y = y;
	init_canvas(&d);
	draw_fractal(&d);
	mlx_scroll_hook(d.mlx, ft_scrollhook, &d);
	mlx_loop_hook(d.mlx, ft_keyhook, &d);
	mlx_loop_hook(d.mlx, ft_mousehook, &d);
	mlx_loop(d.mlx);
	mlx_terminate(d.mlx);
}
