/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:12:54 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/30 18:18:40 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mousehook(void *param)
{
	t_global	*global;

	global = param;
	if (mlx_is_mouse_down(global->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		mlx_get_mouse_pos(global->mlx, &global->window.x, &global->window.y);
	}
	
}

void	ft_keyhook(void *param)
{
	t_global	*global;
	mlx_t		*mlx;
	
	global = param;
	mlx = global->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		move_canvas(global, 0, global->window.height / -20, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		move_canvas(global, 0, global->window.height / 20, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		move_canvas(global, global->window.width / -20, 0, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		move_canvas(global, global->window.width / 20, 0, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT) && mlx_is_key_down(mlx, MLX_KEY_1))
		zoom_canvas(global, 1 / 1.1);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT) && mlx_is_key_down(mlx, MLX_KEY_2))
		zoom_canvas(global, 1.1);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL) && mlx_is_key_down(mlx, MLX_KEY_R))
	{
		init_canvas(&global->canvas);
		draw_lines(global);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL) && mlx_is_key_down(mlx, MLX_KEY_T))
		change_detail(global, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL) && mlx_is_key_down(mlx, MLX_KEY_Y))
		change_detail(global, -1);
}

void	ft_scrollhook(double dx, double dy, void *param)
{
	t_global	*global;
	t_window	*w;
	long double	zoom;

	global = param;
	w = &global->window;
	zoom = (long double) dy;
	if (zoom < 0)
		zoom = 1.1;
	else
		zoom = 1 / 1.1;
	mlx_get_mouse_pos(global->mlx, &w->x, &w->y);
	zoom_canvas(global, zoom);
}
