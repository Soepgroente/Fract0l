/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window->c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:39:55 by vincent           #+#    #+#             */
/*   Updated: 2023/06/05 15:55:29 by vvan-der         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandel(t_data *data, int32_t size)
{
	data->window.size = size;
	data->window.width = size * 247 / 224;
	data->window.height = size;
	data->window.x = -1;
	data->window.y = -1;
}

void	init_julia(t_data *data, int32_t size)
{
	data->window.size = size;
	data->window.width = size * 200 / 150;
	data->window.height = size;
	data->window.x = -1;
	data->window.y = -1;
}

void	init_squid(t_data *data, int32_t size)
{
	data->window.size = size;
	data->window.width = size;
	data->window.height = size;
	data->window.x = -1;
	data->window.y = -1;
}

void	init_nova(t_data *data, int32_t size)
{
	data->window.size = size;
	data->window.width = size * 5 / 4;
	data->window.height = size;
	data->window.x = -1;
	data->window.y = -1;
}

void	ft_openwindow(t_data *d, int size)
{
	if (d->fractal == 1)
		init_mandel(d, size);
	if (d->fractal == 2)
		init_julia(d, size);
	if (d->fractal == 3)
		init_squid(d, size);
	if (d->fractal == 4)
		init_nova(d, size);
	d->mlx = mlx_init(d->window.width, d->window.height, "Fractal", false);
	if (!d->mlx)
		ft_exit();
	d->image = mlx_new_image(d->mlx, d->window.width, d->window.height);
	if (!d->image)
		ft_exit();
	if (mlx_image_to_window(d->mlx, d->image, 0, 0) == -1)
	{
		mlx_close_window(d->mlx);
		ft_exit();
	}
}
