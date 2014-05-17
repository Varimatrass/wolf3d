/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:34:19 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 10:55:00 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_cos(double radian)
{
	double	t;
	double	s;
	int		p;

	p = 0;
	s = 1.0;
	t = 1.0;
	while (ft_abs(t / s) > 0.00000001)
	{
		p++;
		t = (-t * radian * radian) / ((2 * p - 1) * (2 * p));
		s += t;
	}
	return (s);
}

double	ft_cos_d(double degree)
{
	double	t;
	double	s;
	int		p;

	degree = 3.14159265 * degree / 180.0;
	p = 0;
	s = 1.0;
	t = 1.0;
	while (ft_abs(t / s) > 0.00000001)
	{
		p++;
		t = (-t * degree * degree) / ((2 * p - 1) * (2 * p));
		s += t;
	}
	return (s);
}
