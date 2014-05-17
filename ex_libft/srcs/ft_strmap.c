/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 23:10:34 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/01 18:09:10 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	str = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
