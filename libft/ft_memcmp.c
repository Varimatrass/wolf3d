/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:37:04 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:37:05 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1)
	{
		i++;
	}
	if (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i] != 0)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
