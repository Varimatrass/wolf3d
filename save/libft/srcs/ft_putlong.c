/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 02:14:06 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/19 02:19:22 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		i += ft_putnbr(l / 10);
		i += ft_putnbr(l % 10);
	}
	else
		i += ft_putchar('0' + l);
	return (i);
}
