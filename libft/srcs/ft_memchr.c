/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:58:04 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/11/30 16:46:32 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*byte;
	unsigned char	cc;

	byte = (unsigned char *)s;
	i = 0;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (byte[i] == cc)
			return (&byte[i]);
		i++;
	}
	return (NULL);
}
