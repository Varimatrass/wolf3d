/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:41:23 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:41:23 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	k;

	j = ft_strlen(dst);
	k = 0;
	if (size <= j)
		return (size + ft_strlen(src));
	while (src[k] != '\0' && j + k < size - 1)
	{
		dst[j + k] = src[k];
		k++;
	}
	dst[j + k] = '\0';
	if (size < ft_strlen(src))
		return (ft_strlen(src) + j);
	return (j + ft_strlen(src));
}
