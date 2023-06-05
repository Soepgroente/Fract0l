/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:27:34 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/04 16:31:20 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void	calc_julia(t_data *data, long double x, long double y)
{
	t_canvas	*cv;
	long double	dx;
	long double	dy;
	long double	result;

	/* Save x & y pixel coordinates in struct */

	cv = &data->canvas;
	dx = cv->width * (data->window.x / data->window.width) + cv->xmin;
	dy = cv->height * (data->window.y / data->window.height) + cv->ymin;
	while (dx*dx + dy*dy < 4 && cv->iter < cv->max_iter)
	{
		result = dx*dx - dy*dy;
		dy = 2*dx*dy + y;
		dx = result + x;
		cv->iter++;
	}
}

void	draw_julia(int size, long double x, long double y)
{
	t_data	d;

	d = ft_openwindow(size, 2);
	
}