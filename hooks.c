/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:12:54 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/27 20:14:43 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_keyhook(void *param)
{
	t_global	*global;
	mlx_t		*mlx;
	
	global = param;
	mlx = global->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		move_canvas(global, 0, -40);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		move_canvas(global, 0, 40);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		move_canvas(global, -40, 0);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		move_canvas(global, 40, 0);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT) && mlx_is_key_down(mlx, MLX_KEY_1))
		zoom_canvas(global, 1.05);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT) && mlx_is_key_down(mlx, MLX_KEY_2))
		zoom_canvas(global, (1 / 1.05));
}

void	ft_scrollhook(double dx, double dy, void *param)
{
	t_global	*global;
	t_window	*w;

	global = param;
	w = global->window;
	mlx_get_mouse_pos(global->mlx, &w->x, &w->y);
	if (dy != 0)
	{
		if (dy < 0)
		{
			dy = sqrt(fabsl(dy)) / 20;
			dy *= -1;
			dy -= -1;
		}
		else
		{
			dy = sqrt(dy) / 20;
			dy += 1;
		}
		zoom_canvas(global, (long double) dy);
	}
}