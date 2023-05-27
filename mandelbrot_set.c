/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:30:35 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/27 15:26:40 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc_color(t_global *global)
{
	t_color	*c;

	c = global->color;
	if (global->canvas->iter == global->canvas->max_iter)
	{
		c->R = 0x0;
		c->G = 0x0;
		c->B = 0x0;
		c->opac = 0xFF;
	}
	else
	{
		c->R = 0x88;
		c->G = 0x0;
		c->B = 0x0;
		c->opac = 0xFF;
	}
}

void	calc_mandelbrot(t_global *global, long double x, long double y)
{
	t_canvas	*cv;
	long double	dx;
	long double	dy;
	long double	result;

	cv = global->canvas;
	dx = cv->width * (x / global->window->width) + cv->xmin;
	dy = cv->height * (y / global->window->height) + cv->ymin;
	x = 0;
	y = 0;
	cv->iter = 0;
	// if (fabsl(dx) <= 0.25 && fabsl(dy) <= 0.5)
		// cv->iter = cv->max_iter;
	while (((x*x + y*y) < 4) && (cv->iter < cv->max_iter))
	{
		result = x*x - y*y + dx;
		y = 2*x*y + dy;
		x = result;
		cv->iter++;
	}
	calc_color(global);
}
