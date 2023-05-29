/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:06:35 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/29 19:26:56 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window(t_window *window, int32_t size)
{
	window->size = size;
	window->width = size * 247 / 100;
	window->height = size * 224 / 100;
	window->x = 0;
	window->y = 0;
}

void	init_canvas(t_canvas *canvas)
{
	canvas->xmin = -2;
	canvas->xmax = 0.47;
	canvas->ymin = -1.12;
	canvas->ymax = 1.12;
	canvas->width = fabsl(canvas->xmin - canvas->xmax);
	canvas->height = fabsl(canvas->ymin - canvas->ymax);
	canvas->iter = 0;
	canvas->zoomfactor = 1;
}

void	init_color(t_color *color)
{
	color->r = 0x0;
	color->g = 0x0;
	color->b = 0x0;
	color->opac = 0xFF;
}

/* void	print_struct(t_global *global)
{
	
} */