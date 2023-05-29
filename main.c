/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:23:14 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/29 19:15:20 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	draw_lines(void *param)
{
	t_global	*global;
	t_color		*color;
	uint32_t	x;
	uint32_t	y;

	global = param;
	color = &global->color;
	x = 0;
	while (x < global->window.width)
	{
		y = 0;
		while (y < global->window.height)
		{
			calc_mandelbrot(global, x, y);
			color->color = ft_pixel(color->r, color->g, color->b, color->opac);
			mlx_put_pixel(global->image, x, y, color->color);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_global	g;
	int			x;
	int			y;

	x = 0;
	y = 0;
	initialise_data(&g, SIZE);
	g.mlx = mlx_init(g.window.width, g.window.height, "Mandelbrot", true);
	if (!g.mlx)
		ft_exit();
	g.image = mlx_new_image(g.mlx, g.window.width, g.window.height);
	if (!g.image)
		ft_exit();
	if (mlx_image_to_window(g.mlx, g.image, 0, 0) == -1)
	{
		mlx_close_window(g.mlx);
		ft_exit();
	}
	draw_lines(&g);
	mlx_set_mouse_pos(g.mlx, g.window.width / 2, g.window.height / 2);
	// mlx_get_mouse_pos(g.mlx, &x, &y);
	// mlx_loop_hook(g.mlx, ft_scrollhook, g);
	// printf("x: %d, y: %d\n");
	mlx_scroll_hook(g.mlx, ft_scrollhook, &g);
	mlx_loop_hook(g.mlx, ft_keyhook, &g);
	mlx_loop(g.mlx);
	mlx_terminate(g.mlx);
	return (EXIT_SUCCESS);
}
