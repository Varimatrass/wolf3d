/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:31:27 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/22 21:06:07 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr(int n)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar('0' + n);
	return (i);
}

size_t	ft_putunbr(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putunbr(n / 10);
		i += ft_putunbr(n % 10);
	}
	else
		i += ft_putchar('0' + n);
	return (i);
}

size_t	ft_putlong(long l)
{
	size_t	i;

	i = 0;
	if (l < 0)
	{
		i += ft_putchar('-');
		l = -l;
	}
	if (l > 9)
	{
		i += ft_putlong(l / 10);
		i += ft_putlong(l % 10);
	}
	else
		i += ft_putchar('0' + l);
	return (i);
}
