/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:19:44 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/29 17:56:50 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	draw_fractal(t_data *data)
{
	if (data->fractal == 1)
		draw_mandel(data);
	if (data->fractal == 2)
		draw_julia(data);
	if (data->fractal == 3)
		draw_nova(data);
	if (data->fractal == 4)
		draw_multibrot(data);
}

void	change_detail(t_data *data, int direction)
{
	if (direction == 1 && data->canvas.max_iter < 2500)
		data->canvas.max_iter *= 1.25;
	else if (direction == -1 && data->canvas.max_iter > 5)
		data->canvas.max_iter *= 1 / 1.25;
	printf("Maxiter: %d\n", data->canvas.max_iter);
	draw_fractal(data);
}

uint32_t	ft_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	calc_color(t_data *data, long double velocity)
{
	t_color		*c;
	uint32_t	i;
	long double	value;

	c = &data->color;
	if (data->canvas.iter == data->canvas.max_iter)
	{
		c->color = ft_pixel(0, 0, 0, 255);
		return ;
	}
	if (data->fractal == 3)
	{
		i = (data->canvas.iter + (uint32_t)velocity) % 255;
		c->color = c->spectrum[i];
		return ;
	}
	if (velocity > 1000)
		velocity = 1000;
	value = (uint32_t)(velocity) / 100;
	i = (data->canvas.iter + (uint32_t)value) % 255;
	c->color = c->spectrum[i];
}
