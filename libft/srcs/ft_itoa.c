/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 23:15:29 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/04/25 14:55:39 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

static char	*ft_putnbr_str(int n, char *s)
{
	if (n / 10 != 0)
		s = ft_putnbr_str((n / 10), s);
	else if (n < 0)
		*s++ = '-';
	*s++ = ft_abs(n % 10) + '0';
	*s = '\0';
	return (s);
}

char		*ft_itoa(int n)
{
	size_t	i;
	int		n_cpy;
	char	*s;

	i = 0;
	n_cpy = n;
	if (n_cpy < 0)
	{
		i++;
		n_cpy = -n_cpy;
	}
	while (n_cpy > 9)
	{
		n_cpy /= 10;
		i++;
	}
	s = ft_strnew(i);
	ft_putnbr_str(n, s);
	return (s);
}
