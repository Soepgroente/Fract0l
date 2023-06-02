/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:27:34 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/02 16:47:39 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void	calc_julia(t_global *global, long double x, long double y)
{
	t_canvas	*cv;
	long double	dx;
	long double	dy;
	long double	result;

	cv = &global->canvas;
	dx = cv->width * (x / global->window.width) + cv->xmin;
	dy = cv->height * (y / global->window.height) + cv->ymin;
	while (dx*dx + dy*dy < 4 && cv->iter < cv->max_iter)
	{
		result = dx*dx - dy*dy;
		dy = 2*dx*dy + y;
		dx = result + x;
		cv->iter++;
	}
}