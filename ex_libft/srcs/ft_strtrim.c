/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 23:14:30 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/29 21:57:53 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_start(char const *s)
{
	size_t	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_get_end(char const *s)
{
	size_t	i;

	i = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0') &&
			i > 0)
		i--;
	i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*copy;
	int		i;

	i = 0;
	start = ft_get_start(s);
	end = ft_get_end(s);
	if ((copy = (char *)malloc((end - start) * sizeof(char))) == NULL)
		return (NULL);
	while (start < end)
	{
		copy[i] = s[start];
		i++;
		start++;
	}
	copy[i] = '\0';
	return (copy);
}
