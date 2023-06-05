/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mandel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:23:14 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/04 16:35:03 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandel(void *param)
{
	t_data		*data;
	uint32_t	x;
	uint32_t	y;

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

	d = ft_openwindow(size, 1);
	draw_mandel(&d);
	mlx_scroll_hook(d.mlx, ft_scrollhook, &d);
	mlx_loop_hook(d.mlx, ft_keyhook, &d);
	mlx_loop(d.mlx);
	mlx_terminate(d.mlx);
	exit(EXIT_SUCCESS);
}
