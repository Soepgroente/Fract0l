/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:01:47 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/27 15:17:00 by vvan-der         ###   ########.fr       */
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