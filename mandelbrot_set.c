/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:30:35 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/30 11:04:56 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mandelbrot(t_data *data)
{
	t_canvas	*cv;
	t_complex	c;
	t_complex	z;

	cv = &data->canvas;
	c.x = cv->width * data->window.x / data->window.width + cv->xmin;
	c.i = cv->height * data->window.y / data->window.height + cv->ymin;
	z.x = 0;
	z.i = 0;
	cv->iter = 0;
	while ((z.x * z.x + z.i * z.i) < 4 && cv->iter < data->canvas.max_iter)
	{
		z = c_multi(z, z);
		z = c_add(z, c);
		cv->iter++;
	}
	calc_color(data, z.x * z.x + z.i * z.i - 4);
}

void	draw_mandel(void *param)
{
	t_data		*data;
	t_window	*w;

	data = param;
	w = &data->window;
	w->x = 0;
	while (w->x < data->window.width)
	{
		w->y = 0;
		while (w->y < data->window.height)
		{
			calc_mandelbrot(data);
			mlx_put_pixel(data->image, w->x, w->y, data->color.color);
			w->y++;
		}
		w->x++;
	}
}

void	ft_mandelbrot(int size)
{
	t_data	d;

	d.fractal = 1;
	ft_openwindow(&d, size);
	init_canvas(&d);
	init_color(&d);
	draw_fractal(&d);
	mlx_scroll_hook(d.mlx, ft_scrollhook, &d);
	mlx_loop_hook(d.mlx, ft_keyhook, &d);
	mlx_loop_hook(d.mlx, ft_mousehook, &d);
	mlx_mouse_hook(d.mlx, ft_mh2, &d);
	mlx_loop(d.mlx);
	mlx_terminate(d.mlx);
	exit(EXIT_SUCCESS);
}
