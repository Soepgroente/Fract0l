/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:19:44 by vvan-der          #+#    #+#             */
/*   Updated: 2023/05/27 15:22:20 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* void	print_struct(t_global *global)
{
	
} */

t_global	*initialise_data(int32_t size)
{
	t_global	*global;
	
	global = malloc(sizeof(t_global));
	if (!global)
		ft_exit();
	global->color = init_color();
	global->canvas = init_canvas();
	global->window = init_window(size);
	global->zoom = 1;
	return (global);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
