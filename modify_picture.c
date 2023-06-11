/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:01:47 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/07 12:10:02 by vincent          ###   ########.fr       */
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

void	adjust_window(t_data *data, long double zoom)
{
	t_window	*w;
	t_canvas	*c;
	long double	mouse_dx;
	long double	mouse_dy;
	long double	new_x;
	long double	new_y;
	
	w = &data->window;
	c = &data->canvas;
	mouse_dx = (long double)w->x / w->width * c->width + c->xmin;
	mouse_dy = (long double)w->y / w->height * c->height + c->ymin;
	zoom_the_thing(data, zoom);
	new_x = (long double)w->x / w->width * c->width + c->xmin;
	new_y = (long double)w->y / w->height * c->height + c->ymin;
	c->xmin += mouse_dx - new_x;
	c->xmax += mouse_dx - new_x;
	c->ymin += mouse_dy - new_y;
	c->ymax += mouse_dy - new_y;
}

void	zoom_canvas(t_data *data, long double zoom)
{
	if (data->window.x != -1 || data->window.y != -1)
		adjust_window(data, zoom);
	else
		zoom_the_thing(data, zoom);
	draw_fractal(data);
}
