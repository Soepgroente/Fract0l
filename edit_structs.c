/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:01:47 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/27 20:21:31 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_canvas(t_global *global, int x, int y)
{
	t_canvas	*cv;
	t_window	*w;

	cv = global->canvas;
	w = global->window;
	cv->xmin += (long double) x / w->width;
	cv->xmax += (long double) x / w->width;
	cv->ymin += (long double) y / w->height;
	cv->ymax += (long double) y / w->height;
	draw_lines(global);
}

void	adjust_window(t_global *global)
{
	t_window	*w;
	t_canvas	*c;
	long double	offset_x;
	long double	offset_y;

	w = global->window;
	c = global->canvas;
	offset_x = ((long double) w->x - w->width / 2) / w->width;
	offset_y = ((long double) w->y - w->height / 2) / w->height;
	c->xmin += offset_x;
	c->xmax += offset_x;
	c->ymin += offset_y;
	c->ymax += offset_y;
	c->width = fabsl(c->xmin - c->xmax);
	c->height = fabsl(c->ymin - c->ymax);
	printf("offsetX: %Lf, offsetY: %Lf\n", offset_x, offset_y);
	printf("Xmin: %Lf, Xmax: %Lf, Width: %Lf\n", c->xmin, c->xmax, c->width);
	printf("Ymin: %Lf, Ymax: %Lf, Height: %Lf\n", c->ymin, c->ymax, c->height);
}

void	zoom_canvas(t_global *global, long double zoom)
{
	t_canvas	*cv;

	if (zoom > 0)
		zoom = 1 / zoom;
	else
		zoom = fabsl(zoom);
	cv = global->canvas;
	if (global->window->x != 0 || global->window->y != 0)
		adjust_window(global);
	cv->xmin *= zoom;
	cv->xmax *= zoom;
	cv->ymin *= zoom;
	cv->ymax *= zoom;
	cv->width = fabsl(cv->xmin - cv->xmax);
	cv->height = fabsl(cv->ymin - cv->ymax);
	draw_lines(global);
}
