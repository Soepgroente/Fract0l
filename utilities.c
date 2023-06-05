/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:19:44 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/04 15:12:48 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	change_detail(t_data *data, int direction)
{
	if (direction == 1 && data->canvas.max_iter < 5000)
		data->canvas.max_iter *= 1.5;
	else if (direction == -1 && data->canvas.max_iter > 2)
		data->canvas.max_iter *= 1 / 1.5;
	printf("Max_iter: %d\n", data->canvas.max_iter);
	draw_lines(data);
}

void	initialise_data(t_data *data, int fractal)
{
	init_color(data);
	init_canvas(data, fractal);
	init_window(data, fractal);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
