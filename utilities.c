/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:19:44 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/06 16:00:51 by vvan-der         ###   ########.fr       */
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
}

void	change_detail(t_data *data, int direction)
{
	if (direction == 1 && data->canvas.max_iter < 5000)
		data->canvas.max_iter *= 1.2;
	else if (direction == -1 && data->canvas.max_iter > 5)
		data->canvas.max_iter *= 1 / 1.2;
	printf("Maxiter: %d\n", data->canvas.max_iter);
	draw_fractal(data);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	calc_color(t_data *data)
{
	t_color		*c;
	uint32_t	iter;

	iter = data->canvas.iter;
	c = &data->color;
	if (iter == data->canvas.max_iter)
	{
		c->r = 0x0;
		c->g = 0x0;
		c->b = 0x0;
		c->opac = 0xFF;
	}
	else
	{
		c->r = (255 * iter / 3) % 255;
		c->g = (255 * iter / 4) % 255;
		c->b = (255 * iter / 5) % 255;
		c->opac = 255;
	}
	c->color = ft_pixel(c->r, c->g, c->b, c->opac);
}