/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:36:49 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:36:50 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)s1 = *(unsigned char *)s2;
		if (*(unsigned char *)s2 == (unsigned char)c)
			return ((void *)((unsigned char *)s1 + 1));
		s1 = (unsigned char *)s1 + 1;
		s2 = (unsigned char *)s2 + 1;
		i++;
	}
	return (NULL);
}
