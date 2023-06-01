/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:27:34 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/01 14:31:48 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

calc_julia(t_global *global, long double x, long double y)
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
	while (((x*x + y*y) < 4) && (cv->iter < global->canvas.max_iter))
	{
		result = x*x - y*y + dx;
		y = 2*x*y + dy;
		x = result;
		cv->iter++;
	}
	calc_color(global, x);
}