/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:01:47 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/29 15:28:56 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_the_thing(t_data *data, long double zoom)
{
	t_canvas	*c;

	c = &data->canvas;
	c->xmin *= zoom;
	c->xmax *= zoom;
	c->ymin *= zoom;
	c->ymax *= zoom;
	c->width = fabsl(c->xmin - c->xmax);
	c->height = fabsl(c->ymin - c->ymax);
}

void	move_canvas(t_data *data, long double x, long double y)
{
	t_canvas	*cv;
	t_window	*w;

	cv = &data->canvas;
	w = &data->window;
	cv->xmin += (long double) x / w->width * cv->width;
	cv->xmax += (long double) x / w->width * cv->width;
	cv->ymin += (long double) y / w->height * cv->height;
	cv->ymax += (long double) y / w->height * cv->height;
	draw_fractal(data);
}

static void	adjust_window(t_data *data, long double zoom)
{
	t_canvas	*c;
	double		m_dx;
	double		m_dy;
	double		new_x;
	double		new_y;

	c = &data->canvas;
	m_dx = (double)data->window.x / data->window.width * c->width + c->xmin;
	m_dy = (double)data->window.y / data->window.height * c->height + c->ymin;
	zoom_the_thing(data, zoom);
	new_x = (double)data->window.x / data->window.width * c->width + c->xmin;
	new_y = (double)data->window.y / data->window.height * c->height + c->ymin;
	c->xmin += m_dx - new_x;
	c->xmax += m_dx - new_x;
	c->ymin += m_dy - new_y;
	c->ymax += m_dy - new_y;
}

void	zoom_canvas(t_data *data, long double zoom)
{
	if (data->window.x != -1 || data->window.y != -1)
		adjust_window(data, zoom);
	else
		zoom_the_thing(data, zoom);
	draw_fractal(data);
}
