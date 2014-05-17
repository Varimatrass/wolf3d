/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:42:54 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:42:54 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s2);
	if (size == 0)
		return ((char *)s1);
	while (s1[i])
	{
		if (ft_strncmp((char *)&s1[i], s2, size) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
