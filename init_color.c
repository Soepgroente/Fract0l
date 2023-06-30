/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:27:37 by vincent           #+#    #+#             */
/*   Updated: 2023/06/29 17:46:45 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color(t_data *data)
{
	t_color	*c;
	int		i;

	i = 0;
	c = &data->color;
	while (i < 256)
	{
		c->sr[i] = (uint32_t)(127.5 * (1 + cos(2 * PI * i / 256 + 2 * PI / 3)));
		c->sg[i] = (uint32_t)(127.5 * (1 + cos(2 * PI * i / 256 + 4 * PI / 3)));
		c->sb[i] = 255 - (uint32_t)(127.5 * \
		(1 + cos(2 * PI * i / 256 + 2 * PI / 3)));
		c->spectrum[i] = ft_pixel(c->sr[i], c->sg[i], c->sb[i], 255);
		i++;
	}
}
