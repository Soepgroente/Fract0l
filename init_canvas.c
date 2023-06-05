/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:04:45 by vincent           #+#    #+#             */
/*   Updated: 2023/06/04 15:19:56 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	canvas_mandel(t_data *data)
{
	t_canvas	canvas;

	canvas = data->canvas;
	canvas.xmin = -2;
	canvas.xmax = 0.47;
	canvas.ymin = -1.12;
	canvas.ymax = 1.12;
	canvas.width = fabsl(canvas.xmin - canvas.xmax);
	canvas.height = fabsl(canvas.ymin - canvas.ymax);
	canvas.iter = 0;
	canvas.max_iter = 50;
	canvas.zoomfactor = 1;
}

static void	canvas_julia(t_data *data)
{
	t_canvas	canvas;

	canvas = data->canvas;
	canvas.xmin = -2;
	canvas.xmax = 2;
	canvas.ymin = -1.5;
	canvas.ymax = 1.5;
	canvas.width = fabsl(canvas.xmin - canvas.xmax);
	canvas.height = fabsl(canvas.ymin - canvas.ymax);
	canvas.iter = 0;
	canvas.max_iter = 50;
	canvas.zoomfactor = 1;
}

void	init_canvas(t_data *data, int fractal)
{
	if (fractal == 1)
		canvas_mandel(data);
	if (fractal == 2)
		canvas_julia(data);
}