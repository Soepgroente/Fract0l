/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:04:45 by vincent           #+#    #+#             */
/*   Updated: 2023/06/05 18:34:02 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	canvas_mandel(t_data *data)
{
	data->canvas.xmin = -2;
	data->canvas.xmax = 0.47;
	data->canvas.ymin = -1.12;
	data->canvas.ymax = 1.12;
	data->canvas.width = fabsl(data->canvas.xmin - data->canvas.xmax);
	data->canvas.height = fabsl(data->canvas.ymin - data->canvas.ymax);
	data->canvas.iter = 0;
	data->canvas.max_iter = 50;
	data->canvas.zoomfactor = 1;
}

static void	canvas_julia(t_data *data)
{
	data->canvas.xmin = -2;
	data->canvas.xmax = 2;
	data->canvas.ymin = -1.5;
	data->canvas.ymax = 1.5;
	data->canvas.width = fabsl(data->canvas.xmin - data->canvas.xmax);
	data->canvas.height = fabsl(data->canvas.ymin - data->canvas.ymax);
	data->canvas.iter = 0;
	data->canvas.max_iter = 50;
	data->canvas.zoomfactor = 1;
}

void	init_canvas(t_data *data)
{
	if (data->fractal == 1)
		canvas_mandel(data);
	if (data->fractal == 2)
		canvas_julia(data);
}