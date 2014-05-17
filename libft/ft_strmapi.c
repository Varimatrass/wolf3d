/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:41:45 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:41:46 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	i = 0;
	ret = ft_strdup(s);
	while (ret[i])
	{
		ret[i] = f(i, ret[i]);
		i++;
	}
	return (ret);
}
