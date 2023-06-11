/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:39:11 by vincent           #+#    #+#             */
/*   Updated: 2023/06/11 15:56:10 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	c_add(t_complex a, t_complex b)
{
	t_complex	z;

	z.x = a.x + b.x;
	z.i = a.i + b.i;
	return (z);
}

t_complex	c_sub(t_complex a, t_complex b)
{
	t_complex	z;

	z.x = a.x - b.x;
	z.i = a.i - b.i;
	return (z);
}

t_complex	c_multi(t_complex a, t_complex b)
{
	t_complex	z;

	z.x = (a.x * b.x) - (a.i * b.i);
	z.i = (a.x * b.i) + (a.i * b.x);
	return (z);
}

t_complex	c_pow(t_complex x, int power)
{
	t_complex	z;

	z = x;
	if (power == 0)
	{
		z.x = 1;
		z.i = 0;
		return (z);
	}
	while (power > 1)
	{
		z = c_multi(x, z);
		power--;
	}
	return (z);
}

t_complex	c_div(t_complex a, t_complex b)
{
	t_complex	conjugate;
	t_complex	z;

	conjugate.x = b.x;
	conjugate.i = b.i * -1; 
	a = c_multi(a, conjugate);
	b = c_multi(b, conjugate);
	z.x = a.x / b.x;
	z.i = a.i / b.x;
	return (z);
}
