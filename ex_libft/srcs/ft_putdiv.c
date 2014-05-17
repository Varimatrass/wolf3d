/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdiv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 14:07:24 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/21 17:01:39 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putoct(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n > 7)
	{
		i += ft_putoct(n / 8);
		i += ft_putoct(n % 8);
	}
	else
		i += ft_putchar('0' + n);
	return (i);
}

size_t	ft_puthexa(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n > 15)
	{
		i += ft_puthexa(n / 16);
		i += ft_puthexa(n % 16);
	}
	else
	{
		if (n <= 9)
			i += ft_putchar('0' + n);
		else
			i += ft_putchar('a' + n - 10);
	}
	return (i);
}

size_t	ft_puthexa_maj(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n > 15)
	{
		i += ft_puthexa_maj(n / 16);
		i += ft_puthexa_maj(n % 16);
	}
	else
	{
		if (n <= 9)
			i += ft_putchar('0' + n);
		else
			i += ft_putchar('A' + n - 10);
	}
	return (i);
}

size_t	ft_putptr(unsigned long n)
{
	if (n == 0)
		return (ft_putstr(0x0));
	else
		return (ft_putstr("0xfff") + ft_puthexa(n));
}
