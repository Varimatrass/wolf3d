/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:58:38 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/01 20:19:35 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*schar1;
	char	*schar2;

	schar1 = (char *)s1;
	schar2 = (char *)s2;
	i = 0;
	if (s1 && s2 && n)
	{
		while (i < n)
		{
			if (schar1[i] != schar2[i])
				return (schar1[i] - schar2[i]);
			else
				i++;
		}
	}
	return (0);
}
