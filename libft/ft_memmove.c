/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:37:27 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:37:28 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*c;
	int				overlap;

	overlap = 0;
	c = (unsigned char *)s2;
	while (c < (unsigned char *)s2 + n)
	{
		if (c == (unsigned char*)s1)
			overlap = 1;
		c++;
	}
	if (overlap)
	{
		c = (unsigned char *)s2 + n - 1;
		while (c >= (unsigned char *)s2)
		{
			*(c + (s1 - s2)) = *c;
			c--;
		}
		return (s1);
	}
	return (ft_memcpy(s1, s2, n));
}
