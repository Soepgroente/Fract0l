/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:21:38 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/30 11:04:01 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	leaks(void)
// {
// 	system("leaks -q fractol");
// }

static void	write_message(void)
{
	ft_putendl_fd("Please include the following parameters:\n", STDERR_FILENO);
	ft_putendl_fd("1: A size for the window between 100-1500)", STDERR_FILENO);
	ft_putendl_fd("2: The name of one of the following fractals:", 2);
	ft_putendl_fd("\n- Mandelbrot", STDERR_FILENO);
	ft_putendl_fd("- Julia (include x & y coordinates)", STDERR_FILENO);
	ft_putendl_fd("- Nova", STDERR_FILENO);
	ft_putendl_fd("- Multibrot (include an integer between 1 and 64)", 2);
	exit(EXIT_FAILURE);
}

static void	read_args(int argc, char **argv, int size)
{
	if (ft_strlen(argv[2]) > 10)
		write_message();
	if (ft_strncmp(ft_tolower_str(argv[2]), "mandel", 6) == 0 && argc == 3)
		ft_mandelbrot(size);
	else if (ft_strncmp(ft_tolower_str(argv[2]), "multibr", 7) \
		== 0 && argc == 4)
	{
		if (ft_atoi(argv[3]) < 1)
			write_message();
		ft_multibrot(size, ft_atoi(argv[3]));
	}
	if (ft_strlen(argv[2]) > 5)
		write_message();
	else if (ft_strncmp(ft_tolower_str(argv[2]), "julia", 5) == 0 && argc == 5)
		ft_julia(size, ft_ato_double(argv[3]), ft_ato_double(argv[4]));
	else if (ft_strncmp(ft_tolower_str(argv[2]), "julia", 5) == 0 && argc < 5)
	{
		ft_putendl_fd("Please include x & y coordinates", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (ft_strncmp(ft_tolower_str(argv[2]), "nova", 4) == 0 && argc == 3)
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
