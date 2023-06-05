/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:45:33 by vvan-der          #+#    #+#             */
/*   Updated: 2023/06/04 16:16:26 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_string(const char *str, int *c)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
		*c *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
	{
		ft_putendl_fd("Atoi error: non-numerical input", 2);
		exit(EXIT_FAILURE);
	}

	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long	res;
	long	c;
	int		i;

	res = 0;
	c = 1;
	i = check_string(str, &c);
	while (i > 0)
	{
		i--;
		if (!ft_isdigit(str[i]))
			return ((int) res);
		res += (str[i] - 48) * c;
		if (res > INT_MAX || res < INT_MIN)
		{
			ft_putendl_fd("Atoi error: number too large", 2);
			exit(EXIT_FAILURE);
		}
		c *= 10;
	}
	return ((int) res);
}
