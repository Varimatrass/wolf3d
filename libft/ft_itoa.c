/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:35:30 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:35:30 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ctdigit(int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_tenpower(int j)
{
	int		ret;

	ret = 1;
	while (j--)
	{
		ret *= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	int		j;

	j = (n == 0) ? 1 : ft_ctdigit(n);
	p = (char *)malloc(j + 1);
	i = 0;
	if (n >= 0)
	{
		while (j != 0)
			p[i++] = '0' + ((n / ft_tenpower(--j)) % 10);
		p[i] = '\0';
		return (p);
	}
	else
	{
		i++;
		while (j != 0)
			p[i++] = '0' - ((n / ft_tenpower(--j)) % 10);
		p[0] = '-';
		p[i] = '\0';
	}
	return (p);
}
