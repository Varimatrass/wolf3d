/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 23:01:02 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/01 18:29:52 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!size && !dst && !src)
		return (0);
	while (dst[i] && i < size)
		i++;
	while (j + i + 1 < size && src[j])
	{
		if (j + i < size)
			dst[i + j] = src[j];
		j++;
	}
	if (j + i < size && !src[j])
		dst[i + j] = '\0';
	if (size < i)
		return (size + j);
	return (ft_strlen(src) + i);
}
