/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:39:55 by vincent           #+#    #+#             */
/*   Updated: 2023/06/04 16:27:51 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_data *data, int32_t size)
{
	t_window	window;

	window = data->window;
	window.size = size;
	window.width = size * 200 / 150;
	window.height = size;
	window.x = -1;
	window.y = -1;
}

void	init_mandel(t_data *data, int32_t size)
{
	t_window	window;

	window = data->window;
	window.size = size;
	window.width = size * 247 / 224;
	window.height = size;
	window.x = -1;
	window.y = -1;
}

t_data	ft_openwindow(int size, int fractal)
{
	t_data	d;

	if (fractal == 1)
		init_mandel(&d, size);
	if (fractal == 2)
		init_julia(&d, size);
	d.mlx = mlx_init(d.window.width, d.window.height, "Fractal", true);
	if (!d.mlx)
		ft_exit();
	d.image = mlx_new_image(d.mlx, d.window.width, d.window.height);
	if (!d.image)
		ft_exit();
	if (mlx_image_to_window(d.mlx, d.image, 0, 0) == -1)
	{
		mlx_close_window(d.mlx);
		ft_exit();
	}
	return (d);
}