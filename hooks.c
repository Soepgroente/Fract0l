/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:12:54 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/08 19:23:12 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mousehook(void *param)
{
	t_data		*data;
	t_canvas	*cv;

	data = param;
	cv = &data->canvas;
	if (mlx_is_mouse_down(data->mlx, MLX_MOUSE_BUTTON_LEFT) && data->fractal == 1)
	{
		mlx_get_mouse_pos(data->mlx, &data->window.x, &data->window.y);
		cv->x = cv->width * ft_fraction(data->window.x, data->window.width) + cv->xmin;
		cv->y = cv->height * ft_fraction(data->window.y, data->window.height) + cv->ymin;
		draw_julia(data);
	}
}

void	ft_keyhook(void *param)
{
	t_data	*data;
	mlx_t	*mlx;
	
	data = param;
	mlx = data->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		move_canvas(data, 0, data->window.height / -20);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		move_canvas(data, 0, data->window.height / 20);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		move_canvas(data, data->window.width / -20, 0);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		move_canvas(data, data->window.width / 20, 0);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT) && mlx_is_key_down(mlx, MLX_KEY_1))
	{
		data->window.x = data->window.width / 2;
		data->window.y = data->window.height / 2;
		zoom_canvas(data, 1 / 1.1);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT) && mlx_is_key_down(mlx, MLX_KEY_2))
	{
		zoom_canvas(data, 1.1);
		data->window.x = data->window.width / 2;
		data->window.y = data->window.height / 2;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL) && mlx_is_key_down(mlx, MLX_KEY_R))
	{
		init_canvas(data);
		draw_fractal(data);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL) && mlx_is_key_down(mlx, MLX_KEY_T))
		change_detail(data, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL) && mlx_is_key_down(mlx, MLX_KEY_Y))
		change_detail(data, -1);
}

void	ft_scrollhook(double dx, double dy, void *param)
{
	t_data		*data;
	long double	zoom;

	data = param;
	if (dx != 0)
		dx = 0;
	zoom = (long double) dy;
	if (zoom < 0)
		zoom = 1.1;
	else
		zoom = 1 / 1.1;
	mlx_get_mouse_pos(data->mlx, &data->window.x, &data->window.y);
	zoom_canvas(data, zoom);
}
