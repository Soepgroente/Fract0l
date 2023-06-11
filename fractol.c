/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:21:38 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/08 19:19:22 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	write_message(void)
{
	ft_putendl_fd("Please include the following parameters:\n", STDOUT_FILENO);
	ft_putendl_fd("1: A size for the window between 100-1500)", 1);
	ft_putendl_fd("2: The name of one of the following fractals:", 1);
	ft_putendl_fd("- Mandelbrot", 1);
	ft_putendl_fd("- Julia (include x & y coordinates)", 1);
	ft_putendl_fd("- Squid", 1);
	exit(EXIT_FAILURE);
}

static void	read_args(int argc, char **argv, int size)
{
	if (ft_strncmp(ft_tolower_str(argv[2]), "mandel", 6) == 0)
		ft_mandelbrot(size);
	else if (ft_strncmp(ft_tolower_str(argv[2]), "julia", 5) == 0 && argc >= 5)
		ft_julia(size, ft_ato_double(argv[3]), ft_ato_double(argv[4]));
	else if (ft_strncmp(ft_tolower_str(argv[2]), "julia", 5) == 0 && argc < 5)
	{
		ft_putendl_fd("Please include x & y coordinates", 1);
		exit(EXIT_FAILURE);
	}
	else if (ft_strncmp(ft_tolower_str(argv[2]), "squid", 5) == 0)
		ft_squid(size);
	else if (ft_strncmp(ft_tolower_str(argv[2]), "nova", 4) == 0)
		ft_nova(size);
	else
		write_message();
}

int	main(int argc, char **argv)
{
	int		size;

	if (argc < 3)
		write_message();
	size = ft_atoi(argv[1]);
	if (size < 100)
		size = 100;
	if (size > 1500)
		size = 1500;
	read_args(argc, argv, size);
}