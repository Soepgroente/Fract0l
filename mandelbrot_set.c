/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:30:35 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/29 18:48:45 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc_color(t_global *global, long double x)
{
	t_color	*c;
	int		iter;

	iter = global->canvas.iter;
	c = &global->color;
	if (iter == MAX_ITER)
	{
		c->r = 0x0;
		c->g = 0x0;
		c->b = 0x0;
		c->opac = 0xFF;
	}
	else
	{
		// c->r = (255 * x / 3) % 255;
		// c->g = (255 * x / 4) % 255;
		// c->b = (255 * x / 5) % 255;
		// c->opac = 255;
		c->r = (255 * iter / 3 + (int)(10 * x)) % 255;
		c->g = (255 * iter / 4 + (int)(10 * x)) % 255;
		c->b = (255 * iter / 5 + (int)(10 * x)) % 255;
		c->opac = 255;
		// c->r = (255 * iter / 23) % 255;
		// c->g = (255 * iter / 24) % 255;
		// c->b = (255 * iter / 25) % 255;
		// c->opac = 255;
	}
}

void	calc_mandelbrot(t_global *global, long double x, long double y)
{
	t_canvas	*cv;
	long double	dx;
	long double	dy;
	long double	result;

	cv = &global->canvas;
	dx = cv->width * (x / global->window.width) + cv->xmin;
	dy = cv->height * (y / global->window.height) + cv->ymin;
	x = 0;
	y = 0;
	cv->iter = 0;
	if (dx > -0.25 && dx <= 0.25 && fabsl(dy) <= 0.5)
		cv->iter = MAX_ITER;
	while (((x*x + y*y) < 4) && (cv->iter < MAX_ITER))
	{
		result = x*x - y*y + dx;
		y = 2*x*y + dy;
		x = result;
		cv->iter++;
	}
	calc_color(global, x);
}
