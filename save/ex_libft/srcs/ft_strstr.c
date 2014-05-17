/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 23:02:57 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/04/25 14:26:44 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef TEST_STR
# define TEST_STR
static char	ft_test_str(const char *s1, const char *s2, size_t i)
{
	size_t	j;

	j = 0;
	while (s2[j])
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
#endif
char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	char	bool;

	i = 0;
	bool = 0;
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i] == s2[0])
		{
			bool = ft_test_str(s1, s2, i);
			if (bool)
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
