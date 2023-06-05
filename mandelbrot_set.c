/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:30:35 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/04 16:38:14 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_color(t_data *data, long double x)
{
	t_color		*c;
	uint32_t	iter;

	iter = data->canvas.iter;
	c = &data->color;
	if (iter == data->canvas.max_iter)
	{
		c->r = 0x0;
		c->g = 0x0;
		c->b = 0x0;
		c->opac = 0xFF;
	}
	else
	{
		// c->r = (255 * (int)x / 3) % 255;
		// c->g = (255 * (int)x / 4) % 255;
		// c->b = (255 * (int)x / 5) % 255;
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
	c->color = ft_pixel(c->r, c->g, c->b, c->opac);
}

void	calc_mandelbrot(t_data *data, long double x, long double y)
{
	t_canvas	*cv;
	long double	dx;
	long double	dy;
	long double	value;

	cv = &data->canvas;
	dx = cv->width * ft_fraction(x, data->window.width) + cv->xmin;
	dy = cv->height * ft_fraction(y, data->window.height) + cv->ymin;
	x = 0;
	y = 0;
	cv->iter = 0;
	while (((x*x + y*y) < 4) && (cv->iter < data->canvas.max_iter))
	{
		value = x*x - y*y + dx;
		y = 2*x*y + dy;
		x = value;
		cv->iter++;
	}
	calc_color(data, x);
}
