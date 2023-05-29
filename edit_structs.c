/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:01:47 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/29 20:06:32 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_canvas(t_global *global, int x, int y)
{
	t_canvas	*cv;
	t_window	*w;

	cv = &global->canvas;
	w = &global->window;
	cv->xmin += (long double) x / w->width * cv->zoomfactor;
	cv->xmax += (long double) x / w->width * cv->zoomfactor;
	cv->ymin += (long double) y / w->height * cv->zoomfactor;
	cv->ymax += (long double) y / w->height * cv->zoomfactor;
	draw_lines(global);
}

void	adjust_window(t_global *global, long double zoom)
{
	t_window	*w;
	t_canvas	*c;
	long double	old_x;
	long double	old_y;
	long double	new_x;
	long double	new_y;
	
	w = &global->window;
	c = &global->canvas;
	
	old_x = w->x / w->width * c->width + c->xmin;
	old_y = w->y / w->height * c->height + c->ymin;
	
	new_x = 0.5 * c->width + c->xmin;
	new_y = 0.5 * c->height + c->ymin;
	
	c->xmin *= zoom;
	c->xmax *= zoom;
	c->ymin *= zoom;
	c->ymax *= zoom;
	c->width = fabsl(c->xmin - c->xmax);
	c->height = fabsl(c->ymin - c->ymax);
	
	new_x -= old_x;
	new_y -= old_y;
	c->xmin -= new_x;
	c->xmax -= new_x;
	c->ymin -= new_y;
	c->ymax -= new_y;
	c->width = fabsl(c->xmin - c->xmax);
	c->height = fabsl(c->ymin - c->ymax);






	
	// offset_x = ((long double) w->x - w->width / 2);
	// offset_y = ((long double) w->y - w->height / 2);
	// c->xmin += offset_x / w->width * c->width;
	// c->xmax += offset_x / w->width * c->width;
	// c->ymin += offset_y / w->height * c->height;
	// c->ymax += offset_y / w->height * c->height;
	// c->width = fabsl(c->xmin - c->xmax);
	// c->height = fabsl(c->ymin - c->ymax);
	mlx_set_mouse_pos(global->mlx, w->width / 2, w->height / 2);
	printf("Xmin: %Lf, Xmax: %Lf, Width: %Lf\n", c->xmin, c->xmax, c->width);
	printf("Ymin: %Lf, Ymax: %Lf, Height: %Lf\n", c->ymin, c->ymax, c->height);
}

void	zoom_canvas(t_global *global, long double zoom)
{
	t_canvas	*cv;

	if (global->window.x != 0 || global->window.y != 0)
		adjust_window(global, zoom);
	cv = &global->canvas;
	cv->zoomfactor *= zoom;
	printf("Zoomfactor: %Lf\n", cv->zoomfactor);
	// cv->xmin *= zoom;
	// cv->xmax *= zoom;
	// cv->ymin *= zoom;
	// cv->ymax *= zoom;
	// cv->width = fabsl(cv->xmin - cv->xmax);
	// cv->height = fabsl(cv->ymin - cv->ymax);
	draw_lines(global);
}
