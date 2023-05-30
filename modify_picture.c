/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:01:47 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/30 18:19:49 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_the_thing(t_global *global, long double zoom)
{
	t_canvas	*c;

	c = &global->canvas;
	c->xmin *= zoom;
	c->xmax *= zoom;
	c->ymin *= zoom;
	c->ymax *= zoom;
	c->width = fabsl(c->xmin - c->xmax);
	c->height = fabsl(c->ymin - c->ymax);
}

void	move_canvas(t_global *global, long double x, long double y, long double zoom)
{
	t_canvas	*cv;
	t_window	*w;

	cv = &global->canvas;
	w = &global->window;
	cv->xmin += (long double) x / w->width * cv->width;
	cv->xmax += (long double) x / w->width * cv->width;
	cv->ymin += (long double) y / w->height * cv->height;
	cv->ymax += (long double) y / w->height * cv->height;
	draw_lines(global);
}

void	adjust_window(t_global *global, long double zoom)
{
	t_window	*w;
	t_canvas	*c;
	long double	mouse_dx;
	long double	mouse_dy;
	long double	new_x;
	long double	new_y;
	
	w = &global->window;
	c = &global->canvas;
	mouse_dx = (long double)w->x / w->width * c->width + c->xmin;
	mouse_dy = (long double)w->y / w->height * c->height + c->ymin;
	zoom_the_thing(global, zoom);
	new_x = (long double)w->x / w->width * c->width + c->xmin;
	new_y = (long double)w->y / w->height * c->height + c->ymin;
	c->xmin += mouse_dx - new_x;
	c->xmax += mouse_dx - new_x;
	c->ymin += mouse_dy - new_y;
	c->ymax += mouse_dy - new_y;
	c->width = fabsl(c->xmin - c->xmax);
	c->height = fabsl(c->ymin - c->ymax);
}

void	zoom_canvas(t_global *global, long double zoom)
{
	if (global->window.x != -1 || global->window.y != -1)
		adjust_window(global, zoom);
	else
		zoom_the_thing(global, zoom);
	global->canvas.zoomfactor *= zoom;
	printf("Zoomfactor: %Lf\n", global->canvas.zoomfactor);
	draw_lines(global);
}
