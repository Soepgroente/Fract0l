/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:52:12 by vincent           #+#    #+#             */
/*   Updated: 2023/06/04 13:24:04 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	atod_error(void)
{
	ft_putendl_fd("Error: invalid numerical input", 2);
	exit(EXIT_FAILURE);
}

static int	check_input(const char *str, int i)
{
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) || (i > 0 && str[i] == '.'))
	{
		i++;
		if (str[i] == '.')
		{
			if (ft_strlen(&str[i]) > 19)
				atod_error();
			i++;
			break ;
		}
	}
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		atod_error();
	return (i);
}

long double	ft_ato_double(const char *str)
{
	long double	res;
	long double	c;
	int			i;

	res = 0;
	c = 1;
	if (str[0] == '-')
		c *= -1;
	i = check_input(str, 0);
	while (i > 0)
	{
		i--;
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (res);
		if (str[i] == '.')
		{
			res /= (ft_pow(10, ft_strlen(&str[i]) - 1));
			c /= (ft_pow(10, ft_strlen(&str[i]) - 1));
		}
		else
		{	
			res += (str[i] - 48) * c;
			c *= 10.0;
		}
	}
	return (res);
}
