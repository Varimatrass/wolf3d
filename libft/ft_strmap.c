/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:41:38 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:41:39 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = ft_strdup(s);
	while (ret[i])
	{
		ret[i] = f(ret[i]);
		i++;
	}
	return (ret);
}
