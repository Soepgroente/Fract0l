/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:12:54 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/30 11:04:22 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Did a lot of bad stuff just to please norminette. */

void	ft_mousehook(void *param)
{
	t_data		*d;
	t_canvas	*cv;

	d = param;
	cv = &d->canvas;
	if (mlx_is_mouse_down(d->mlx, MLX_MOUSE_BUTTON_LEFT) && d->fractal == 1)
	{
		mlx_get_mouse_pos(d->mlx, &d->window.x, &d->window.y);
		cv->x = cv->width * d->window.x / d->window.width + cv->xmin;
		cv->y = cv->height * d->window.y / d->window.height + cv->ymin;
		draw_julia(d);
	}
	if (mlx_is_key_down(d->mlx, 340) && mlx_is_key_down(d->mlx, 50))
	{
		zoom_canvas(d, 1.1);
		d->window.x = d->window.width / 2;
		d->window.y = d->window.height / 2;
	}
	if (mlx_is_key_down(d->mlx, 341) && mlx_is_key_down(d->mlx, 82))
	{
		init_canvas(d);
		draw_fractal(d);
	}
}

void	ft_mh2(mouse_key_t btn, action_t act, modifier_key_t m, void *p)
{
	t_data		*data;
	t_canvas	*cv;

	(void)m;
	data = p;
	cv = &data->canvas;
	if (btn == 0 && act == MLX_RELEASE && data->fractal == 1)
	{
		draw_mandel(data);
	}
}

void	ft_keyhook(void *param)
{
	t_data	*d;
	mlx_t	*mlx;

	d = param;
	mlx = d->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		move_canvas(d, 0, d->window.height / -20);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		move_canvas(d, 0, d->window.height / 20);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		move_canvas(d, d->window.width / -20, 0);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		move_canvas(d, d->window.width / 20, 0);
	if (mlx_is_key_down(mlx, 340) && mlx_is_key_down(mlx, MLX_KEY_1))
	{
		d->window.x = d->window.width / 2;
		d->window.y = d->window.height / 2;
		zoom_canvas(d, 1 / 1.1);
	}
	if (mlx_is_key_down(d->mlx, 341) && mlx_is_key_down(d->mlx, MLX_KEY_T))
		change_detail(d, 1);
	if (mlx_is_key_down(d->mlx, 341) && mlx_is_key_down(d->mlx, MLX_KEY_Y))
		change_detail(d, -1);
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
