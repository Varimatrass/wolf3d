/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:43:08 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:43:09 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	beg;
	size_t	end;
	char	*ret;

	if (ft_strlen(s) == 0)
		return (ft_strnew(0));
	beg = 0;
	while (s[beg] && (s[beg] == ' ' || (s[beg] >= 9 && s[beg] <= 13)))
		beg++;
	end = ft_strlen(s) - 1;
	while (end && (s[end] == ' ' || (s[end] >= 9 && s[end] <= 13)))
		end--;
	end++;
	if (end > beg)
	{
		ret = ft_strnew(end - beg);
		ret = ft_strncpy(ret, (char *)&s[beg], end - beg);
		ret[end - beg + 1] = '\0';
		return (ret);
	}
	return (ft_strnew(0));
}
