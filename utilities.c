/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:19:44 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/01 20:45:26 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_detail(t_global *global, int direction)
{
	if (direction == 1 && global->canvas.max_iter < 5000)
		global->canvas.max_iter *= 1.5;
	else if (direction == -1 && global->canvas.max_iter > 2)
		global->canvas.max_iter *= 1 / 1.5;
	printf("Max_iter: %d\n", global->canvas.max_iter);
	draw_lines(global);
}

void	initialise_data(t_global *global, int32_t size)
{
	init_color(&global->color);
	init_canvas(&global->canvas);
	init_window(&global->window, size);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
