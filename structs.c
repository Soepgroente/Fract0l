/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:06:35 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/27 15:27:59 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window	*init_window(int32_t size)
{
	t_window	*window;

	window = malloc (sizeof(t_window));
	if (!window)
		ft_exit();
	window->size = size;
	window->width = size * 247 / 100;
	window->height = size * 224 / 100;
	return (window);
}

t_canvas	*init_canvas(void)
{
	t_canvas	*canvas;

	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
		ft_exit();
	canvas->xmin = -2;
	canvas->xmax = 0.47;
	canvas->ymin = -1.12;
	canvas->ymax = 1.12;
	canvas->width = fabsl(canvas->xmin) + fabsl(canvas->xmax);
	canvas->height = fabsl(canvas->ymin) + fabsl(canvas->ymax);
	canvas->iter = 0;
	canvas->max_iter = 100;
	return (canvas);
}

t_color	*init_color(void)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		ft_exit();
	color->R = 0x0;
	color->G = 0x0;
	color->B = 0x0;
	color->opac = 0xFF;
	return (color);
}

/* void	print_struct(t_global *global)
{
	
} */