/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:21:38 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/04 16:18:04 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	write_message(void)
{
	ft_putendl_fd("Please include the following parameters:", 1);
	ft_putendl_fd("1: A size for the window between 100-2000)", 1);
	ft_putendl_fd("2: The name of one of the following fractals:", 1);
	ft_putendl_fd("- Mandelbrot", 1);
	ft_putendl_fd("- Julia", 1);
	ft_putendl_fd("3: With Julia, please specify X and Y coordinates", 1);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		size;

	if (argc < 3)
		write_message();
	size = ft_atoi(argv[1]);
	if (size < 100)
		size = 100;
	if (size > 2000)
		size = 2000;	
	if (argc >= 3)
	{
		if (ft_strncmp(ft_tolower_str(argv[1]), "mandel", 6) == 0)
			draw_mandelbrot(size);
		else if (ft_strncmp(ft_tolower_str(argv[1]), "julia", 5) == 0 && argc < 5)
			ft_putendl_fd("Please include x & y coordinates", 1);
		else if (ft_strncmp(ft_tolower_str(argv[1]), "julia", 5) == 0 && argc >= 5)
			draw_julia(size, ft_ato_double(argv[3]), ft_ato_double(argv[4]));
		else
			write_message();
	}
}