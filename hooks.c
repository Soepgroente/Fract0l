/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:12:54 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/04 14:22:24 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mousehook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_mouse_down(data->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		mlx_get_mouse_pos(data->mlx, &data->window.x, &data->window.y);
	}
}

void	ft_keyhook(void *param)
{
	t_data	*data;
	mlx_t		*mlx;
	
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
		zoom_canvas(data, 1 / 1.1);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT) && mlx_is_key_down(mlx, MLX_KEY_2))
		zoom_canvas(data, 1.1);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL) && mlx_is_key_down(mlx, MLX_KEY_R))
	{
		init_canvas(&data->canvas);
		draw_lines(data);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL) && mlx_is_key_down(mlx, MLX_KEY_T))
		change_detail(data, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL) && mlx_is_key_down(mlx, MLX_KEY_Y))
		change_detail(data, -1);
}

void	ft_scrollhook(double dx, double dy, void *param)
{
	t_data	*data;
	t_window	*w;
	long double	zoom;

	data = param;
	w = &data->window;
	if (dx != 0)
		dx = 0;
	zoom = (long double) dy;
	if (zoom < 0)
		zoom = 1.1;
	else
		zoom = 1 / 1.1;
	mlx_get_mouse_pos(data->mlx, &w->x, &w->y);
	zoom_canvas(data, zoom);
}
